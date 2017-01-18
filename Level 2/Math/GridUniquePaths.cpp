//
//  GridUniquePaths.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
 
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
 
 How many possible unique paths are there?
 
 Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
 
 Example :
 
 Input : A = 2, B = 2
 Output : 2
 
 2 possible routes : (0, 0) -> (0, 1) -> (1, 1)
 OR  : (0, 0) -> (1, 0) -> (1, 1)
 */

int Solution::uniquePaths(int A, int B)
{
    if (A == 1)
        return 1;
    else if (B == 1)
        return 1;
    else
        return uniquePaths(A-1, B) + uniquePaths(A, B-1);
}
