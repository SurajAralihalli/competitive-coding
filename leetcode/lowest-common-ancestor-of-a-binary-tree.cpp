// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Date: 7th September, 2021
// Tags: tree, dfs, binary


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursive(root,p,q);
        return lca;
    }
    
    bool recursive(TreeNode* root,TreeNode* p, TreeNode* q)
    {
        if(root!=NULL)
        {
            bool cur = false;;
            if(root == p || root == q) cur = true;
            bool left =false,right=false;
            left = recursive(root->left,p,q);
            right = recursive(root->right,p,q);
            if((cur && left) || (cur && right) || (left && right)) 
            {lca=root;}
            return (cur || left || right);
        
            
        }
        return false;
    }
};
