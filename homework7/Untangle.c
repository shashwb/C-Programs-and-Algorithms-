//
//  Untangle.c
//
//
//  Created by Seth Balodi on 11/13/14.
//  CS 2505 Fall 2014
//
//


/**************************************************************************
 * Untangle() parses a chain of records stored in the memory region pointed
 * to by pBuffer and writes a report to the supplied file stream. Formatting
 * details are provided in the specification for the assignment.
 *
 * Pre: pBuffer points to a region of memory formatted as specified.
 * Log points to an opened text file.
 *
 * Post: The target of pBuffer has been parsed and a report written as
 * specified.
 *
 **************************************************************************/


#include "Untangle.h"
#include <stdio.h>
#include <stdlib.h>



void Untangle(const uint8_t* pBuffer, FILE* Log) {
    
    
    
    //variable that holds length of the records
    uint8_t lengthOfRecord = 0;
    //this variable is used as the starting index of for loop that traverses the record values
    uint8_t indexOfStarting = 0;
    //this is the value of the offset which is used to move around the grid, as in the examples given
    uint16_t offset = (uint16_t)(pBuffer[0]);
    
    //opened the log, able to be appended
    Log = fopen("log.txt", "a+");
    //this checks to see if opening the file Log errors
    if (Log == NULL) {
        fputs("File error", stderr); exit(1);
    }
    
    //while the offset is not equal to a value of 0, the following code is executed
    while (offset != 0) {
        //the length of the record is instantiated here, with pointer arithmetic occuring and an eventual
        //dereferencing of the given by the pBuffer and the offset
        lengthOfRecord = *(pBuffer + offset);
        
        //this value is of type char and stores the first character in the word that is going to be output
        //into the Log file
        char charsInWordStarting = (char)(*(pBuffer + offset + 1));
        //here, the index of the starting value is initialized to be used in the loop
        indexOfStarting = *(pBuffer + offset + 1);

        //this for loop traverses the record and prints out the value of the variable charsInWordStarting into
        //the output Log file, as well as the amount of offset
        for (; indexOfStarting < lengthOfRecord; indexOfStarting++) {
            fprintf(Log, "%x:  %c", offset, charsInWordStarting);
        }
        
        //finally, the offset is incremented to the next offset of the next value
        offset = *((uint16_t*)(offset + pBuffer));
        
        
    }
    //finally, we close the Log file after we are done appending value to it
    fclose(Log);
    
    
    
}






