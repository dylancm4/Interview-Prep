//
//  NumberOf1Bits.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Write a function that takes an unsigned integer and returns the number of 1 bits it has.
 
 Example:
 
 The 32-bit integer 11 has binary representation
 
 00000000000000000000000000001011
 so the function should return 3.
 
 Note that since Java does not have unsigned int, use long for Java
 */

int Solution::numSetBits(unsigned int A)
{
    int num_ones = 0;
    while (A)
    {
        if (A & 1)
            num_ones++;
        A >>= 1;
    }
    return num_ones;
}
