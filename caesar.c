//  caesar.c -- example for CS 2505 notes
//  Usage:  caesar <shift distance> <file name>
//
#include <stdio.h>     // for Std Library I/O fns
#include <errno.h>     // for global errno variable, set by strtol() function
#include <stdlib.h>    // for strtol() function
//#include <ctype.h>     // for isalpha() function
#include <stdint.h>    // for exact-width types
#include <inttypes.h>  // for I/O of exact-width types

// declarations of functions that are defined later in this file:
uint8_t checkParams(int nparams, char** params);
uint8_t checkShiftAmt(const char* const src);
int32_t setShiftAmt(const char* const src);
uint32_t processFile(int shiftAmt, const char* const fileName);
char applyShift(char Original, uint8_t shiftAmt);

// define some constants used as return values by checkParams():
#define WRONG_NUMBER_OF_PARAMS    1
#define INVALID_SHIFT_SPECIFIED   2
#define FILE_NOT_FOUND            3

// When main() is called, the shell puts the command-line parameters into
// the following structure:
//
//   argc == # of "tokens" on the command-line
//
//   argv[0] ---> char array holding name of executable file
//   argv[1] ---> char array holding 1st command-line argument
//   . . .
//   argv[argc-1] == NULL
//
// So, for this program, if it's invoked correctly from the command-line:
//
//   argv[0] ---> "caesar"
//   argv[1] ---> "<digits of integer specifying shift distance for cipher>"
//   argv[2] ---> "<name of file to be encrypted>"
//   argv[3] == NULL (0)
//
int main(int argc, char** argv) {
    
    // see if the command-line parameters are OK:
    uint8_t ckStatus;
    if ( ( ckStatus = checkParams(argc, argv) ) != 0 ) {
        return (int) ckStatus;
    }
    
    // convert the command-line parameter, which is a string,
    // to an integer:
    int32_t shiftAmt = setShiftAmt(argv[1]);
    printf("Shifting alphabetic input text by %"PRId32" positions.\n\n", shiftAmt);
    
    // apply the specified shift to all the alphabetic characters
    // in the input file:
    uint32_t charsShifted = processFile(shiftAmt, argv[2]);
    printf("\nShifted %"PRIu32" alphabetic characters.\n", charsShifted);
    
    return 0;
}

/**
 *  Reads the file "fileName" character-by-character, and shifts the
 *  alphabetic characters (a-z, A-Z) shiftAmt positions up; writes the
 *  characters to standard output.
 *
 *  Pre:     shiftAmt is initialized; if it is not in [0,25), it
 *              will be mapped into that range
 *           fileName is the name of the file to be processed,
 *              which should be in the current directory, unless
 *              fileName includes a path to the file
 *
 *  Post:    The file has not been modified.
 *
 *  Returns: The number of characters that were shifted.
 */
uint32_t processFile(int shiftAmt, const char* const fileName) {
    
    // make sure shiftAmt is in range [0, 25):
    shiftAmt = ((shiftAmt % 26) + 26) % 26;
    
    uint32_t nCharsShifted = 0;
    // open the input file; its existence was already verified in
    // the function that checked the command-line parameters:
    FILE *In = fopen(fileName, "r");
    
    char nextIn,    // character just read
    nextOut;   // character to be written next
    
    // fscanf() returns the number of variables to which values
    // were assigned; so this will stop the loop when we reach the
    // end of the file and fail to read anything:
    while ( fscanf(In, "%c", &nextIn) == 1 ) {
        
        // isalpha() returns true iff its parameter is alphabetic
        if ( isalpha(nextIn) ) {
            ++nCharsShifted;
            // applyShift() computes the shifted mapping of nextIn:
            nextOut = applyShift(nextIn, shiftAmt);
        }
        else
            nextOut = nextIn;
        
        printf("%c", nextOut);
    }
    
    // close the file when we're done with it:
    fclose(In);
    
    return nCharsShifted;
}

/**
 *   Takes a character Original, and computes and returns the
 *   character obtained by shifting Original by shiftAmt positions,
 *   according to the ASCII encoding.
 *
 *  Pre:     Original is in a-z or A-Z
 *           shiftAmt is in [0, 25)
 *
 *  Post:    Modified is in a-z or A-Z (circular shift, if necessary)
 *
 *  Returns: shifted analog of Original
 */
char applyShift(char Original, uint8_t shiftAmt) {
    
    char Modified = Original;
    
    //. . . implementation goes here . . .
    
    return Modified;
}

/**
 *   Validates the command-line parameters passed to main().
 *
 *  Pre:     nparams == argc from main()
 *           params  == argv from main()
 *
 *  Post:    The array of parameters has not been modified.
 *
 *  Returns: 0 if everythig was OK
 *           WRONG_NUMBER_OF_PARAMS if nparams != 3
 *           INVALID_SHIFT_SPECIFIED if the shift amount was not an integer
 *           FILE_NOT_FOUND if the specified input file cannot be opened
 *
 *  Calls:   checkShiftAmt(), fopen(), fclose()
 */
uint8_t checkParams(int nparams, char** params) {
    
    if ( nparams != 3 ) {
        printf("Invoke as: caesar <shift distance> <file name>\n");
        return WRONG_NUMBER_OF_PARAMS;
    }
    if ( !checkShiftAmt(params[1]) ) {
        return INVALID_SHIFT_SPECIFIED;
    }
    FILE* fp;
    if ( (fp = fopen(params[2], "r") ) == 0 ) {
        printf("The file %s could not be found.\n", params[2]);
        return FILE_NOT_FOUND;
    }
    if ( params[3] != NULL ) {
        printf("Well... that was unsatisfying...\n");
    }
    fclose(fp);
    return 0;
}

/**
 *  Determines if the string src specfies an integer.
 *
 *  Pre:     src points to a zero-terminated char array (C string)
 *
 *  Returns: 0 if something is wrong, > 0 otherwise
 *
 *  Calls:   strtol()
 */
uint8_t checkShiftAmt(const char* const src) {
    
    char *p;      // Look up the documentation for strtol() to
    // see what this is for...
    
    errno = 0;    // This is defined via errno.h; strtol() will
    // change it if an error is detected.
    
    int result = (int) strtol(src, &p, 10);
    
    return (errno == 0 && *p == 0 && p != src);
}

/**
 *  Converts the string src to an integer; has been previously
 *  validated by a call to checkShiftAmt().
 *
 *  Pre:     src points to a zero-terminated char array (C string)
 *
 *  Returns: integer corresponding to the string
 *
 * Calls:    strtol()
 */
int32_t setShiftAmt(const char* const src) {
    
    char *p;
    int  shiftAmt = strtol(src, &p, 10);
    return shiftAmt;
}