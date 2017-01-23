//
//  KthRowOfPascalsTriangle.cpp
//  
//
//  Created by Dylan Miller on 1/22/17.
//
//

/*
 Given an index k, return the kth row of the Pascal’s triangle.
 
 Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
 
 Example:
 
 Input : k = 3
 
 Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1].
 Note:Could you optimize your algorithm to use only O(k) extra space?
 */

/*
 1
 1  1
 1  2  1
 1  3  3  1
 1  4  6  4  1
 1  5 10 10  5  1
 */

vector<int> Solution::getRow(int A)
{
    int num_rows = A + 1;
    vector<int> row(num_rows, 0);
    for (int i = 0; i < num_rows; i++)
    {
        int prev_row_left = i ? 0 : 1;
        for (int j = 0; j <= i; j++)
        {
            int row_j = row[j];
            row[j] += prev_row_left;
            prev_row_left = row_j;
        }
    }
    return row;
}

// Difficulty: Medium

