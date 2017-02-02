//
//  BalancedBinaryTree.cpp
//  
//
//  Created by Dylan Miller on 2/2/17.
//
//

/*
 Given a binary tree, determine if it is height-balanced.
 
 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 
 Example :
 
 Input :
 1
 / \
 2   3
 
 Return : True or 1
 
 Input 2 :
 3
 /
 2
 /
 1
 
 Return : False or 0
 Because for the root node, left subtree has depth 2 and right subtree has depth 0.
 Difference = 2 > 1.
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

int getDepth(TreeNode* A)
{
    if (!A)
        return 0;
    else
        return 1 + max(getDepth(A->left), getDepth(A->right));
}

int Solution::isBalanced(TreeNode* A)
{
    if (!A)
        return true;
    
    bool a_is_balanced = abs(getDepth(A->left) - getDepth(A->right)) <= 1;
    if (a_is_balanced)
        return isBalanced(A->left) && isBalanced(A->right);
    else
        return false;
}

// Difficulty: Easy
