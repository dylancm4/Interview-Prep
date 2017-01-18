//
//  LongestConsecutiveSequence.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
 Example:
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
 Your algorithm should run in O(n) complexity.
 */

int Solution::longestConsecutive(const vector<int> &A)
{
    if (!A.size())
        return 0;
    vector<int> B = A;
    sort(B.begin(), B.end());
    int prev_num = 0x7FFFFFFF;
    int consecutive_length = 1;
    int max_consecutive_length = 1;
    for (vector<int>::const_iterator it = B.begin(); it != B.end(); it++)
    {
        int num = *it;
        if (num == prev_num)
            ; // skip duplicates
        else if (num == prev_num+1)
        {
            consecutive_length++;
            if (consecutive_length > max_consecutive_length)
                max_consecutive_length = consecutive_length;
        }
        else
            consecutive_length = 1;
        prev_num = num;
    }
    return max_consecutive_length;
}
