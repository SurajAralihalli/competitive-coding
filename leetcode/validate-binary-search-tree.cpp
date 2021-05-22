// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/validate-binary-search-tree/
// Date: 22th May, 2021
// Tags: tree, binary-search

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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        long long m = LLONG_MIN;
        if(root!=NULL){
            inh(root,flag,m);
        }
        return flag;
    
    }
    
    
     static void inh(TreeNode* root,bool& flag, long long& m)
    {
        int v = root->val;
        int a;
        int b;
         
        if(root->left!=NULL)
        {
            inh(root->left,flag, m);
        }
        
         
        // cout << m << " " << v << " " << ( ((flag) && (v>m)) ) <<endl;

        flag = ((flag) && ((long long)v>m));

        
        m = v;
        
        if(root->right!=NULL)
        {
            inh(root->right,flag,m);
            
        }
        
        
        
        
    }
    
};