//
//  AddBinaryStrings.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Given two binary strings, return their sum (also a binary string).
 
 Example:
 
 a = "100"
 
 b = "11"
 Return a + b = “111”.
 */

string Solution::addBinary(string A, string B)
{
    string sum_string;
    int carry = 0;
    for (int i = A.size()-1, j = B.size()-1; i >= 0 || j >= 0; i--, j--)
    {
        int a_digit = i >= 0 ? (A[i] - '0') : 0;
        int b_digit = j >= 0 ? (B[j] - '0') : 0;
        int digit_sum = a_digit + b_digit + carry;
        if (digit_sum > 1)
        {
            digit_sum -= 2;
            carry = 1;
        }
        else
            carry = 0;
        
        sum_string.push_back(digit_sum + '0');
    }
    if (carry)
        sum_string.push_back('1');
    
    reverse(sum_string.begin(), sum_string.end());
    
    return sum_string;
}

// Difficulty: Easy
