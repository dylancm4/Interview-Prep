//
//  SquareRootOfInteger.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Implement int sqrt(int x).
 
 Compute and return the square root of x.
 
 If x is not a perfect square, return floor(sqrt(x))
 
 Example :
 
 Input : 11
 Output : 3
 DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
 */

long long squared(long long x)
{
    return x * x;
}

int Solution::sqrt(int A)
{
    int low = 0;
    int high = A / 2 + 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        long long mid_squared = squared(mid);
        if (mid_squared == A)
            return mid;
        else if (A < mid_squared)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return squared(mid) < A ? mid : mid - 1; // floor(sqrt(x))
}
