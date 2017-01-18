//
//  GreatestCommonDivisor.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given 2 non negative integers m and n, find gcd(m, n)
 
 GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
 Both m and n fit in a 32 bit signed integer.
 
 Example
 
 m : 6
 n : 9
 
 GCD(m, n) : 3
 NOTE : DO NOT USE LIBRARY FUNCTIONS
 */

vector<int> getAllFactors(int A)
{
    vector<int> factors;
    double a_sqrt = sqrt(A);
    for (int i = 1, j = 0; i <= int(a_sqrt); i++)
    {
        if (A % i == 0)
        {
            factors.push_back(i);
            if (i != a_sqrt)
                factors.push_back(A/i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

int Solution::gcd(int A, int B)
{
    if (A == 0)
        return B;
    if (B == 0)
        return A;
    
    vector<int> a_factors = getAllFactors(A);
    vector<int> b_factors = getAllFactors(B);
    int a_factors_size = a_factors.size();
    for (int i = a_factors_size-1; i >= 0; i--)
    {
        vector<int>::iterator it = find(b_factors.begin(), b_factors.end(), a_factors[i]);
        if (it != b_factors.end())
            return a_factors[i];
    }
    return 0;
}
