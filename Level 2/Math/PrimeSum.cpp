//
//  PrimeSum.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
 
 NOTE A solution will always exist. read Goldbach’s conjecture
 
 Example:
 
 
 Input : 4
 Output: 2 + 2 = 4
 
 If there are more than one solutions possible, return the lexicographically smaller solution.
 
 If [a, b] is one solution with a <= b,
 and [c,d] is another solution with c <= d, then
 
 [a, b] < [c, d]
 
 If a < c OR a==c AND b < d.
 */

vector<int> getPrimes(int A)
{
    vector<unsigned char> is_prime(A+1);
    for (int i = 0; i <= A; i++)
        is_prime[i] = 1;
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i <= sqrt(A); i++)
    {
        if (is_prime[i] == 1)
        {
            for (int j = 2; i * j <= A; j++)
                is_prime[i*j] = 0;
        }
    }
    
    vector<int> primes;
    for (int i = 0; i <= A; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

vector<int> Solution::primesum(int A)
{
    vector<int> primes = getPrimes(A);
    int num_primes = primes.size();
    for (int i = 0; i < num_primes; i++)
    {
        for (int j = i; j < num_primes; j++)
        {
            if (primes[i] + primes[j] == A)
            {
                vector<int> result;
                result.push_back(primes[i]);
                result.push_back(primes[j]);
                return result;
            }
        }
    }
}
