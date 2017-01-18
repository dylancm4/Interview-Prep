//
//  PalindromeInteger.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Determine whether an integer is a palindrome. Do this without extra space.
 
 A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
 Negative numbers are not palindromic.
 
 Example :
 
 Input : 12121
 Output : True
 
 Input : 123
 Output : False
 */

bool Solution::isPalindrome(int A)
{
    if (A < 0)
        return false;
    
    int num_digits = 0;
    for (int i = A; i; i /= 10)
        num_digits++;
    
    for (int i = 0; i < num_digits/2; i++)
    {
        int a = (A / int(pow(10, i))) % 10;
        int b = (A / int(pow(10, num_digits-i-1))) % 10;
        if (a != b)
            return false;
    }
    return true;
}
