//
//  ZigZagString.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P.......A........H.......N
 ..A..P....L....S....I...I....G
 ....Y.........I........R
 And then read line by line: PAHNAPLSIIGYIR
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
 **Example 2 : **
 ABCD, 2 can be written as
 
 A....C
 ...B....D
 and hence the answer would be ACBD.
 */

string Solution::convert(string A, int B)
{
    if (B < 2)
        return A;
    
    string result;
    int increment = (B - 1) * 2;
    for (int row = 0; row < B; row++)
    {
        int increment1 = increment - 2*row;
        int increment2 = 2*row;
        if (!increment1)
            increment1 = increment2;
        if (!increment2)
            increment2 = increment1;
        
        for (int i = row, j = 0; i < A.size(); j++)
        {
            result.push_back(A[i]);
            i += (j&1) ? increment2 : increment1;
        }
    }
    return result;
}
