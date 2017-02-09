//
//  Combinations.cpp
//  
//
//  Created by Dylan Miller on 2/8/17.
//
//

/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
 
 Make sure the combinations are sorted.
 
 To elaborate,
 1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
 2. Entries should be sorted within themselves.
 
 Example :
 If n = 4 and k = 2, a solution is:
 
 [
 [1,2],
 [1,3],
 [1,4],
 [2,3],
 [2,4],
 [3,4],
 ]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
 Example : itertools.combinations in python.
 If you do, we will disqualify your submission retroactively and give you penalty points.
 */

void combine(vector<vector<int>>& combinations, vector<int>& combination, int start, int end, int count)
{
    for (int i = start; i <= end-count+1; i++)
    {
        vector<int> combo = combination;
        combo.push_back(i);
        if (count == 1)
            combinations.push_back(combo);
        else
            combine(combinations, combo, i+1, end, count-1);
    }
}

vector<vector<int> > Solution::combine(int n, int k)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    ::combine(combinations, combination, 1, n, k);
    return combinations;
}

// Difficulty: Hard. My solution ended up being fairly simple, but it took me a long time to wrap my head around how to use recursion for this, especially because it required copying vectors by value. My solution seems cleaner than the example solution, which I didn't attempt to understand.

/*
 1 2 3 4 5 6 7
 
 123
 124
 125
 126
 127
 
 134
 135
 136
 137
 
 145
 146
 147
 
 156
 157
 
 167
 
 234
 235
 236
 237
 
 245
 246
 247
 
 256
 257
 
 267
 
 345
 346
 347
 
 356
 357
 
 367
 
 456
 457
 
 467
 
 567
 */

