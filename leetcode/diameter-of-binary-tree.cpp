// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/diameter-of-binary-tree/
// Date: 29th May, 2021
// Tags: dfs, trees




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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        help(root,maxi);
        return maxi;
    }
    
    static int help(TreeNode* root,int& maxi)
    {
        if(root!=NULL)
        {
            int l = help(root->left,maxi);
            int r = help(root->right,maxi);
            maxi = max(maxi,l+r);
            return max(l+1,r+1);
        }
        return 0;
    }
};