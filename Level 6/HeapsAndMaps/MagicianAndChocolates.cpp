//
//  MagicianAndChocolates.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.
 
 Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.
 
 For example,
 
 K = 3
 N = 2
 A = 6 5
 
 Return: 14
 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
 so, total number of chocolates eaten: 6 + 5 + 3 = 14
 
 Note: Return your answer modulo 10^9+7
 */

int Solution::nchoc(int A, vector<int> &B)
{
    // Create a multiset to tracks the bags of chocolates.
    multiset<int> bag_set(B.begin(), B.end());
    
    int total_chocolates = 0;
    for (int i = 0; i < A && bag_set.size(); i++)
    {
        // Find the bag with the most chocolates and remove it from bag_set.
        multiset<int>::iterator it = bag_set.end();
        it--;
        int chocolates = *it;
        bag_set.erase(it);
        
        // Add a bag with half of those chocolates back to bag_set.
        int half_chocolates = chocolates / 2;
        if (half_chocolates)
            bag_set.insert(half_chocolates);
        
        // Prevent overflow using technique from problem description.
        while (chocolates > 1000000007 - total_chocolates)
            chocolates -= 1000000007;
        
        // Increment the total number of chocolates.
        total_chocolates += chocolates;
    }
    
    return total_chocolates;
}

// Difficulty: Easy
