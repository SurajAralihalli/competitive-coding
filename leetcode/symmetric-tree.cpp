// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/symmetric-tree/
// Date: 17th May, 2021
// Tags: tree, dfs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root!=NULL)
        {
            return isSymmetric_help(root->left, root->right);
        }
        else
        {
            return true;
        }
    }
    
    static bool isSymmetric_help(TreeNode* a,TreeNode* b)
    {
        if(a!=NULL && b!=NULL)
        {
            if(a->val == b->val)
            {
                return isSymmetric_help(a->left, b->right) && isSymmetric_help(a->right, b->left);
            }
            else
            {
                return false;
            }
        }
        else if(a==NULL && b==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};