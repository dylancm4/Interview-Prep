//
//  SingleNumberII.cpp
//  
//
//  Created by Dylan Miller on 2/12/17.
//
//

/*
 Given an array of integers, every element appears thrice except for one which occurs once.
 
 Find that element which does not appear thrice.
 
 Note: Your algorithm should have a linear runtime complexity.
 
 Could you implement it without using extra memory?
 
 Example :
 
 Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
 Output : 4
 */

int Solution::singleNumber(const vector<int> &A)
{
    int bits[32];
    memset(bits, 0, sizeof(bits));
    for (int i = 0; i < A.size(); i++)
    {
        int number = A[i];
        for (int j = 31; j >= 0; j--)
        {
            int bit = number & 1;
            bits[j] += bit;
            if (bits[j] == 3)
                bits[j] = 0;
            number >>= 1;
        }
    }
    
    int number = 0;
    for (int i = 0; i < 32; i++)
    {
        number <<= 1;
        number += bits[i] ? 1 : 0;
    }
    
    return number;
}

// Difficulty: Hard. I needed to use the Solution Approach below. I was mainly thrown off by the question asking "Could you implement it without using extra memory?" Since a similar problem called "Single Number" could be solved without extra memory by using XOR, I was trying to figure out a similar approach here. I'm not sure why the question mentioned no extra memory, since the provided solution does use extra memory. Once I realized I could use extra memory, it wasn't difficult, since I had already thought about cancelling out groups of three 1's. If I had known I could use extra memory from the start, it still wouldn't have been easy, but perhaps medium difficulty.

/*
 Solution Approach:
 Having noticed that if X has 1 in that position, we will have 3x+1 number of 1s in that position. If X has 0 in that position, we will have 3x+1 number of 0 in that position.
 
 A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit.
 
 We can improve this based on the previous solution using three bitmask variables:
 
 ones as a bitmask to represent the ith bit had appeared once.
 twos as a bitmask to represent the ith bit had appeared twice.
 threes as a bitmask to represent the ith bit had appeared three times.
 When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones.
 */
