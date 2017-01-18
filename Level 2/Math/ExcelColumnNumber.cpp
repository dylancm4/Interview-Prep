//
//  ExcelColumnNumber.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a column title as appears in an Excel sheet, return its corresponding column number.
 
 Example:
 
 A -> 1
 
 B -> 2
 
 C -> 3
 
 ...
 
 Z -> 26
 
 AA -> 27
 
 AB -> 28
 */

int Solution::titleToNumber(string A)
{
    int number = 0;
    int a_length = A.length();
    for (int i = 0; i < a_length; i++)
    {
        int num = A[i] - 'A' + 1;
        number = number * 26 + num;
    }
    return number;
}
