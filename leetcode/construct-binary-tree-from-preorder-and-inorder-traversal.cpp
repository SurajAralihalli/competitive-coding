
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ (partial answer)
// Date: 10th November, 2021
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
        int np = preorder.size();
        int ni = inorder.size();
        unordered_map<int,int> imap;
        for(int i=0;i<ni;i++)
        {
            imap[inorder[i]] = i;
        }
        return recurse(preorder,inorder,0,np, 0,ni,imap);
    }
    
    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int p, int np, int i,  int ni,unordered_map<int,int> imap)
    {
        if(np>0 || ni>0)
        {
            // cout << p << " " << np << " " << i << " " << ni << endl;
            TreeNode* node = new TreeNode();
            node->val = preorder[p];
            
            int iindex = imap[preorder[p]];
            int ln = iindex - i;
            int rn = ni - ln - 1;
            
            node->left = recurse(preorder,inorder,p+1,ln, i,ln,imap);
            node->right = recurse(preorder,inorder,p+ln+1,rn, iindex+1,rn,imap);
            
            return node;
        }
        return NULL;
    }
};
