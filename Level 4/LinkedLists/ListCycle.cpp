//
//  ListCycle.cpp
//  
//
//  Created by Dylan Miller on 1/28/17.
//
//

/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Try solving it using constant additional space.
 
 Example :
 
 Input :
 
 ______
 |     |
 \/    |
 1 -> 2 -> 3 -> 4
 
 Return the node corresponding to node 3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::detectCycle(ListNode* A)
{
    set<ListNode*> node_set;
    for (ListNode* node = A; node; node = node->next)
    {
        if (node_set.find(node) != node_set.end())
            return node;
        node_set.insert(node);
    }
    return NULL;
}

// Difficulty: Easy, but my solution was not the intended one. I worked through the Hard intended solution with a CodePath mentee. First you detect if there is a cycle using fast and slow pointers, then you detect the length of the cycle (k), then you detect where the cycle begins using two pointers, one starting at head and the other starting at the kth node from head.
