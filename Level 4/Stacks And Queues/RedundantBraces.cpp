//
//  RedundantBraces.cpp
//  
//
//  Created by Dylan Miller on 2/19/17.
//
//

/*
 Write a program to validate if the input string has redundant braces?
 Return 0/1
 0 -> NO 1 -> YES
 
 Input will be always a valid expression
 
 and operators allowed are only + , * , - , /
 
 Example:
 
 ((a + b)) has redundant braces so answer will be 1
 (a + (a + b)) doesn't have have any redundant braces so answer will be 0
 */

int Solution::braces(string A)
{
    stack<bool> bracesStack;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
            bracesStack.push(false);
        else if (A[i] == ')')
        {
            if (!bracesStack.top())
                return 1;
            bracesStack.pop();
        }
        else if (!bracesStack.empty() && (A[i] == '+' || A[i] == '*' || A[i] == '-' || A[i] == '/'))
            bracesStack.top() = true;
    }
    return 0;
}

// Difficulty: Easy
