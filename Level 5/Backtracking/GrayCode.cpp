//
//  GrayCode.cpp
//  
//
//  Created by Dylan Miller on 2/12/17.
//
//

/*
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 There might be multiple gray code sequences possible for a given n.
 Return any such sequence.
 */

/*1 bit
 0
 1
 
 2 bits
 00
 01
 11
 10
 
 3 bits
 000
 001
 011
 010
 110
 111
 101
 100*/

void grayCode(vector<int>& codes, int A)
{
    if (A == 1)
    {
        codes.push_back(0);
        codes.push_back(1);
    }
    else
    {
        grayCode(codes, A-1);
        for (int i = codes.size()-1; i >= 0; i--)
        {
            int mask = 1 << A - 1;
            codes.push_back(codes[i] | mask);
        }
    }
}

vector<int> Solution::grayCode(int A)
{
    vector<int> codes;
    if (A > 0)
        ::grayCode(codes, A);
    return codes;
}

// Difficulty: Easy once I saw the pattern of going from n bit to n+1 bits.
