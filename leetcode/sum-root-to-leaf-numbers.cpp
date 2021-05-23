// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
        int sumi=0;
        int total = 0;
        help(root,sumi,total);
        return total;
        
    }
    
    static void help(TreeNode* root, int sumi, int& total)
    {
        //if leaf
        if(root!=NULL)
        {
            sumi= (sumi * 10) + (root->val);
            help(root->left,sumi,total);
            help(root->right,sumi,total);
            
            if((root->left == NULL) && (root->right == NULL))
            {
                total += sumi;
            }
        }
        return;
        
    }
};