//
//  RomanToInteger.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 
 Read more details about roman numerals at Roman Numeric System
 
 Example :
 
 Input : "XIV"
 Return : 14
 Input : "XX"
 Output : 20
 */

int Solution::romanToInt(string A)
{
    // Symbol   I   V   X	L	C	D	M
    // Value    1   5   10  50  100 500	1000
    
    // Notation	IV	IX	XL	XC	CD	CM
    // Number	4	9	40	90	400	900
    
    map<char, int> roman_map;
    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;
    
    int number = 0;
    char last_char = 0;
    int a_size = A.size();
    for (int i = 0; i < a_size; i++)
    {
        char this_char = A[i];
        if (last_char == 'I' && this_char == 'V')
        {
            number += 4 - 1;
            last_char = 0;
        }
        else if (last_char == 'I' && this_char == 'X')
        {
            number += 9 - 1;
            last_char = 0;
        }
        else if (last_char == 'X' && this_char == 'L')
        {
            number += 40 - 10;
            last_char = 0;
        }
        else if (last_char == 'X' && this_char == 'C')
        {
            number += 90 - 10;
            last_char = 0;
        }
        else if (last_char == 'C' && this_char == 'D')
        {
            number += 400 - 100;
            last_char = 0;
        }
        else if (last_char == 'C' && this_char == 'M')
        {
            number += 900 - 100;
            last_char = 0;
        }
        else
        {
            number += roman_map[A[i]];
            last_char = this_char;
        }
    }
    return number;
}
