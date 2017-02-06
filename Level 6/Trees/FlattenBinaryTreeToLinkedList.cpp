//
//  FlattenBinaryTreeToLinkedList.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 Given a binary tree, flatten it to a linked list in-place.
 
 Example :
 Given
 
 
 1
 / \
 2   5
 / \   \
 3   4   6
 The flattened tree should look like:
 
 1
 \
 2
 \
 3
 \
 4
 \
 5
 \
 6
 Note that the left child of all nodes should be NULL.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::flatten(TreeNode* A)
{
    if (!A)
        return NULL;
    
    TreeNode* left_flat = flatten(A->left);
    TreeNode* right_flat = flatten(A->right);
    
    A->left = NULL;
    
    if (left_flat)
    {
        A->right = left_flat;
        
        TreeNode* last_left = left_flat;
        while (last_left->right)
            last_left = last_left->right;
        last_left->right = right_flat;
    }
    else
        A->right = right_flat;
    
    return A;
}

// Difficulty: Easy
