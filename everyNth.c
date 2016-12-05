//
//  everyNth.c
//  
//
//  Created by Seth Balodi on 10/16/14.
//
//

#include "everyNth.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

uint64_t everyNth(uint64_t Value, uint8_t N) {
    
    //initialize so that it doesn't have a garbage value
    uint64_t Accum = 0;
    
    uint64_t temporaryN = pow(10, N);               //temporarily stores 10 to a power. Used for choosing value
    uint64_t currCount = 0;                         //current count used for multiplier at the end
    
    uint64_t multiplier;                            //multiplier used towards digits
    uint64_t lastDigit;
    uint64_t temporaryValue;                        //the value being worked with through the while loop
    
    temporaryValue = Value;                         //assign to the Value
    
while(temporaryValue > 0)
{
    multiplier = pow(10, currCount);
    lastDigit = temporaryValue % 10;                //modulo operator to get the last digit
    temporaryValue = temporaryValue / temporaryN;   //break down the temporary value to eventually exit the while loop
    Accum = Accum + (lastDigit * multiplier);
    currCount++;                                    //increase the count
}

    
    return Accum;                                   //returns the N-th value(s)
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
