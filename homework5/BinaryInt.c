#include "BinaryInt.h"
#include <inttypes.h>

// Internal representation stores bits so that coefficient of 2^i is at index i.

/**
 *   Initializes BinInt[] so that the elements correspond to the 2's complement
 *   representation of the 32-bit integer Src.
 *
 *   Pre:   BinInt[] is of dimension 32
 *   Post:  For i = 0 to 31, BinInt[i] == 2^i bit of Src
 */
void BI_Create(uint8_t BinInt[], int32_t Src) {
    
    int32_t Mask = 0x01;
    for (int pos = 0; pos < NUM_BITS; pos++) {
        BinInt[pos] = ( Src & Mask) ? 1 : 0;
        Mask = Mask << 1;
    }
}

/**
 *   Computes sum of 2's complement representations of integer values.
 *
 *   Pre:   Sum[], Left[] and Right[] are of dimension 32
 *          Left[] and Right[] store 2's complement representations
 *   Post:  Sum[] == Left[] + Right[], if possible
 *   Ret:   false if overflow occurs when computing sum of Left[] and Right[];
 *          true otherwise
 */
bool BI_Add(uint8_t Sum[], const uint8_t Left[], const uint8_t Right[]) {
    
    
    //before we even begin, I can see the parameters that are passed into this function that we have to
    //work with. There are 3 arrays, the sum, the left, and the right.
    
    //we need to think about what kind of variables we need for this program.
    //because we are doing addition and subtraction of these specialized values, we need
    //a total (sum) and we need the amount that is carried.
    int total = 0;
    int carry = 0;
    
    //what we have to do is go through this entire array, which has 32 characters
    //we are going to loop through it and do not need to compare any of the values to anything
    for (int i = 0; i < 32; i++)
    {
        
        //we are given this in the post condition
        //the total value is the current value of i on both arrays plus any type of carry that is added to it.
        total = Left[i] + Right[i] + carry;
        
        //if the total ends up being 0, then the carry is 0 and the sum at that point will be 0
        if(total == 0)
        {
            Sum[i] = 0;
            carry = 0;
        }
        else if(total == 1)
        {
            Sum[i] = 1;
            carry = 0;
        }
        else if(total == 2)
        {
            Sum[i] = 0;
            carry = 1;
        }
        else if(total == 3)
        {
            Sum[i] = 1;
            carry = 1;
        }
    }

    if ((Left[31] == Right[31]) && (Left[31] != Sum[31]))
    {
        return false;
    }
    return true;
}
/**
 *   Computes difference of 2's complement representations of integer values.
 *
 *   Pre:   Diff[], Left[] and Right[] are of dimension 32
 *          Left[] and Right[] store 2's complement representations
 *   Post:  Diff[] == Left[] - Right[], if possible
 *   Ret:   false if overflow occurs when computing difference of Left[]
 *          and Right[]; true otherwise
 */
bool BI_Sub(uint8_t Diff[], const uint8_t Left[], const uint8_t Right[]) {
    
    // make a new array for the right side of the size 32 (as it is a 32 bit integer)
    uint8_t newRightArray[32];
    
    //
    BI_Neg(newRightArray, Right);
    
    BI_Add(Diff, Left, newRightArray);
    
    if (Diff[31] == Right[31] && Diff[31] != Left[31]) return false;
    else return true;
}

/**
 *   Computes negation of 2's complement representation of integer value.
 *
 *   Pre:   Neg[] and Right[] are of dimension 32
 *          Right[] stores a 2's complement representation
 *   Post:  Neg[] = -Right[]
 *   Ret:   false if negation cannot be correctly represented;
 *          true otherwise
 */
bool BI_Neg(uint8_t Neg[], const uint8_t Right[]) {
    
    for (int i = 0; i < 32; i++)
    {
        if(Right[i] == 0) Neg[i] = 1;
        
        else if(Right[i] == 1) Neg[i] = 0;
    }
    uint8_t oneArray[32];

    
    BI_Create(oneArray, 1);
    BI_Add(Neg, Neg, oneArray);
    
    bool boolCheck = false;
    
    for (int i = 0; i < 32; i++)
    {
        if((Neg[i] != Right[i]) || (Neg[31] == 0))
        {
            boolCheck = true;
            break;
        }
    }
    if (boolCheck == false)
    {
        for (int i = 0; i < 32; i++)
        {
            Neg[i] = 0;
        }
    }
    return boolCheck;
}

/**
 *   Prints 2's complement representation, with formatting.
 *
 *   Pre:   fp is open on an output stream
 *          BinInt[] is of dimension 32 and stores a 2's complement
 *             representation
 *          prefix and suffix are each NULL or point to a C-string
 *   Post:  the bits represented in BinInt[] have been written, preceded by
 *          prefix (if not NULL) and followed by suffix (if not NULL)
 */
void BI_fprintf(FILE* fp, const uint8_t BinInt[], char* prefix, char* suffix) {
    
    if ( prefix != NULL)
        fprintf(fp, prefix);
    
    for (int pos = NUM_BITS - 1; pos >= 0; pos--) {
        if ( pos < NUM_BITS - 1 && pos % 4 == 3 )
            fprintf(fp, " ");
        
        fprintf(fp, "%"PRIu8, BinInt[pos]);
    }
    
    if ( suffix != NULL)
        fprintf(fp, suffix);
}








// On my honor:
//
// - I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants
// assigned to this course.
//
// - I have not used C language code obtained from another student,
// or any other unauthorized source, either modified or unmodified.
//
// - If any C language code or documentation used in my program
// was obtained from an allowed source, such as a text book or course
// notes, that has been clearly noted with a proper citation in
// the comments of my program.
//
// Seth Balodi