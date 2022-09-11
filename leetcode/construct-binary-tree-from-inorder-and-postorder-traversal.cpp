// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Date: 11th September, 2022
// Tags: trees, tree

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
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        
        return build(0, inorder.size()-1, 0, postorder.size()-1);
        
    }
    
    TreeNode* build(int inL, int inR, int postL, int postR)
    {
        if(postL <= postR)
        {
            int value = postorder[postR];
            TreeNode* node = new TreeNode(value);
            
            int index = inL;
            for(int i=inL; i<=inR; i++)
            {
                if(inorder[i] == value)
                {
                    index = i;
                    break;
                }
            }
            
            int width = index - inL;
            node->left = build(inL, index-1, postL, postL + width - 1 );
            node->right = build(index+1, inR, postL + width, postR - 1 );
            
            return node;
        }
        else
        {
            return NULL;
        }
    }
    
};
