// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/cousins-in-binary-tree/
// Date: 15th Nov, 2021
// Tags: bfs

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int count = q.size();
        
        if(root->left!=NULL && root->right!=NULL)
        {
            int l = root->left->val;
            int r = root->right->val;

            if((l==x || l==y) && (r==x || r==y))
            {
                return false;
            }
        }
        
        while(!q.empty())
        {
            int found =0;
            for(int i=0;i<count;i++)
            {
                auto top = q.front();
                q.pop();
                if(top->val==x || top->val==y)
                {
                    found++;
                }
                
                if(top->left!=NULL)
                {
                    q.push(top->left);
                }
                
                if(top->right!=NULL)
                {
                    q.push(top->right);
                }
                
                if(top->left!=NULL && top->right!=NULL)
                {
                    int l = top->left->val;
                    int r = top->right->val;
                    
                    if((l==x || l==y) && (r==x || r==y))
                    {
                        return false;
                    }
                }
            
            }
            
            if(found==2) 
            {
                return true;
            }
            
            count = q.size();
        }
        
        return false;
    }
};
