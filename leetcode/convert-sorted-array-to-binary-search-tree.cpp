// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Date: 9th November, 2021
// Tags: trees, array


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
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        int n = nums.size();
        return buildTree(nums,0,n-1);
    }
    
    TreeNode* buildTree(vector<int>& nums,int l, int r)
    {
        
        if(l==r)
        {
            TreeNode* node = new TreeNode();
            node->left = NULL;
            node->right = NULL;
            node->val = nums[l];
            return node;
        }
        if(l>r)
        {
            return NULL;
        }
        else
        {
            int m = (l+r)/2;
            TreeNode* node = new TreeNode();
            node->left = buildTree(nums,l,m-1);
            node->right = buildTree(nums,m+1,r);
            node->val = nums[m];
            return node;
            
        }
        
    }
};
