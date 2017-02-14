//
//  ReverseBits.cpp
//  
//
//  Created by Dylan Miller on 2/12/17.
//
//

/*
 Reverse bits of an 32 bit unsigned integer
 
 Example 1:
 
 x = 0,
 
 00000000000000000000000000000000
 =>        00000000000000000000000000000000
 return 0
 
 Example 2:
 
 x = 3,
 
 00000000000000000000000000000011
 =>        11000000000000000000000000000000
 return 3221225472
 */

unsigned int Solution::reverse(unsigned int A)
{
    int B = 0;
    for (int i = 0; i < 32; i++)
    {
        int bit = A & 1;
        A >>= 1;
        B = (B<<1) + bit;
    }
    return B;
}

// Difficulty: Easy


