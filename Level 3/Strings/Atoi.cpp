//
//  Atoi.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Please Note:
 
 There are certain questions where the interviewer would intentionally frame the question vague.
 The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.
 
 Implement atoi to convert a string to an integer.
 
 Example :
 
 Input : "9 2704"
 Output : 9
 Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.
 
 Questions: Q1. Does string contain whitespace characters before the number?
 A. Yes Q2. Can the string have garbage characters after the number?
 A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
 A. Return 0. Q4. What if the integer overflows?
 A. Return INT_MAX if the number is positive, INT_MIN otherwise.
 Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
 If you do, we will disqualify your submission retroactively and give you penalty points.
 */

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool getNumberBounds(const string &A, int& start_index, int& end_index, bool& is_negative)
{
    enum {STATE_WHITESPACE, STATE_SIGN, STATE_DIGIT} state = STATE_WHITESPACE;
    for (int i = 0; i < A.length(); i++)
    {
        switch (state)
        {
            case STATE_WHITESPACE:
            {
                if (A[i] == '-')
                {
                    is_negative = true;
                    state = STATE_SIGN;
                }
                else if (A[i] == '+')
                {
                    is_negative = false;
                    state = STATE_SIGN;
                }
                else if (isDigit(A[i]))
                {
                    is_negative = false;
                    start_index = end_index = i;
                    state = STATE_DIGIT;
                }
                else if (A[i] != ' ') // garbage before number
                    return false;
                break;
            }
            case STATE_SIGN:
            {
                if (isDigit(A[i]))
                {
                    start_index = end_index = i;
                    state = STATE_DIGIT;
                }
                else
                    return false;
                break;
            }
            case STATE_DIGIT:
            {
                if (isDigit(A[i]))
                    end_index = i;
                else
                    return true;
                break;
            }
        }
    }
    return state == STATE_DIGIT;
}


int aDigitsToI(const string &A, int start_index, int end_index, bool is_negative)
{
    long long number = 0;
    for (int i = start_index; i <= end_index; i++)
    {
        number = number * 10 + A[i] - '0';
        
        // Check for overflow.
        if (!is_negative && number > INT_MAX)
            return INT_MAX;
        else if (is_negative && -number < INT_MIN)
            return INT_MIN;
    }
    return int(is_negative ? -number : number);
}

int Solution::atoi(const string &A)
{
    int start_index;
    int end_index;
    bool is_negative;
    if (getNumberBounds(A, start_index, end_index, is_negative))
        return aDigitsToI(A, start_index, end_index, is_negative);
    return 0;
}

// Difficulty: Easy
