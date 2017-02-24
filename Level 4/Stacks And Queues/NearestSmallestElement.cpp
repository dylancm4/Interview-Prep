//
//  NearestSmallestElement.cpp
//  
//
//  Created by Dylan Miller on 2/23/17.
//
//

/*
 Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
 
 More formally,
 
 G[i] for an element A[i] = an element A[j] such that
 j is maximum possible AND
 j < i AND
 A[j] < A[i]
 Elements for which no smaller element exist, consider next smaller element as -1.
 
 Example:
 
 Input : A : [4, 5, 2, 10]
 Return : [-1, 4, -1, 2]
 
 Example 2:
 
 Input : A : [3, 2, 1]
 Return : [-1, -1, -1]
 */

vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> smaller_array;
    stack<int> smaller_stack;
    for (int i = 0; i < A.size(); i++)
    {
        bool smaller_found = false;
        while (smaller_stack.size())
        {
            int num = smaller_stack.top();
            if (num < A[i])
            {
                smaller_found = true;
                smaller_array.push_back(num);
                break;
            }
            smaller_stack.pop();
        }
        if (!smaller_found)
            smaller_array.push_back(-1);
        smaller_stack.push(A[i]);
    }
    return smaller_array;
}

// Difficulty: Easy

