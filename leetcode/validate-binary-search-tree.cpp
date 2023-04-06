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


// Approach 3
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        long prev = LONG_MIN;
        isValidBSTHelp(root, isValid, prev);
        return isValid;

    }
    void isValidBSTHelp(TreeNode* root, bool &isValid, long& prev) {
        if(root!=NULL) {
            isValidBSTHelp(root->left, isValid, prev);
            isValid = isValid && (root->val > prev);
            prev = root->val;
            isValidBSTHelp(root->right, isValid, prev);
        }
    }
};


// Approach 1
class Solution {
public:
    bool flag;
    bool isValidBST(TreeNode* root) {
        flag = true;
        
        dfs(root, LLONG_MIN);
        return flag;
        
        
    }
    
    long long dfs(TreeNode* root, long long val)
    {
        if(root!=NULL)
        {
            long long l = dfs(root->left,val);
            if((long long)root-> val <= l)
            {
                flag = false;
            }
            
            long long r = dfs(root->right,(long long)root-> val);
            
            return r;
        }
        else
        {
            return val;
        }
    }
};

// Approach 2
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
