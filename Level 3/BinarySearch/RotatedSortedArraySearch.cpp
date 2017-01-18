//
//  RotatedSortedArraySearch.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
 
 You are given a target value to search. If found in the array, return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 
 Input : [4 5 6 7 0 1 2] and target = 4
 Output : 0
 
 NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
 */

int findPivot(const vector<int> &A)
{
    int low = 0;
    int high = A.size() - 1;
    while (low <= high)
    {
        if (A[low] <= A[high])
            return low;
        else
        {
            int mid = (low + high) / 2;
            int prev = (mid + A.size() - 1) % A.size();
            if (A[mid] <= A[prev])
                return mid;
            else if (A[mid] <= A[high])
                high = mid - 1;
            else // A[mid] >= A[low]
                low = mid + 1;
        }
    }
    return 0;
}

int binarySearch(const vector<int> &A, int low, int high, int B)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == B)
            return mid;
        else if (B < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B)
{
    int pivot = findPivot(A);
    if (A[pivot] == B)
        return pivot;
    
    if (pivot >= 1)
    {
        int index = binarySearch(A, 0, pivot-1, B);
        if (index != -1)
            return index;
    }
    
    if (pivot+1 <= A.size()-1)
    {
        int index = binarySearch(A, pivot+1, A.size()-1, B);
        if (index != -1)
            return index;
    }
    
    return -1;
}
