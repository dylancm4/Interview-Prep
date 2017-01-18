//
//  Subtract.cpp
//  
//
//  Created by Dylan Miller on 1/17/17.
//
//

/*
 Given a singly linked list, modify the value of first half nodes such that :
 
 1st node’s new value = the last node’s value - first node’s current value
 2nd node’s new value = the second last node’s value - 2nd node’s current value,
 and so on …
 
 NOTE :
 * If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes. So, if L = 5, the first half refers to first 2 nodes.
 * If the length L of linked list is even, then the first half implies at first L/2 nodes. So, if L = 4, the first half refers to first 2 nodes.
 Example :
 
 Given linked list 1 -> 2 -> 3 -> 4 -> 5,
 
 You should return 4 -> 2 -> 3 -> 4 -> 5
 as
 
 for first node, 5 - 1 = 4
 for second node, 4 - 2 = 2
 Try to solve the problem using constant extra space.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* A)
{
    ListNode* reversed_next = NULL;
    ListNode* node = A;
    while (node)
    {
        ListNode* next_node = node->next;
        node->next = reversed_next;
        reversed_next = node;
        node = next_node;
    }
    return reversed_next;
}

ListNode* Solution::subtract(ListNode* A)
{
    // Get list size.
    int size = 0;
    for (ListNode* first = A; first; first = first->next)
        size++;
    
    // Split list in half.
    int second_half_start_index = (size&1) ? ((size >> 1) + 1) : (size >> 1);
    ListNode* second_half = A;
    for(int i = 0; i < second_half_start_index; i++)
        second_half = second_half->next;
    
    // Reverse the second half.
    ListNode* second_half_reversed = reverseList(second_half);
    
    // Perform subtractions.
    for (ListNode* first = A, *second = second_half_reversed;
         second;
         first = first->next, second = second->next)
    {
        first->val = second->val - first->val;
    }
    
    // Un-reverse the second half.
    reverseList(second_half_reversed);
    
    return A;
}
