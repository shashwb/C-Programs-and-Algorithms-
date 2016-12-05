//
//  everyNth.h
//  
//
//  Created by Seth Balodi on 10/16/14.
//
//

#ifndef EVERYNTH_H
#define EVERYNTH_H
#include <stdint.h>

///////////////////////////////////////////////////////////////////////
//
//  Forms an integer value by taking the Nth digits of Value, starting
//  at the low digit, and concatenating those digits.
//
// Examples:
//     everyNth(12345, 1) = 12345
//     everyNth(12345, 2) =   135
//     everyNth(12345, 3) =    25
//     everyNth(12345, 4) =    15
//     everyNth(12345, 5) =     5
//
// Pre:      Value and N have been initialized.
//           N > 0.
// Post:
// Returns:  integer value formed by concatenating the specified
//           digits of Value; if N = 0, the return value is undefined
//
// Restrictions:
//    You may use any integer operations supported in C.  You may also
//    use any selection (if, if..else, etc) or iteration (for, while)
//    constructs.
//    You may not use an array, nor may you perform any I/O operations.
//
uint64_t everyNth(uint64_t Value, uint8_t N);

#endif
