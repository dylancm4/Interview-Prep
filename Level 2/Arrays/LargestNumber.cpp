//
//  LargestNumber.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example:
 
 Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */

int compare(int a, int b)
{
    char a_string[16];
    char b_string[16];
    int num_digits_a = sprintf(a_string, "%d", a);
    int num_digits_b = sprintf(b_string, "%d", b);
    double ab = a * pow(10, num_digits_b) + b;
    double ba = b * pow(10, num_digits_a) + a;
    if (ab < ba)
        return 1;
    else if (ab > ba)
        return -1;
    else
        return 0;
    
}

int partition(vector<int> &A, int start, int end)
{
    int pivot = A[end];
    int partition_index = start;
    for (int i = start; i < end; i++)
    {
        if (compare(A[i], pivot) <= 0)
        {
            std::swap(A[i], A[partition_index]);
            partition_index++;
        }
    }
    std::swap(A[partition_index], A[end]);
    return partition_index;
}

void quickSort(vector<int> &A, int start, int end)
{
    if (start < end)
    {
        int partition_index = partition(A, start, end);
        quickSort(A, start, partition_index - 1);
        quickSort(A, partition_index + 1, end);
    }
}

string Solution::largestNumber(const vector<int> &A)
{
    vector<int> B = A;
    quickSort(B, 0, B.size()-1);
    string largest_num_string;
    int num_numbers = B.size();
    for (int i = 0; i < num_numbers; i++)
    {
        int num = B[i];
        if (num || largest_num_string.size())
        {
            char num_string[16];
            sprintf(num_string, "%d", B[i]);
            largest_num_string += num_string;
        }
    }
    return largest_num_string.size() ? largest_num_string : "0";
}
