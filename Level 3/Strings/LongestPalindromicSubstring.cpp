//
//  LongestPalindromicSubstring.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a string S, find the longest palindromic substring in S.
 
 Substring of string S:
 
 S[i...j] where 0 <= i <= j < len(S)
 
 Palindrome string:
 
 A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
 
 Incase of conflict, return the substring which occurs first ( with the least starting index ).
 
 Example :
 
 Input : "aaaabaaa"
 Output : "aaabaaa"
 */

string Solution::longestPalindrome(string A)
{
    // Against my better judgment to use long long rather than int
    // throughout this function, but the interviewbit testing was using
    // huge test strings that made this necessary.
    long long a_size = A.size();
    if (a_size < 2)
        return A;
    
    vector<vector<bool>> pal_table(a_size, vector<bool>(a_size, false));
    
    long long longest_start_index = 0;
    long long longest_length = 1;
    
    // Populate table for one-letter palindromes.
    for (long long i = 0; i < a_size; i++)
    {
        pal_table[i][i] = true;
    }
    
    // Find two-letter palindromes.
    for (long long i = 0; i < a_size-1; i++)
    {
        if (A[i] == A[i+1])
        {
            pal_table[i][i+1] = true;
            if (longest_length < 2)
            {
                longest_start_index = i;
                longest_length = 2;
            }
        }
    }
    
    // Find palindromes with three or more letters.
    for (long long pal_length = 3; pal_length <= a_size; pal_length++)
    {
        for (long long i = 0; i < a_size-pal_length+1; i++)
        {
            // Compare first and last characters and use the pal_table
            // to compare the characters that come in between.
            long long j = i + pal_length - 1;
            if (A[i] == A[j] && pal_table[i+1][j-1])
            {
                pal_table[i][j] = true;
                if (longest_length < pal_length)
                {
                    longest_start_index = i;
                    longest_length = pal_length;
                }
            }
        }
    }
    
    return A.substr(longest_start_index, longest_length);
}
