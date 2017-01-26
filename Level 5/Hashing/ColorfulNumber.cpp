//
//  ColorfulNumber.cpp
//  
//
//  Created by Dylan Miller on 1/24/17.
//
//

/*
 For Given Number N find if its COLORFUL number or not
 
 Return 0/1
 
 COLORFUL number:
 
 A number can be broken into different contiguous sub-subsequence parts.
 Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245.
 And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
 Example:
 
 N = 23
 2 3 23
 2 -> 2
 3 -> 3
 23 -> 6
 this number is a COLORFUL number since product of every digit of a sub-sequence are different.
 
 Output : 1
 */

// Example:
// 123456
// 1 12 123 1234 12345 123456
// 2 23 234 2345 23456
// 3 34 345 3456
// 4 45 456
// 5 56
// 6

int Solution::colorful(int A)
{
    if (A < 0)
        A = -A;
    
    // Convert A to a vector of integers.
    vector<int> num_vector;
    for (int i = A; i; i /= 10)
        num_vector.push_back(i % 10);
    reverse(num_vector.begin(), num_vector.end());
    
    // Use an unordered_map to determine if a duplicate exists of
    // the product of the digits in a subsequence.
    unordered_map<int, int> color_map;
    for (int i = 0; i < num_vector.size(); i++)
    {
        int product = 1;
        for (int j = i; j < num_vector.size(); j++)
        {
            product *= num_vector[j];
            if (color_map.find(product) != color_map.end())
                return 0;
            color_map[product] = 1;
        }
    }
    
    return 1;
}
