//
//  RemoveDuplicatesFromSortedArray.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Remove duplicates from Sorted Array
 Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
 
 Note that even though we want you to return the new length, make sure to change the original array as well in place
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 Example:
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].
 */

int Solution::removeDuplicates(vector<int> &A)
{
    if (A.size() < 2)
        return A.size();
    
    int offset = 0;
    int j = 0;
    for (int i = 0; i < A.size(); i = j)
    {
        for (j = i+1; j < A.size(); j++)
        {
            if (A[j] > A[i])
            {
                if (offset != i)
                    A[offset] = A[i];
                offset++;
                break;
            }
        }
    }
    // last element special case
    int last_index = A.size() - 1;
    if (offset != last_index)
        A[offset] = A[last_index];
    offset++;
    
    // Unsure if A should be trimmed. If so, the return value is redundant, since it would equal A.size().
    return offset;
}
