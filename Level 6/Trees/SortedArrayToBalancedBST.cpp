//
//  SortedArrayToBalancedBST.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 
 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 Example :
 
 
 Given A : [1, 2, 3]
 A height balanced BST  :
 
 2
 /   \
 1     3
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

TreeNode* sortedArrayToBST(const vector<int>& A, int start_index, int len)
{
    int middle_index = start_index + len / 2;
    TreeNode* tree_node = new TreeNode(A[middle_index]);
    int left_len = middle_index-start_index;
    int right_len = len-left_len-1;
    tree_node->left = left_len > 0 ? sortedArrayToBST(A, start_index, left_len) : NULL;
    tree_node->right = right_len > 0 ? sortedArrayToBST(A, middle_index+1, right_len) : NULL;
    
    return tree_node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A)
{
    return ::sortedArrayToBST(A, 0, A.size());
}

// Difficulty: Easy, though I should review the technique of finding the root by going to the middle of the sorted array.

