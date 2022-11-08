// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
// Date: 8th Nov, 2022
// Tags: bfs, trees, tree

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
    map<int, vector<int>> map;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        if(root!=NULL)
        {
             q.push({root, 0});
        }
       
        int count = q.size();
        
        while(!q.empty())
        {
            for(int i=0;i<count;i++)
            {
                auto top = q.front();
                q.pop();
                
                TreeNode* node = top.first;
                int index = top.second;
                
                map[index].push_back(node->val);
                
                if(node->left!=NULL)
                {
                    q.push({node->left, index-1});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right, index+1});
                }
            }
            
            count = q.size();
        }
        
    vector<vector<int>> sol;
    for(auto i:map)
    {
        sol.push_back(i.second);
    }
        
    return sol;
    }
};
