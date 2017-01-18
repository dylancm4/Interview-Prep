//
//  SetMatrixZeros.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
 
 Do it in place.
 
 Example
 
 Given array A as
 
 1 0 1
 1 1 1
 1 1 1
 On returning, the array A should be :
 
 0 0 0
 1 0 1
 1 0 1
 Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
 */

void Solution::setZeroes(vector<vector<int> > &A)
{
    int num_rows = A.size();
    int num_columns = A.front().size();
    vector<unsigned char> shouldZeroRow(num_rows);
    for (int r = 0; r < num_rows; r++)
    {
        shouldZeroRow[r] = 0;
        for (int c = 0; c < num_columns; c++)
        {
            if (A[r][c] == 0)
                shouldZeroRow[r] = 1;
        }
    }
    vector<unsigned char> shouldZeroColumn(num_columns);
    for (int c = 0; c < num_columns; c++)
    {
        shouldZeroColumn[c] = 0;
        for (int r = 0; r < num_rows; r++)
        {
            if (A[r][c] == 0)
                shouldZeroColumn[c] = 1;
        }
    }
    
    for (int r = 0; r < num_rows; r++)
    {
        if (shouldZeroRow[r])
        {
            for (int c = 0; c < num_columns; c++)
            {
                A[r][c] = 0;
            }
        }
    }
    for (int c = 0; c < num_columns; c++)
    {
        if (shouldZeroColumn[c])
        {
            for (int r = 0; r < num_rows; r++)
            {
                A[r][c] = 0;
            }
        }
    }
}
