//
//  ReverseLinkedListII.cpp
//  
//
//  Created by Dylan Miller on 1/28/17.
//
//

/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list. Note 2:
 Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseBetween(ListNode* A, int m, int n)
{
    // Save pointer to node before reversed sequence, if any.
    int index = 1;
    ListNode* cur_node = A;
    ListNode* node_before_reversal;
    if (m > 1)
    {
        while (index < m - 1)
        {
            cur_node = cur_node->next;
            index++;
        }
        node_before_reversal = cur_node;
        
        // Move to reversed sequence.
        cur_node = cur_node->next;
        index++;
    }
    else
        node_before_reversal = NULL;
    
    // Save pointer to last node of reversed sequence.
    ListNode* last_reversed_node = cur_node;
    
    // Reverse the sequence.
    ListNode* prev_node = NULL;
    ListNode* next_node;
    while (index <= n)
    {
        next_node = cur_node->next;
        cur_node->next = prev_node;
        prev_node = cur_node;
        cur_node = next_node;
        index++;
    }
    
    // Save pointer to first node of reversed sequence.
    ListNode* first_reversed_node = prev_node;
    
    // Save pointer to node after reversed sequence.
    ListNode* node_after_reversal = cur_node;
    
    // Insert the reversed sequence into the list.
    ListNode* head;
    if (node_before_reversal)
    {
        node_before_reversal->next = first_reversed_node;
        head = A;
    }
    else
        head = first_reversed_node;
    last_reversed_node->next = node_after_reversal;
    
    return head;
}

// Difficulty: Straightforward, but more medium than easy.
