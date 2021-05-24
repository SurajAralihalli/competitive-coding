// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Date: 24th May, 2021
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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        help(root,maxi);
        return maxi;
        
    }
    
    static int help(TreeNode* root,int& maxi)
    {
        if(root!=NULL)
        {
            int a = (root->val);
            int l = help(root->left,maxi);
            int r = help(root->right,maxi);
            
            int local_maxi = INT_MIN;
            local_maxi=max(local_maxi,a);
            local_maxi=max(local_maxi,l+a);
            local_maxi=max(local_maxi,r+a);
            
            int send = local_maxi;
            maxi = max(maxi,local_maxi);
            maxi = max(maxi,a + l + r );
            // cout << l << " " << a << " " << r << endl;
            // cout << "send: " << send << " maxi: "<< maxi << endl;
            return send;
        }
        else
        {
            return 0;
        }
    }
};
