// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Date: 18th May, 2021
// Tags: stack, tree, BFS


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> matrix;
        matrix.reserve(100);
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        if(root==NULL) {return matrix;}
        while(!q.empty())
        {
            int s = q.size();
            vector<int> vec;
            level++;
            for(int i=0;i<s;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                cout << "level: "<< (level) << " " << node->val << endl;
                vec.push_back(node->val);
                
                if(node->left)
                {
                   q.push(node->left);
                }
                if(node->right)
                {
                   q.push(node->right);
                }
                
            }
            if(level%2==0){reverse(vec.begin(),vec.end());}
            matrix.push_back(vec);
    }
    return matrix;
    }
};