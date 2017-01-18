//
//  ImplementStrStr.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Please Note:
 
 Another question which belongs to the category of questions which are intentionally stated vaguely.
 Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.
 
 Implement strStr().
 
 strstr - locate a substring ( needle ) in a string ( haystack ).
 Try not to use standard library string functions for this question.
 
 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 NOTE: Good clarification questions:
 What should be the return value if the needle is empty?
 What if both haystack and needle are empty?
 For the purpose of this problem, assume that the return value should be -1 in both cases.
 */

int Solution::strStr(const string &haystack, const string &needle)
{
    int haystack_len = haystack.length();
    int needle_len = needle.length();
    for (int i = 0; i < haystack_len; i++)
    {
        int matched_chars = 0;
        for (int j = 0; j < needle_len && i+j < haystack_len; j++)
        {
            if (needle[j] == haystack[i+j])
                matched_chars++;
        }
        if (matched_chars == needle_len)
            return i;
    }
    return -1;
}
