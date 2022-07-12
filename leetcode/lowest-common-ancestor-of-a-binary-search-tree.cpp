// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Date: 11th July, 2022
// Tags: trees


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Approach 1
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if((root->val < p->val) && (root->val < q->val))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return root;
        }
        
        
    }
};

//Approach 2
class Solution {
public:
    TreeNode* lca;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = NULL;
        recursive(root, p, q);
        return lca;
    }
    
    pair<bool,bool> recursive(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root!=NULL)
        {
            bool pFound = root->val == p->val?true:false;
            bool qfound = root->val == q->val?true:false;
            
            if(root->val>p->val)
            {
                pFound = pFound || recursive(root->left, p, q).first;
            }
            else
            {
                pFound = pFound || recursive(root->right, p, q).first;
            }
            
            if(root->val>q->val)
            {
                qfound = qfound || recursive(root->left, p, q).second;
            }
            else
            {
                qfound = qfound || recursive(root->right, p, q).second;
            }
            
            if(!lca && pFound && qfound)
            {
                lca = root;
            }
            return {pFound, qfound};
        }
        return {false, false};
    }
};
