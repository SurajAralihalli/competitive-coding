// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/invert-binary-tree/
// Date: 23th May, 2021
// Tags: tree

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
    TreeNode* invertTree(TreeNode* root) {
        invertTreehelp(root);
        return root;
    }
    
    static void invertTreehelp(TreeNode* root)
    {
        if(root!=NULL)
        {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTreehelp(root->left);
            invertTreehelp(root->right);
        }
        return;
    }
};