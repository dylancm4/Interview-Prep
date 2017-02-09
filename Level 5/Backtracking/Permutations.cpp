//
//  Permutations.cpp
//  
//
//  Created by Dylan Miller on 2/8/17.
//
//

/*
 Given a collection of numbers, return all possible permutations.
 
 Example:
 
 [1,2,3] will have the following permutations:
 
 [1,2,3]
 [1,3,2]
 [2,1,3]
 [2,3,1]
 [3,1,2]
 [3,2,1]
 
 NOTE
 No two entries in the permutation sequence should be the same.
 For the purpose of this problem, assume that all the numbers in the collection are unique.
 
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
 Example : next_permutations in C++ / itertools.permutations in python.
 If you do, we will disqualify your submission retroactively and give you penalty points.
 */

void permute(vector<vector<int>>& permutations, vector<int>& permutation, set<int>& numbers)
{
    if (!numbers.size())
    {
        permutations.push_back(permutation);
        return;
    }
    
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        int number = *it;
        
        vector<int> p = permutation;
        p.push_back(number);
        
        set<int> n = numbers;
        n.erase(number);
        
        permute(permutations, p, n);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> permutations;
    vector<int> permutation;
    set<int> numbers(A.begin(), A.end());
    ::permute(permutations, permutation, numbers);
    return permutations;
}

// Difficulty: Easy, because it was so similar to the solution for the hard problem Combinations.
