//
//  AddOneToNumber.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Given a non-negative number represented as an array of digits,
 
 add 1 to the number ( increment the number represented by the digits ).
 
 The digits are stored such that the most significant digit is at the head of the list.
 
 Example:
 
 If the vector has [1, 2, 3]
 
 the returned vector should be [1, 2, 4]
 
 as 123 + 1 = 124.
 
 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
 For example, for this problem, following are some good questions to ask :
 Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
 A : For the purpose of this question, YES
 Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
 A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
 */

vector<int> Solution::plusOne(vector<int> &A)
{
    vector<int> B;
    
    // Converted to reversed array, adding one.
    int carry = 1; // this is the initial plus one
    for (int i = A.size()-1; i >= 0; i--)
    {
        int digit = A[i] + carry;
        if (digit >= 10)
        {
            digit -= 10;
            carry = 1;
        }
        else
            carry = 0;
        B.push_back(digit);
    }
    if (carry)
        B.push_back(carry);
    
    // Remove trailing zeros from reversed array.
    for (int i = B.size()-1; i >= 0 && B[i] == 0; i--)
        B.pop_back();
    
    // Un-reverse the array.
    reverse(B.begin(), B.end());
    
    return B;
}

// Difficulty: Medium

