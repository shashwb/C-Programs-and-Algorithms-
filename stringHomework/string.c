  //
//  string.c
//  
//
//  Created by Seth Balodi on 12/8/14.
//
//

#include "string.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


/*
 The String is initialzed to the value in s.
 
 Pre:
    str is not NULL
    s is C string with length up to len (excludes the null char)
 Post:
    Up to len characters in s are copied into str->buf and the new string is terminated with a '\0'
 
    str->size is set to maximum of len, but may be less
    if a '\0' is encoutnered in s before len chars have occurred.
 
    str->dim is set to  maximum of len + 1, but may be less 
    if a '\0' is encountered in s before len chars have occurred.
 
    str->dim space is allocated for str->buf
 
 Returns:
    true if allocation succeeds, false otherwise
 */
bool String_Init(String *str, char * s, uint32_t len) {
    
    
    //s is the pointer to the array of characters that we are going to initialize into our str
    
    //the size of the string is equal to the length
    str->size = len;
    //the dimension of the string also contains the null pointer...therefore +1
    str->dim = len + 1;
    
    //allocates space for the actual string
    str->buf = malloc(str->dim * sizeof(char));
    
    
    if (str->buf == NULL) {
        return false;
    }
    
    for (int i = 0; i < len; i++) {
        //index of each and copies them in
        *(str->buf + i) = *(s + i);
    }
    return true;
}





/*
 Gets/erturns the underlying string.
 Pre:
    str is not NULL
 Returns:
    returns str->buf
 */
const char * String_GetCString(const String * const str) {
    
    //simply returns the buf member of the str struct
    return str->buf;
    
}



/*
 Pre: 
    str is not NULL
 Post:
    Deallocates the memory allocated for the string
    sets str->buf to NULL after deallocating
    sets str->dim and str->size to 0
 */
void String_Free(String *str) {
    
    
    //free the allocated memory
    free(str->buf);
    
    //sets str->buf to NULL after freeing up the memory
    str->buf = NULL;
    //sets str->dim and str->size to 0
    str->dim = 0;
    str->size = 0;
    
}



/* 
 Pre:
    dest is not NULL
    src is not NULL and constains a String you want to append
    src != dest
 Post:
    The string *src is appended to the String *dest
 Returns:
    true if the append goes fine (allocating etc), false otherwise
 */
bool String_AppendString(String *dest, const String * const src) {
    
    //here we reallocate the dest->buffer and makes
    
    int totalSizeAppendString = (dest->size + src->dim);
    char *reallocate = realloc(dest->buf, totalSizeAppendString);
    if (reallocate == NULL) {
        return false;
    }
    dest->buf = reallocate;
    
    //goes through the entire size of the string we are appending onto dest
    for (int i = 0; i < src->size; i++) {
        //puts the values in src into destination while incrementing the counter
        *(dest->buf + dest->size + i) = *(src->buf + i);
    }
    
    //we set the new size to the size of both strings
    dest->dim = dest->dim + src->dim;
    dest->size = dest->size + src->size;

    //finally, we add the null terminator to the end of the dest->buf
    *(dest->buf + dest->size + 1) = '\0';
    
    //return true!
    return true;
    
}



/*
 Pre:
    str is not NULL
 Returns:
    The dimension of the string
 */
uint32_t String_Dim(const String * const str) {
    
    //get the dimension member of the String
    return str->dim;
}




/*
 Inserts a String at pos
 Pre:
    dest is not NULL
    src is not NULL
    src != dest
 
 Post: 
    C string is inserted
 Returns:
    If there is an invalid pos, or if the alloc goes bad, return false.
    Otherwise we return true.
 
 Other thoughts:
    You are goint to insert "before" pos, so if I insert at post=0, I am inserting
    before the string, also if I were to insert at pos=str->size (which is technically
    outside of the string), it will insert before the end and become the last char 
    in the string.
 */
//TEST
bool String_InsertString(String *dest, const String * const src, uint32_t pos) {
    
    
    if (pos > (dest->size)) {
        return false;
    }
    
    //reallocate space to make more room
    //reallocateding the destination string value.
    //add the dimension of destination and the size of the thing we are inserting
    int totalSizeInsertedString = (dest->size + src->dim);
    
    char *reallocate = realloc(dest->buf, totalSizeInsertedString);
    if (reallocate == NULL) {
        return false;
    }
    
    dest->buf = reallocate;
    
    
    for (int i = 0; i <= (dest->size - pos); i++) {
        //here is where we shift the positions to make room for what we're entering
        *(dest->buf + i + src->size + pos) = *(dest->buf + i + pos);
    }
    
    for (int i = 0; i < src->size; i++) {
        //here is where we actually insert the string
        *(dest->buf + i + pos) = *(src->buf + i);
    }
    
    dest->size = dest->size + src->size;
    //SET THIS AT THE END TO STOP MEMORY LEAKS
    dest->dim = dest->dim + src->dim;
    
    int forTerminator = dest->dim + src->size;
    
    //set the null terminator
    *(dest->buf + forTerminator) = '\0';
    return true;

}


/*
 Pre:
    str is not NULL
 Returns:
    True if size is 0, false otherwise
 */
bool String_Empty(const String * const str) {
    
    //obviously if the size of the string is 0, the string is empty
    if (str->size == 0) {
        return true;
    }
    return false;
    
}




/*
 GO THROUGH AND EXPLAIN
 Assigns dest to values in src
 Pre:
    dest is not NULL
    src is not NULL and contains a String you want to assign
    src != dest
Post:
    deep copy of src into dest, similar to dest = src
 Return:
    True if the assign goes fine (allocating etc), false otherwise
 */
bool String_Assign(String *dest, const String* const src) {

    

    char *reallocate = realloc(dest->buf, src->dim);
    if (reallocate == NULL) {
        return false;
    }
    
    dest->buf = reallocate;
    
    //go through the size of the string we want to copy in to dest
    for (int i=0; i < src->size; i++) {
        //put the values in src into the destination
        *((dest->buf) + i) = *((src->buf) + i);
    }
    

    //set the members of the string here, along with the null terminator
    dest->size = src->size;
    dest->dim = src->dim;
    *(dest->buf + dest->size) = '\0';
    
    return true;
    
}




/*
 WHAT DOES THIS MEAN
 Compares two strings
 Pre:
    str1 and str2 are not NULL
 Returns:
    returns true if they are equal, false otherwise
 */
bool String_Compare(const String * const str1, const String * const str2) {
    
    //go through the first string's values
    for (int i=0; i < str1->size; i++) {
        //compare string1 to string 2 buffer values
        //dereference the two buffers and compare the values while iterating
        if (*(str1->buf + i) != *(str2->buf + i)) {
            return false;
        }
    }
    return true;
    
}


/*
 Erases a single character.
 Returns:
    false if position is outside of the string, true otherwise
 */
bool String_Erase(String *str, uint32_t pos) {

    //if the position is outside of the string, then it returns false
    if (pos >= str->size) {
        return false;
    }
    
    //reallocate str->buff to the size
    char *reallocatedToBuf = realloc(str->buf, str->size);
    if (reallocatedToBuf == NULL) {
        return false;
    }
    //set str->buf to the memory that was reallocated
    str->buf = reallocatedToBuf;
    
    //we are doing str->size - 1 because we need to use str->size for the null terminator
    //go through the arrays
    for (int position = pos; position < str->size - 1; position++) {
        //takes whatever is at position and sets it equal to whatever is one idnex after it,
        //which effectively erases it
        *(str->buf + position) = *(str->buf + position + 1);
    }
    
    str->size = str->size - 1;
    str->dim = str->dim - 1;
    
    //set the null terminator
    *(str->buf + str->size) = '\0';
    return true;
}


/*
 Pre:
    str is not NULL
 Returns:
    The size of the string
 */
uint32_t String_Size(const String * const str) {
    return str->size;
}




/*
 Modified *str so that it contains the original string and a mirrored version.
 
 Pre:
    str is not NULL
 Post:
    The string is mirrored like so:
    "Hello World --> "Hello Worlddlrow olleH"
 
 dim and size should be updated to conform to the new value.
 
 Return:
    True if mirroring goes fine (allocating etc), false otherwise
 */
bool String_Mirror(String *str) {
    
    //Hello World --> Hello Worlddlrow olleH
    int totalMirrorString = (str->size * 2) + 1;
    char *reallocate = realloc(str->buf, totalMirrorString);
    if (reallocate == NULL) {
        return false;
    }
    
    str->buf = reallocate;
    
    //we put where the old index is and where the new index is.
    //we will use a while loop iterate both in separate ways, and then set the new index
    //to the old index which is iterating backwards. This adds it to the end of the first one
    //based on where we put our original indexes to
    int oldIndex = str->size - 1;
    int newIndex = str->size;

    while (oldIndex >= 0){
        *(str->buf + newIndex) = *(str->buf + oldIndex);
        oldIndex--;
        newIndex++;
    }
    
    str->size = str->size * 2;
    return true;
}


/*
 Split the String up into several sub-Strings using "split" as the delimiter
 
 Pre:
    str is not NULL
    split is delimiter used to break up the string
 Post:
    An array of Strings is created, here we split by the space character:
        "Hello World" --> {"Hello", "World"}
        "Hello   World  " --> {"Hello", "World"}
        "CS2505 Fall 2014" --> {"CS2505", "Fall", "2014"}
 
    count should be set to the number of items created in the new array.
 
    Remember each of the strings above is String, so dim and sie should have
    the correct value also.
 
    This example would result in a NULL pointer and count = 0;
        " " --> NULL
 Returns:
    The newly allocated array of Strings, or NULL if the allocation fails.
 */
String* String_Split(String const * const str, char split, uint32_t *count) {
    

    //set an index to check for splits
    int ind = 0;
    
    //while the index of the string is on the split variabe and i is less than the size, we will increment
    //the index
    while (((*str).buf[ind] == split) && (ind < (*str).size)) {
        ind++;
    }
    //using this value, we compare
    if (ind == (*str).size) {
        *count = 0;
        return NULL;
    }
    
    *count = 1;
    
    
    for (; ind < (*str).size - 1; ind++) {
        if ((*str).buf[ind] == split && (*str).buf[ind+1] != split) {
            *count = (*count) + 1;
        }
    }
    
    String* outputString = (String*) (malloc(sizeof(String) * (*count)));

    if (outputString == NULL) {
        return NULL;
    }
    
    //set a variable for the beginning index
    int beginningIndex = 0;
    while ((str->buf[beginningIndex] == split) && (beginningIndex < str->size)) {
        beginningIndex++;
    }
    
    int j;
    int len = 0;
    int index = 0;
    
    
    for (ind = beginningIndex; ind < str->size; ind++) {
        if (str->buf[index] != split) {
            len++;
            if (ind == (*str).size - 1) {
                outputString[index].buf = (char*) (malloc((len + 1) * sizeof(char)));
                for (j = 0; j < len; j++) {
                    
                    outputString[index].buf[j] = str->buf[j + beginningIndex];
                    outputString[index].buf[len] = '\0';
                    outputString[index].size = len;
                    outputString[index].dim = len + 1;
                    
                    len = 0;
                }
            }
            else {
                if (len != 0) {
                    outputString[index].buf = (char*) malloc((len+1) * sizeof(char));
                    for (j = 0; j < len; j++) {
                        
                        outputString[index].buf[j] = (*str).buf[j + beginningIndex];
                        outputString[index].buf[len] = '\0';
                        outputString[index].size = len;
                        outputString[index].dim = len + 1;
                        len = 0;
                        
                        index++;
                    }
                beginningIndex = ind + 1;
                }
            }
        }
    }
    
    return outputString;

    
    
    
    
    
    
    
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
// was obtained from another source, such as a text book or course
// notes, that has been clearly noted with a proper citation in
// the comments of my program.
//
// - I have not designed this program in such a way as to defeat or
// interfere with the normal operation of the Curator System.
//
// <Student Name>




