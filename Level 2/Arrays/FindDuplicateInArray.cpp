//
//  FindDuplicateInArray.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
 
 Sample Input:
 
 [3 4 1 4 1]
 Sample Output:
 
 1
 If there are multiple possible answers ( like in the sample case above ), output any one.
 
 If there is no duplicate, output -1
 */

int Solution::repeatedNumber(const vector<int> &A)
{
    vector<unsigned char> B((A.size()+7)/8, 0);
    for (int i = 0; i < A.size(); i++)
    {
        int number = A[i];
        int index = (number - 1) / 8;
        int bit_offset = (number - 1) % 8;
        unsigned char bit_mask = 1 << bit_offset;
        if (B[index] & bit_mask)
            return number;
        else
            B[index] |= bit_mask;
    }
    return -1;
}

// Difficulty: Easy, but although my solution passed, I did not give the intended solution, which is difficulty hard and not intuitive. The intended solution uses sqrt() to create ranges of numbers, then counts the numbers which fall into each range. A range containing a repeated number will have a count that is too high, then that range can be scanned using a hash table to determine the repeated number.
