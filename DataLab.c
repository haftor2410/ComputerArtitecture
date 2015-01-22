/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  4. Use the btest checker to formally verify your functions
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
 *   2. Use the btest checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

//Skila staestu minustolu two's complement...
int tmin(void) {
  return 1 << 31;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // (~x + ~x) = 0 for only the biggest number and -1
    int isMinusOneOrBiggest, isNeg;

    isMinusOneOrBiggest = (~x + ~x);

    //check if its a negative number
    isNeg = !(~0^x);

    return !(isMinusOneOrBiggest|isNeg);
}

/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    // the | operator is the same as & except for 1's
    //so first turn everything around use the | and then turn it back around
    return ~(~x|~y);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */

int upperBits(int n) {

    int opening, shifting;
    //opens up all the bits except when its zero, then nothing opens
    opening = ~!!n + 1;

    //shifts them to there position
    shifting = ~(~32 + n);

    return opening << shifting;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
    //if ^ does not return 0 then we know the numbera are not the same
    return !(x^y);
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

    int signBit, extraAdding;

    //checks if the number is pos or neg
    signBit = (x >> 31);

    //we will add this number to x if the number is negative (one less than n)
    //because we will round up if we dont
    extraAdding = ((1 << n) + ~0);

    //if the number is pos no adding will be done
    return (x + (signBit & extraAdding)) >> n;
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2


 */
int byteSwap(int x, int n, int m) {

    int shiftN, shiftM, maskN, maskM, byteNtoM, byteMtoN, maskOut;

    // the shifts for N and M
    shiftN = n<<3;
    shiftM = m<<3;

    // opens up the N and M bytes
    maskN = 0xff << shiftN;
    maskM = 0xff << shiftM;

    // gets the n'th byte, shift it to be the LSB and then shifts it to m's position
    // then mask with maskM to compinsate for the sign extension
    byteNtoM = (((x & maskN) >> shiftN) << shiftM) & maskM;

    // gets the m'th byte, shift it to be the LSB and then shifts it to n's position
    // then mask with maskN to compinsate for the sign extension
    byteMtoN = (((x & maskM) >> shiftM) << shiftN) & maskN;

    // turns of the n and m bytes
    maskOut = x & ~maskN & ~maskM;

    //returns the bytes in the requested order
    return maskOut | byteNtoM | byteMtoN;
}
/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {

    int oddMask;

    //mask that is all odd bits
    oddMask = (0xaa<<24) + (0xaa<<16)  + (0xaa<<8)  + (0xaa) ;

    return !!(x&oddMask);
}

/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {

    int XposYneg, dif, signbit, signbitAndDif;

    // if x is pos and y is neg the sign bit is = 1
    XposYneg = y & (~x);

    // if y-x is negative, the sign bit is = 1
    dif = y + (~x + 1);

     // if x and y have the same sign bit, the sign bit is = 1
    signbit = (~(x ^ y));

    // if the the differance is negative and x and y have the same sign bit, the sign bit is = 1
    signbitAndDif = signbit & dif;

    // if either is true then x is not greater
    return ((XposYneg|signbitAndDif) >> 31 & 1);
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {

    int normalShift, opening, negShift;

    // shifts x n-times
    normalShift = (x>>n);

    // if x is negative we need to compensate for the sign extension

    // we open up n bits
    opening = (1 << n) + ~0;

    // shift them 32 - n times
    negShift = ~(~32 + n);

    // by masking we get have compensated for the sign extension
    return normalShift & ~(opening << negShift);
}

/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3 
 */
int isAsciiDigit(int x) {

    int toLargeMask, isThreeMask, isOneToNineMask;

    //checks if x is larger then what is expected
    toLargeMask = (x & (~0<<8));

    //checks if the second byte is three
    isThreeMask = ((x & 240) ^ 48);

    //checks if the first byte is (0-9)
    isOneToNineMask = !(!(x&8)|!(x&6));

    //if everything holds we return 1
    return !(toLargeMask | isThreeMask | isOneToNineMask);
}

/* 
 * subOK - Determine if possible to compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int subOK(int x, int y) {

    int xSign, ySign, diffSign, posOverflow, negOverflow;

    // get sign bit from x
    xSign = (x >> 31) & 1;

    // get sign bit from y
    ySign = (y >> 31) & 1;

    //get sign bit from x-y
    diffSign = ((x + (~y + 1)) >> 31) & 1;

    //if x is pos and y is neg we owerflow if the sign bit is 1 in diffSign
    //because (x-(-y)) should give 0 in the sign bit. If its 1 we have posOverflow
    posOverflow = (!(xSign)) & ySign & diffSign;

    //if x is neg and y is pos we owerflow if the sign bit is 0 in diffSign
    //because (-x-y) should give 1 in the sign bit. If its 0 we have posOverflow
    negOverflow = xSign & !(ySign) & !diffSign;

    //if it overflow either pos or neg we return 0
    return !(posOverflow | negOverflow);
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */

int isNonZero(int x) {

    int xAndNegX;

    //all number except for 0 will have the sign bit = 1
    xAndNegX = x | (~x + 1);

    //is the sign bit is 1 then its not zero
    return (xAndNegX >> 31) & 1;
}
/*
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {

    int xAndNegX;

    //all number except for 0 will have the sign bit = 1
    xAndNegX = x | (~x + 1);

    //check the sign bit and return 1 if x is zero
    return ((xAndNegX >> 31 ) & 1) ^ 1;
}

/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {

    unsigned maskSignBit, maskSpecial, maskMant, posNum;

    // mask to mask the sign bit out
    maskSignBit = 0x7FFFFFFF;

    // mask to check if UF is a special case
    maskSpecial = 0x7F800000;

    // mask to look at the mantissa
    maskMant = 0x7fffff;

    // UF after having masked out the sign bit
    posNum = uf & maskSignBit;


    // returns UF is a special case and not infinity == not a number
    if (((maskSpecial & uf) == maskSpecial) && (maskMant & uf) != 0)
    {
     	return uf;
    }
    // else return positive UF
    else
    {
     	return posNum;
    }
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */


unsigned float_half(unsigned uf) {

    int maskSignBit, maskExponent, maskFraction, normToDenorm, signBit, exponent, fraction;
    int lastTwoBitsAre11, isExponentOne;

    maskSignBit = 0x80000000;
    maskExponent = 0x7f800000;
    maskFraction = 0x7fffff;
    normToDenorm = 1 << 22;

    signBit = maskSignBit & uf;
    exponent = maskExponent & uf;
    fraction = maskFraction & uf;

    // returns true if last two bits are 11 else return 0
    lastTwoBitsAre11 = !((3 & fraction) ^ 3);

    // returns true if the exponent is exactly 1 else return 0
    isExponentOne = !((exponent >> 23) ^ 1);

    // if UF is a special case (all 1's) we return UF
    if(!(maskExponent ^ exponent)){
        return uf;
    }

        // if UF is denormalized we shift the fraction one to the right
    if((exponent) == 0){
        // if the last two bits are 11 we have to compensate by adding 1 before shifting
        return signBit | (fraction + lastTwoBitsAre11) >> 1;
    }

    // if we are shifting from normalized to denormalized
    if(isExponentOne){
        return signBit | normToDenorm | (fraction + lastTwoBitsAre11) >> 1;
    }

    //else we do exponent - 1
    return signBit | ((exponent + ~0 ) & maskExponent) | fraction;

}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

