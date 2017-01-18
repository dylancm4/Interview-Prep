//
//  WaveArray.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given an array of integers, sort the array into a wave like array and return it,
 In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
 
 Example
 
 Given [1, 2, 3, 4]
 
 One possible answer : [2, 1, 4, 3]
 Another possible answer : [4, 1, 3, 2]
 
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
 So, in example case, you will return [2, 1, 4, 3]
 */

int partition(vector<int>& A, int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            std::swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }
    std::swap(A[partitionIndex], A[end]);
    return partitionIndex;
}

void quickSort(vector<int>& A, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(A, start, end);
        quickSort(A, start, partitionIndex-1);
        quickSort(A, partitionIndex+1, end);
    }
}

void quickSort(vector<int>& A)
{
    quickSort(A, 0, A.size()-1);
}

vector<int> Solution::wave(vector<int>& A)
{
    quickSort(A);
    int a_size = A.size();
    for (int i = 0; i < a_size-1; i+=2)
    {
        std::swap(A[i], A[i+1]);
    }
    return A;
}
