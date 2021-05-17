// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool r;
        // leaf nodes
        if(p!=NULL && q!=NULL)
        {
            if(p->val == q->val)
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) ;
            }
            else {return false;}
        }
        else if(p==NULL && q==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};