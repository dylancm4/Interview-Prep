//
//  LongestSubstringWithoutRepeat.cpp
//  
//
//  Created by Dylan Miller on 1/28/17.
//
//

/*
 Given a string,
 find the length of the longest substring without repeating characters.
 
 Example:
 
 The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 
 For "bbbbb" the longest substring is "b", with the length of 1.
 */

/*
 abcabcbb
 bcabcbb b bc bca bcab bcabc bcabcb bcabcbb
 cabcbb
 abcbb
 bcbb
 cbb
 bb
 b
 
 0123456789bqwertyb0123456789abcd
 */

int Solution::lengthOfLongestSubstring(string A)
{
    if (!A.size())
        return 0;
    int longest_substring = 1;
    for (int i = 0; i < A.length();)
    {
        if (longest_substring >= A.length() - i) // can't be a larger substring
            break;
        
        int length = 0;
        bool repeat_found = false;
        unordered_set<char> char_set;
        for (int j = i; j < A.length(); j++)
        {
            if (char_set.find(A[j]) != char_set.end())
            {
                repeat_found = true;
                
                // Move i past the repeated character.
                while (A[i] != A[j])
                    i++;
                i++;
                
                break;
            }
            char_set.insert(A[j]);
            length++;
        }
        if (longest_substring < length)
            longest_substring = length;
        
        if (!repeat_found)
            break;
    }
    return longest_substring;
}

// Difficulty: Medium, to create algorithm which was efficient enough to pass, and my final code is a bit sloppy.
