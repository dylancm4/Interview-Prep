//
//  PreorderTraversal.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 Given a binary tree, return the preorder traversal of its nodes’ values.
 
 Example :
 Given binary tree
 
 1
 \
 2
 /
 3
 return [1,2,3].
 
 Using recursion is not allowed.
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

vector<int> Solution::preorderTraversal(TreeNode* A)
{
    vector<int> preorder_vector;
    stack<TreeNode*> right_node_stack;
    TreeNode* node = A;
    while (node)
    {
        preorder_vector.push_back(node->val);
        if (node->right)
            right_node_stack.push(node->right);
        
        if (node->left)
            node = node->left;
        else if (!right_node_stack.empty())
        {
            node = right_node_stack.top();
            right_node_stack.pop();
        }
        else
            node = NULL;
    }
    return preorder_vector;
}

// Difficulty: Easy
