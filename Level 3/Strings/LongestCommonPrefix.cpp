//
//  LongestCommonPrefix.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Write a function to find the longest common prefix string amongst an array of strings.
 
 Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
 
 As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
 
 Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
 
 Example:
 
 Given the array as:
 
 [
 
 "abcdefgh",
 
 "aefghijk",
 
 "abcefgh"
 ]
 The answer would be “a”.
 */

string Solution::longestCommonPrefix(vector<string> &A)
{
    string prefix;
    
    if (A.size() == 0)
        return prefix;
    else if (A.size() == 1)
        return A[0];
    
    int min_len = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].length() < min_len)
            min_len = A[i].length();
    }
    
    for (int i = 0; i < min_len; i++)
    {
        string& s0 = A[0];
        char character = s0[i];
        bool is_equal = true;
        for (int j = 1; j < A.size(); j++)
        {
            string& sj = A[j];
            if (sj[i] != character)
            {
                is_equal = false;
                break;
            }
        }
        
        if (is_equal)
            prefix.push_back(character);
        else
            break;
    }
    
    return prefix;
}

// Difficulty: Easy
