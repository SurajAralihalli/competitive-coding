// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Date: 6th July, 2021
// Tags: tree, bfs

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        queue<TreeNode*> q;
        if(root!=NULL) q.push(root);
        
        int count = q.size();
        while(!q.empty())
        {
            vector<int> row;
            for(int i=0;i<count;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sol.push_back(row);
            count = q.size();
        }
        
        return sol;
        
    }
};
