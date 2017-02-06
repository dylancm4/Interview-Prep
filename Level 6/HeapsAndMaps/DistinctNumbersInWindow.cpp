//
//  DistinctNumbersInWindow.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.
 
 Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
 
 Note:
 - If K > N, return empty array.
 
 For example,
 
 A=[1, 2, 1, 3, 4, 3] and K = 3
 
 All windows of size K are
 
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 
 So, we return an array [2, 3, 3, 2].
 */

void addNumToMap(map<int,int>& num_map, int num)
{
    map<int,int>::iterator it = num_map.find(num);
    if (it != num_map.end())
        it->second++;
    else
        num_map[num] = 1;
}

void removeNumFromMap(map<int,int>& num_map, int num)
{
    map<int,int>::iterator it = num_map.find(num);
    if (it != num_map.end())
    {
        it->second--;
        if (!it->second)
            num_map.erase(it);
    }
}

vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int> distinct_num_counts;
    if (B > A.size())
        return distinct_num_counts;
    
    map<int,int> num_map;
    for (int i = 0; i < B-1; i++)
        addNumToMap(num_map, A[i]);
    
    for (int i = B-1; i < A.size(); i++)
    {
        addNumToMap(num_map, A[i]);
        distinct_num_counts.push_back(num_map.size());
        removeNumFromMap(num_map, A[i-B+1]);
    }
    
    return distinct_num_counts;
}

// Difficulty: Easy, though my initial solution used std::set and did not pass efficiency check.

