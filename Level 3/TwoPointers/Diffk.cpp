//
//  Diffk.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 
 Example: Input :
 A : [1 3 5]
 k : 4
 Output : YES as 5 - 1 = 4
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 
 Try doing this in less than linear space complexity.
 */

int Solution::diffPossible(vector<int> &A, int B)
{
    int j = 1;
    for (int i = 0; i < A.size(); i++)
    {
        for (j = max(j, i+1); j < A.size(); j++)
        {
            int difference = A[j] - A[i];
            if (difference == B)
                return 1;
            else if (difference > B) // further comparisons yield differences which are too large
            {
                // Leave j at current value, since lower j will yield differences which are too small.
                break;
            }
        }
    }
    return 0;
}
