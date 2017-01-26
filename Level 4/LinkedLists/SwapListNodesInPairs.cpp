//
//  SwapListNodesInPairs.cpp
//  
//
//  Created by Dylan Miller on 1/23/17.
//
//

/*
 Given a linked list, swap every two adjacent nodes and return its head.
 
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::swapPairs(ListNode* A)
{
    ListNode* head = A;
    ListNode* prev = NULL;
    ListNode* after = NULL;
    for (ListNode* node = A; node && node->next; node = after)
    {
        ListNode* first = node;
        ListNode* second = first->next;
        after = second->next; // may be NULL
        
        // Node after previous node is second.
        if (!prev) // start of list
            head = second;
        else
            prev->next = second;
        
        // Node after second is first.
        second->next = first;
        
        // Node after first is node that was after second.
        first->next = after;
        
        // Previous node for next loop iteration is first.
        prev = first;
    }
    return head;
}

// Difficulty: Easy
