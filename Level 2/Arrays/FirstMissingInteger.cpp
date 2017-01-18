//
//  FirstMissingInteger.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an unsorted integer array, find the first missing positive integer.
 
 Example:
 
 Given [1,2,0] return 3,
 
 [3,4,-1,1] return 2,
 
 [-8, -7, -6] returns 1
 
 Your algorithm should run in O(n) time and use constant space.
 */

int Solution::firstMissingPositive(vector<int> &A)
{
    sort(A.begin(), A.end());
    if (A.back() < 1)
        return 1;
    
    // Skip negatives.
    int i;
    int a_size = A.size();
    for (i = 0; i < a_size; i++)
    {
        if (A[i] > 0)
            break;
    }
    
    int least_int = 1;
    for (; i < a_size; i++)
    {
        if (A[i] != least_int)
            return least_int;
        least_int++;
    }
    return A.back() + 1;
}
