//
//  NextPermutation.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
 
 If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
 
 The replacement must be in-place, do not allocate extra memory.
 
 Examples:
 
 1,2,3 → 1,3,2
 
 3,2,1 → 1,2,3
 
 1,1,5 → 1,5,1
 
 20, 50, 113 → 20, 113, 50
 Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 
 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
 */

void Solution::nextPermutation(vector<int> &A)
{
    // Find the longest decreasing suffix.
    int first_lesser_index = -1;
    for (int i = A.size()-1; i > 0; i--)
    {
        if (A[i-1] < A[i])
        {
            first_lesser_index = i-1;
            break;
        }
    }
    if (first_lesser_index == -1)
    {
        reverse(A.begin(), A.end());
        return;
    }
    
    // Swap the last element of the prefix with the next greater
    // element in the suffix, yielding smallest possible prefix.
    int next_greater_index;
    for (int i = A.size()-1; i > first_lesser_index; i--)
    {
        if (A[i] > A[first_lesser_index])
        {
            next_greater_index = i;
            break;
        }
    }
    swap(A[first_lesser_index], A[next_greater_index]);
    
    // Reverse suffix to get smallest possible suffix.
    reverse(A.begin() + first_lesser_index + 1, A.end());
}

// Difficulty: Very hard, not intuitive

