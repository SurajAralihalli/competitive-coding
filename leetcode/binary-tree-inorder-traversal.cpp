// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Date: 22th May, 2021
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> vec;
        vec.reserve(1000);
        inh(root,vec);
        return vec;
    }
    
    
    static void inh(TreeNode* root,vector<int>& vec)
    {
        
        if(root==NULL) return;
        if(root->left!=NULL)
        {
            inh(root->left,vec);
        }
        
        vec.push_back(root->val);
            
        if(root->right!=NULL)
        {
            inh(root->right,vec);
        }
        
        
        
    }
};