//
//  ReverseTheString.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Given an input string, reverse the string word by word.
 
 Example:
 
 Given s = "the sky is blue",
 
 return "blue is sky the".
 
 A sequence of non-space characters constitutes a word.
 Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
 If there are multiple spaces between words, reduce them to a single space in the reversed string.
 */

void Solution::reverseWords(string &A)
{
    vector<string> words;
    string word;
    bool in_word = false;
    for (int i = 0; i < A.length(); i++)
    {
        if (!in_word)
        {
            if (A[i] != ' ')
            {
                word.push_back(A[i]);
                in_word = true;
            }
        }
        else // in_word
        {
            if (A[i] == ' ')
            {
                words.push_back(word);
                word.clear();
                in_word = false;
            }
            else
                word.push_back(A[i]);
        }
    }
    if (in_word)
        words.push_back(word);
    
    reverse(words.begin(), words.end());
    
    A.clear();
    for (int i = 0; i < words.size(); i++)
    {
        if (i)
            A.push_back(' ');
        A.append(words[i]);
    }
}

// Difficulty: Easy
