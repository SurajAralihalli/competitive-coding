// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        int maxi=0;
        int depth=0;
        if(root!=NULL)
        {
            depth++;
            help(root,maxi,depth);
        }
        return maxi;
        
        
    }
    
    static void help(TreeNode* root, int& maxi, int depth)
    {
        if(root!=NULL)
        {
            maxi = max(maxi,depth);
            help(root->left,maxi, depth+1);
            help(root->right,maxi, depth+1);
        }
        return;
    }
};