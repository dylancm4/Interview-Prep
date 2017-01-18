//
//  ImplementPowerFunction.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Implement pow(x, n) % d.
 
 In other words, given x, n and d,
 
 find (xn % d)
 
 Note that remainders on division cannot be negative.
 In other words, make sure the answer you return is non negative.
 
 Input : x = 2, n = 3, d = 3
 Output : 2
 
 2^3 % 3 = 8 % 3 = 2.
 */

int Solution::pow(int x, int n, int d)
{
    if (n == 0)
        return x ? 1 : 0;
    
    long long _x = x % d;
    long long result = 1;
    for (int power = n; power; power >>= 1)
    {
        // Use % operator to remove the part of result and _x
        // which is divisible by d.
        if (power & 1)
            result = (result * _x) % d;
        _x = (_x * _x) % d;
    }
    
    if (result < 0)
        result += d;
    
    return int(result);
}
