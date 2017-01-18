//
//  MatrixSearch.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Write an efficient algorithm that searches for a value in an m x n matrix.
 
 This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than or equal to the last integer of the previous row.
 Example:
 
 Consider the following matrix:
 
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return 1 ( 1 corresponds to true )
 
 Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
 */

int getMatrixSize(vector<vector<int> > &A)
{
    return A.size() * A.front().size();
}

int getMatrixElement(vector<vector<int> > &A, int offset)
{
    int num_columns = A.front().size();
    int row = offset / num_columns;
    int column = offset % num_columns;
    return A[row][column];
}

int Solution::searchMatrix(vector<vector<int> > &A, int B)
{
    int low = 0;
    int high = getMatrixSize(A) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int a_mid = getMatrixElement(A, mid);
        if (a_mid == B)
            return 1;
        else if (B < a_mid)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
