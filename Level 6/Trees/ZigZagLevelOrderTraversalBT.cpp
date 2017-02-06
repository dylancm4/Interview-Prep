//
//  ZigZagLevelOrderTraversalBT.cpp
//  
//
//  Created by Dylan Miller on 2/5/17.
//
//

/*
 Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
 
 Example :
 Given binary tree
 
 3
 / \
 9  20
 /  \
 15   7
 return
 
 [
 [3],
 [20, 9],
 [15, 7]
 ]
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
enum Direction {DIRECTION_LEFT_TO_RIGHT, DIRECTION_RIGHT_TO_LEFT};
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    vector<vector<int>> zigzag_nodes;
    if (A)
    {
        int row_number = 0;
        zigzag_nodes.push_back(vector<int>());
        stack<TreeNode*> left_to_right_nodes;
        stack<TreeNode*> right_to_left_nodes;
        left_to_right_nodes.push(A);
        Direction direction = DIRECTION_LEFT_TO_RIGHT;
        while ((direction == DIRECTION_LEFT_TO_RIGHT && !left_to_right_nodes.empty())
               || (direction == DIRECTION_RIGHT_TO_LEFT && !right_to_left_nodes.empty()))
        {
            if (direction == DIRECTION_LEFT_TO_RIGHT)
            {
                TreeNode* node = left_to_right_nodes.top();
                left_to_right_nodes.pop();
                
                zigzag_nodes[row_number].push_back(node->val);
                
                if (node->left)
                    right_to_left_nodes.push(node->left);
                if (node->right)
                    right_to_left_nodes.push(node->right);
                
                if (left_to_right_nodes.empty() && !right_to_left_nodes.empty())
                {
                    row_number++;
                    zigzag_nodes.push_back(vector<int>());
                    direction = DIRECTION_RIGHT_TO_LEFT;
                }
            }
            else // DIRECTION_RIGHT_TO_LEFT
            {
                TreeNode* node = right_to_left_nodes.top();
                right_to_left_nodes.pop();
                
                zigzag_nodes[row_number].push_back(node->val);
                
                if (node->right)
                    left_to_right_nodes.push(node->right);
                if (node->left)
                    left_to_right_nodes.push(node->left);
                
                if (right_to_left_nodes.empty() && !left_to_right_nodes.empty())
                {
                    row_number++;
                    zigzag_nodes.push_back(vector<int>());
                    direction = DIRECTION_LEFT_TO_RIGHT;
                }
            }
        }
    }
    return zigzag_nodes;
}

// Difficulty: Easy, but took a while.


