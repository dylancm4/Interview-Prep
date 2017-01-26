//
//  RotateList.cpp
//  
//
//  Created by Dylan Miller on 1/23/17.
//
//

/*
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::rotateRight(ListNode* A, int B)
{
    // Determine the number of nodes.
    int num_nodes = 0;
    for (ListNode* node = A; node; node = node->next)
        num_nodes++;
    
    // Make B < num_nodes.
    B %= num_nodes;
    
    // Edge cases.
    if (!B || num_nodes < 2)
        return A;
    
    // Get pointer to node before node to rotate.
    int rotate_after_index = num_nodes - B - 1;
    ListNode* node = A;
    for (int i = 0; i < rotate_after_index; i++)
        node = node->next;
    
    // Perform rotation.
    ListNode* head = node->next;
    ListNode* tail = node;
    while (node->next)
        node = node->next;
    node->next = A;
    tail->next = NULL;
    
    return head;
}

// Difficulty: Easy

