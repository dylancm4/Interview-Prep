//
//  MaxNonNegativeSubArray.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Find out the maximum sub-array of non negative numbers from an array.
 The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
 
 Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
 
 Example:
 
 A : [1, 2, 5, -7, 2, 3]
 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3]
 NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
 NOTE 2: If there is still a tie, then return the segment with minimum starting index
 */

vector<int> Solution::maxset(vector<int> &A)
{
    int a_size = A.size();
    int winning_start_index = 0;
    int winning_end_index = -1;
    long long winning_sum = -1;
    int start_index = -1;
    long long sum;
    int i;
    for (i = 0; i < a_size; i++)
    {
        int num = A[i];
        if (start_index == -1)
        {
            if (num >= 0)
            {
                start_index = i;
                sum = num;
            }
        }
        else // already started
        {
            if (num >= 0)
            {
                sum += num;
            }
            else
            {
                if (sum > winning_sum)
                {
                    winning_start_index = start_index;
                    winning_end_index = i - 1;
                    winning_sum = sum;
                }
                start_index = -1;
            }
        }
    }
    if (start_index != -1)
    {
        if (sum > winning_sum)
        {
            winning_start_index = start_index;
            winning_end_index = i - 1;
            winning_sum = sum;
        }
    }
    
    vector<int> result(winning_end_index - winning_start_index + 1);
    for (int i = winning_start_index, j = 0; i <= winning_end_index; i++, j++)
    {
        result[j] = A[i];
    }
    return result;
}
