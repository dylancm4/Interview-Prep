//
//  RearrangeArray.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
 
 Example:
 
 Input : [1, 0]
 Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
 * All elements in the array are in the range [0, N-1]
 * N * N does not overflow for a signed integer
 */

inline void setOriginalValue(int& c, int x, int radix)
{
    c = x * radix;
}

inline int getOriginalValue(int c, int radix)
{
    return c / radix;
}

inline void setNewValue(int& c, int x, int radix)
{
    c += x;
}

inline int getNewValue(int c, int radix)
{
    return c % radix;
}

void Solution::arrange(vector<int> &A)
{
    int a_size = A.size();
    for (int i = 0; i < a_size; i++)
    {
        setOriginalValue(A[i], A[i], a_size);
    }
    for (int i = 0; i < a_size; i++)
    {
        setNewValue(A[i], getOriginalValue(A[getOriginalValue(A[i], a_size)], a_size), a_size);
    }
    for (int i = 0; i < a_size; i++)
    {
        A[i] = getNewValue(A[i], a_size);
    }
}
