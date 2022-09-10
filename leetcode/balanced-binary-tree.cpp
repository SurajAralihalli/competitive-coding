// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/balanced-binary-tree/
// Date: 10th September, 2022
// Tags: trees, tree

/*
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
    bool balanced;
    bool isBalanced(TreeNode* root) {
        balanced = true;
        depthR(root);
        return balanced;
    }
    
    int depthR(TreeNode* root)
    {
        if(root!=NULL)
        {
            int l = depthR(root->left);
            int r = depthR(root->right);
            
            if(abs(l-r)>1) {balanced = false;}
            return max(l,r)+1;
        }
        else
        {
            return 0;
        }
    }
};
