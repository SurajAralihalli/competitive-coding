// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        string mini(85,'z');
        help(root,s,mini);
        return mini;
    }
    
    static void help(TreeNode* root, string s, string& mini)
    {
        //if leaf
        if(root!=NULL)
        {
            s+= (char)(root->val + int('a'))  ;
            help(root->left,s,mini);
            help(root->right,s,mini);
            // cout << s << endl;
            if((root->left == NULL) && (root->right == NULL))
            {
                reverse(s.begin(),s.end());
                mini = min(s,mini);
                
            }
        }
        return;
        
    }
};