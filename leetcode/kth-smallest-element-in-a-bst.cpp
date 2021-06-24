
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Date: 24th June, 2021
// Tags: trees, dfs, binary-search-tree


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
    int kthSmallest(TreeNode* root, int k) {
        int cur=0;
        return help(root, k,cur);
    }
    
    int help(TreeNode* root, int k, int& cur)
    {
        if(root!=NULL)
        {
            int l = help(root->left,  k, cur);
            cur++;
            if(cur==k) 
            {
                return root->val;
            }
            if(l!=INT_MAX){
                return l;
            }
            int r = help(root->right,  k, cur);
            return r;
        }
        
        return INT_MAX;
    }
};
