// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-tree-right-side-view/
// Date: 10th September, 2022
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
    vector<int> sol;
    vector<int> rightSideView(TreeNode* root) {
            queue<TreeNode*> q;
            if(root!=NULL) q.push(root);
            int count = q.size();
            while(!q.empty())
            {
                for(int i=0;i<count;i++)
                {
                    TreeNode* node = q.front();
                    q.pop();
                    if(i==count-1)
                    {
                        sol.push_back(node->val);
                    }
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                }
                count = q.size();
            }
            return sol;
    }
   
};
