#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

/* REMINDER: You may not use ANY of the std
 * C string functions for this assignment.
 */

struct _String
{
    /* the string */
    char * buf;
    
    /* size of the string */
    uint32_t size;
    
    /* the actual dimension of the underlying array */
    uint32_t dim;
};

typedef  struct _String String;


/*
 * the String is initialized to the value in s.
 *
 * Pre:
 *	str is not NULL
 *	s is C string with length up to len (excludes null char)
 * Post:
 * 	Up to len characters in s are copied into str->buf and the
 * 	new string is terminated with a '\0'
 *
 * 	str->size is set to a maximum of len, but may be less
 * 	if a '\0' is encountered in s before len chars have occurred.
 *
 * 	str->dim is set to a maximum of len + 1, but may be less
 * 	if a '\0' is encountered in s before len chars have occurred.
 *
 * 	str->dim space is allocated for str->buf
 *
 * Returns:
 * 	true if allocation succeeds, false otherwise.
 */
bool String_Init(String *str, char * s, uint32_t len);


/* Every function after this line assumes the String objects
 * passed to the functions have been initialized by String_Init()
 */

/* ------------------------------------------------------------- */

/*
 * Gets/returns the underlying string
 *
 * Pre:
 *	str is not NULL
 * Returns:
 *	returns str->buf
 */
const char * String_GetCString(const String * const str);

/*
 * Pre:
 *	str is not NULL
 * Post:
 *
 * 	Deallocates the memory allocated for the string
 *	Sets str->buf to NULL after deallocating
 *	sets str->dim and str->size to 0
 *
 */
void String_Free(String *str);


/* Appends a String to the String
 *
 * Pre:
 *	dest is not NULL
 *	src is not NULL and contains a String you want to append
 * 	src != dest
 * Post:
 *	The String *src is appended to the String *dest
 *
 * Returns:
 *	true if the append goes fine (allocating etc), false otherwise
 *
 */
bool String_AppendString(String *dest, const String * const src);


/* Inserts a String at pos
 *
 * Pre:
 *	dest is not NULL
 *	src is not NULL
 *	src != dest
 *
 * Post:
 *	The String *src is inserted into *dest at pos.
 * Returns:
 *	If there is an invalid pos, or if the alloc goes bad return false.
 *	Otherwise return true.
 *
 * Other thoughts:
 * 	You are going to insert "before" pos. So if I insert at pos=0 I am
 *	inserting before the string, also if I were insert at pos=str->size
 *	(which technically outside the string) it will insert before the
 *	end and become the last char in the string.
 */
bool String_InsertString(String *dest, const String * const src,  uint32_t pos);


/*
 * Pre:
 * 	str is not NULL
 *
 * Returns:
 * 	The dimension of the string
 */
uint32_t String_Dim(const String * const str);

/*
 * Pre:
 * 	str is not NULL
 *
 * Returns:
 * 	The size of the string
 */
uint32_t String_Size(const String * const str);


/*
 * Pre:
 * 	str is not NULL
 *
 * Returns:
 * 	true is size is 0, false otherwise
 */
bool String_Empty(const String * const str);


/* Assigns dest to values in src /
 *
 * Pre:
 *	dest is not NULL
 *	src is not NULL and contains a String you want to assign
 * 	src != dest
 * Post:
 *	deep copy of *src into *dest, similar to *dest = *src
 *
 * Returns:
 *	true if the assign goes fine (allocating etc), false otherwise
 *
 */
bool String_Assign(String *dest, const String * const  src);


/* Compares two Strings
 *
 * Pre:
 *	str1 and str2 are not NULL
 * Returns:
 * 	returns true if the Strings are equal and false otherwise.
 */
bool String_Compare(const String * const str1, const String * const str2);




/*
 * Splits the String up into several sub-Strings using "split" as the delimiter.
 *
 * Pre:
 * 	str is not NULL
 *	split is delimiter used to break up the String
 * Post:
 * 	An array of Strings is created, here we split by the space character:
 * 		"Hello World" --> {"Hello", "World"}
 * 		"Hello   World  " --> {"Hello", "World"}
 *		"CS2505 Fall 2014" -->{"CS2505", "Fall", "2014"}
 *
 *	count should be set to the number of items created in the new array.
 *
 * 	Remeber each of the strings above is String, so dim and size should
 *      be have the correct value also.
 *
 *	This example would result in a NULL pointer and count = 0:
 *		" " --> NULL
 * Returns:
 * 	The newly allocated array of Strings, or NULL if the allocation fails.
 */
String* String_Split(String const * const str, char split, uint32_t *count);


/*
 * Modifies *str so that it contains the original string and a mirrored version.
 *
 * Pre:
 * 	str is not NULL
 * Post:
 * 	The string is mirrored like so:
 * 		"Hello World" --> "Hello WorlddlroW olleH"
 *
 * 	dim and size should be updated to conform to the new value.
 *
 * Returns:
 *	true if mirroring goes fine (allocating etc), false otherwise
 *
 */
bool String_Mirror(String *str);



/* Erases a single character.
 *
 *
 * Returns:
 * 	false if pos is outside of the string, true otherwise
 */
bool String_Erase(String * str, uint32_t pos);

#endif