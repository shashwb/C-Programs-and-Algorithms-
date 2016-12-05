/*
 * CS:APP Data Lab
 *
 * MOHAMED KABAISH
 * PID: mgk5075
 *
 * SETH BALODI
 * PID: shashwb
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;
    
    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc. Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
// selected puzzles for Fall 2014
/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    /* return not x*/
    return !x;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    /* starts with x equal to binary 01, then shifts it to become 0100 and
     * adds itself 01, to produce 0101. The pattern is repeated until all
     * even bytes are 1, and odd bytes are 0. */
    int x = 1;
    x = (x << 2) + x;
    x = (x << 4) + x;
    x = (x << 8) + x;
    x = (x << 16) + x;
    return x;
    
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /* starts with the binary 1111 1111, then shifts 8*n bits over
     * the result is then & with the 1st parameter to get the specific
     * byte*/
    int mask = 0xff;
    mask = mask << (n << 3);
    x =  x & mask;
    return x >> (n << 3);
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /* First compute the absolute value of x, the quotient is computed by
     * shifting the first parameter to the right by n bytes. The result is
     * negated if the first parameter is negative (to achieve negative result*/
    int sign = x >> 31;
    int comp = ~sign;
    int absx = ((x & comp) +  (((~x) + 1) & sign));
    int quot = absx >> n;
    return (comp & quot) + (sign & ((~quot)+1));
}
/*
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
    /* First the absolute value is computed. The remainder is computed by
     * shifting the binary 01 to the right by n bits, then adding the
     * complement of zero, the result of this expression is then & with the
     * absolute value of the first parameter. The result is negated if the
     * first parameter is negative*/
    int sign = x >> 31;
    int comp = ~sign;
    int absx = ((x&comp) + (((~x)+1)&sign));
    int rem = absx & ((1<<n) + ~0);
    return (comp & rem) + (sign & ((~rem)+1));
}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
    /** in this function, we have to use the ‘^’ operator in order to get whether
     or not x and y have the same sign because overflow happens when x and y have
     different signs. We get the result of x - y and compares it to x to see if the 
     result and x have the same sign. We calculate the sign bit and shift it,
     negating the result and returning it to determine if we can compute it without overflow. **/
    
    int negate = (~y + 1);
    int result = x + negate;
    
    int compareResultToX = x ^ result;
    int comparesXY = x ^ y;
    
    return !((comparesXY & compareResultToX) >> 31);
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
    /** compute the absolute value of x, by arithmetically shifting the first
     *  parameter by 31 bits (producing all 1 for negative, and all 0 for
     *  positive. Using the variables sign and comp (complement), we use the
     *  two variables as masks, and negate the first parameter if sign is all 1
     *  and simply return the value of the first parameter if comp is all 1*/
    int sign = x >> 31;
    int comp = ~sign;
    return ((x & comp) +  (((~x) + 1) & sign));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    
    /* first, we need to check various levels of bytes starting from the first four.
      logarithmically, we need to check two, then one byte. Eventually we will get to bits.
      we will need the amount of the shift and also a variable to hold the result. The logic
      below will give the result of at least sixteen if 4 bits exist there and we need to bring
      all of the high bits down during each check. We then go logarithmically down and check the
      next bytes, which will result in 8 more, and then we check the next byte which will give a 
      result of of 4 more. Checking the next 4 bits, we get a result of 2 more. We have been changing
      the result variable every time.  We shift the high
      bits down again. We need to check the bit in the position one left shift from the last, then 
      there has to be one more. This will return the floor of the logarithmic function*/
    int initialMask = 0xFF << 24 | 0xFF << 16;
    int mask1 = 0xFF << 8;
    int mask2 = 0xF0;
    int mask3 = 0x0C;
    
    int shiftVar;
    int result = 0;
    
    result = !!(x & initialMask) << 4;
    x >>= result;
    
    shiftVar = !!(x & mask1) << 3;
    x >>= shiftVar;
    result += shiftVar;
    
    shiftVar = !!(x & mask2) << 2;
    x >>= shiftVar;
    result += shiftVar;
    
    shiftVar = !!(x & mask3) << 1;
    x >>= shiftVar;
    result += shiftVar;
    
    //shifting the last
    result += (x >> 1);

    return result;
  } 
