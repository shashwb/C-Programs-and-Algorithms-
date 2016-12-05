//
//  driverString.c
//  
//
//  Created by Seth Balodi on 12/9/14.
//
//

#include <stdio.h>
#include <stdint.h>
#include "string.h"


void testString();


char Quote00[] = "To be, or not to be: that is the question:  whether 'tis nobler in the mind to suffer the slings and arrows of outrageous fortune, or to take arms against a sea of troubles, and by opposing end them. -- Hamlet";
char Quote01[] = "Our indiscretion sometime serves us well when our deep plots do pall, and that should learn us there's a divinity that shapes our ends, rough-hew them how we will. -- Hamlet";
char Quote12[] = "If thou didst ever hold me in thy heart absent thee from felicity awhile, and in this harsh world draw thy breath in pain, to tell my story. -- Hamlet";

char Quote[] = "I fuck bitches";


int main(int argc, char** argv)
{
    testString();
    
    return 0;
}

void testString() {

    
    String str1;
    String str2;
    
    printf("\n");
    printf("Initialize str1 to the first 25 characters of: %s\n", Quote00);
    printf("\nDid it initialize correctly? %d\n", String_Init(&str1, Quote00, 25));
    
    //now let's get the value of the string that we initialized...
    printf("\n%s\n", String_GetCString(&str1));
    
    //let's get some more info by testing the dimensions, size, and empty funcitons
    printf("\nstr Dimension: %u\n", String_Dim(&str1));
    printf("\nstr Size: %u\n", String_Size(&str1));
    printf("\nstr Is it empty? (1 for true): %d\n", String_Empty(&str1));
    
    //free up the string pointed to by str1
    String_Free(&str1);
    printf("\nNow that I've just freed it...is it empty? (1 for true): %d\n", String_Empty(&str1));
    
    String mirrorString = String_Init(&str1, Quote, 20);
    printf("\nTesting Mirror_String %s\n", Mirror_String(Mirror_String));
    
    
    
    
}