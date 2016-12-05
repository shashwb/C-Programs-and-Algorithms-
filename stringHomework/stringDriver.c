#include <stdio.h>
#include <stdint.h>
#include "string.h"


char Quote00[] = "To be, or not to be: that is the question:  whether 'tis nobler in the mind to suffer the slings and arrows of outrageous fortune, or to take arms against a sea of troubles, and by opposing end them. -- Hamlet";
char Quote01[] = "Our indiscretion sometime serves us well when our deep plots do pall, and that should learn us there's a divinity that shapes our ends, rough-hew them how we will. -- Hamlet";
char Quote02[] = "If thou didst ever hold me in thy heart absent thee from felicity awhile, and in this harsh world draw thy breath in pain, to tell my story. -- Hamlet";


/* Basic driver to test String type */
int main()
{
    String str1, str2;
    
    /* this is really ugly code, but hey, how many of you will
     * actually look in this file?
     *
     * Going to use all of the functions to maniuplate the strings...
     */
    
    /* basic initialize test */
    printf("\n");
    printf("Initialize str1 to the first 25 characters of: %s\n", Quote00);
    String_Init(&str1, Quote00, 25);
    printf("str1 is: \"%s\"\n", String_GetCString(&str1));
    
    /* Test out the dimension, size, and empty functions */
    printf("str1 Dimension: %u\n",  String_Dim(&str1));
    printf("str1 Size: %u\n", String_Size(&str1));
    printf("str1 Empty function: %u\n", String_Empty(&str1));
    printf("\n");
    
    /* more string intialization */
    printf("Initialize str2 to \"Hello World!\"...\n");
    String_Init(&str2, "Hello World!", 12);
    printf("str2 is: \"%s\"\n", String_GetCString(&str2));
    printf("str2 Dimension: %u\n",  String_Dim(&str2));
    printf("str2 Size: %u\n", String_Size(&str2));
    printf("str2 Empty function: %u\n", String_Empty(&str2));
    printf("\n");
    
    /* append a String type */
    printf("\n");
    printf("Append str1 to str2...\n");
    String_AppendString(&str2, &str1);
    printf("str2 is: \"%s\"\n", String_GetCString(&str2));
    printf("str2 Dimension: %u\n",  String_Dim(&str2));
    printf("str2 Size: %u\n", String_Size(&str2));
    printf("\n");
    
    /* test erase function */
    printf("Erase the first character of str2\n");
    String_Erase(&str2, 0);
    printf("str2 is: \"%s\"\n", String_GetCString(&str2));
    printf("str2 Dimension: %u\n",  String_Dim(&str2));
    printf("str2 Size: %u\n", String_Size(&str2));
    printf("\n");
    
    /* test the compare function */
    printf("Lets compare str1 and str2. ");
    printf("This should be false.\n");
    printf("The result of the compare: %u", String_Compare(&str1, &str2));
    printf("\n");
    
    /* test the assign function */
    printf("\n");
    printf("Now assign str2 the value of str1, then compare the strings");
    printf(" again.\nThis time the result should be true.\n");
    String_Assign(&str2, &str1);
    printf("The result of the compare: %u", String_Compare(&str1, &str2));
    printf("\n");
    
    printf("\nAfter all of that...\n");
    printf("str2 is: \"%s\"\n", String_GetCString(&str2));
    printf("str2 Dimension: %u\n",  String_Dim(&str2));
    printf("str2 Size: %u\n", String_Size(&str2));
    printf("\n");
    
    
    /* test the split function */
    printf("Lets split a string...\n");
    printf("Initialize String split to 'CS 2505 Fall 2014'.\n");
    
    String split;
    uint32_t num_splits;
    
    String_Init(&split, "CS 2505 Fall 2014", 17);
    printf("split is: \"%s\"\n", String_GetCString(&split));
    
    String * tokens = String_Split(&split, ' ', &num_splits);
    
    if((num_splits != 4) || (tokens == NULL))
    {
        printf("There is a problem with your split function.\n");
        return 1;
    }
    
    printf("Print the results of the split function.\n");
    for(int s = 0; s < num_splits; s++)
    {
        printf("tokens[%d] is: \"%s\"\n", s,
               String_GetCString(&tokens[s]));
        printf("tokens[%d] Dimension: %u\n", s, String_Dim(&tokens[s]));
        printf("tokens[%d] Size: %u\n", s, String_Size(&tokens[s]));
        printf("\n");
    }
    
    printf("Test mirror function.\n");
    String_Mirror(&split);
    
    printf("Mirrored string is: \"%s\"\n", String_GetCString(&split));
    printf("Mirrored Dimension: %u\n",  String_Dim(&split));
    printf("Mirrored Size: %u\n", String_Size(&split));
    printf("\n");
    
    /* test erase functions */
    printf("Erase the first character of tokens[0].\n");
    String_Erase(&tokens[0], 0);
    printf("tokens[0] is: \"%s\"\n", String_GetCString(&tokens[0]));
    printf("tokens[0] Dimension: %u\n",  String_Dim(&tokens[0]));
    printf("tokens[0] Size: %u\n", String_Size(&tokens[0]));
    printf("\n");
    
    printf("Erase the middle-ish character of tokens[1]\n");
    String_Erase(&tokens[1], 2);
    printf("tokens[1] is: \"%s\"\n", String_GetCString(&tokens[1]));
    printf("tokens[1] Dimension: %u\n",  String_Dim(&tokens[1]));
    printf("tokens[1] Size: %u\n", String_Size(&tokens[1]));
    printf("\n");
    
    printf("Erase the end character of tokens[2]\n");
    String_Erase(&tokens[2], String_Size(&tokens[2]) - 1);
    printf("tokens[2] is: \"%s\"\n", String_GetCString(&tokens[2]));
    printf("tokens[2] Dimension: %u\n",  String_Dim(&tokens[2]));
    printf("tokens[2] Size: %u\n", String_Size(&tokens[2]));
    printf("\n");
    
    
    printf("Erasing an out of bounds char does nothing to the string\n");
    String_Erase(&tokens[3], String_Size(&tokens[3]));
    printf("tokens[3] is: \"%s\"\n", String_GetCString(&tokens[3]));
    printf("tokens[3] Dimension: %u\n",  String_Dim(&tokens[3]));
    printf("tokens[3] Size: %u\n", String_Size(&tokens[3]));
    printf("\n");
    
    /* test insert functions */
    printf("Insert a few Strings into tokens[3].\n");
    String_InsertString(&tokens[3], &tokens[2], 0);
    String_InsertString(&tokens[3], &tokens[2],
                        String_Size(&tokens[3])/2 + 1);
    String_InsertString(&tokens[3], &tokens[2], String_Size(&tokens[3]));
    printf("tokens[3] is: \"%s\"\n", String_GetCString(&tokens[3]));
    printf("tokens[3] Dimension: %u\n",  String_Dim(&tokens[3]));
    printf("tokens[3] Size: %u\n", String_Size(&tokens[3]));
    printf("\n");
    
    
    /* clean up */
    printf("Freeing all the strings...\n");
    
    String_Free(&str1);
    assert(str1.buf == NULL);
    assert(str1.size == 0);
    assert(str1.dim == 0);
    
    String_Free(&str2);
    assert(str2.buf == NULL);
    assert(str2.size == 0);
    assert(str2.dim == 0);
    
    String_Free(&split);
    assert(split.buf == NULL);
    assert(split.size == 0);
    assert(split.dim == 0);
    
    for(int s = 0; s < num_splits; s++)
    {
        String_Free(&tokens[s]);
    }
    
    free(tokens);
    
    return 0;
}