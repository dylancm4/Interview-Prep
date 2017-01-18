//
//  PalindromeString.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 Example:
 
 "A man, a plan, a canal: Panama" is a palindrome.
 
 "race a car" is not a palindrome.
 
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 */

int Solution::isPalindrome(string A)
{
    int a_size = A.size();
    for (int i = 0, j = a_size-1; i < j;)
    {
        char char_i = A[i];
        char char_j = A[j];
        int is_i_alnum = isalnum(char_i);
        int is_j_alnum = isalnum(char_j);
        if (!is_i_alnum && !is_j_alnum)
        {
            i++;
            j--;
            continue;
        }
        else if (!is_i_alnum)
        {
            i++;
            continue;
        }
        else if (!is_j_alnum)
        {
            j--;
            continue;
        }
        
        if (toupper(char_i) != toupper(char_j))
            return 0;
        
        i++;
        j--;
    }
    return 1;
}
