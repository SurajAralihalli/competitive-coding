
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Date: 6th July, 2021
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursive(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    
    TreeNode* recursive(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
        if(lp<=rp)
        {
            
            int i;
            for(i=li;i<=ri;i++)
            {
                if(inorder[i]==preorder[lp]) break;
            }
            
            int widthLeft = i - li;
            
            TreeNode* node = new TreeNode(preorder[lp]);
            node -> left = recursive(preorder, inorder, lp+1, lp+widthLeft, li, i-1);
            node->right = recursive(preorder, inorder, lp+widthLeft+1, rp, i+1, ri);
            
            return node;
        }
        else 
        {
            return NULL;
        };
    }
    
};
