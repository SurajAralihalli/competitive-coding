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
struct node
{
    TreeNode* p;
    int level;
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> matrix(2000);
        node* root_node = new node();
        root_node->p = root;
        root_node->level = 0;
        queue<node*> q;
        if(root!=NULL)
        {
            q.push(root_node);
        }
        while(!q.empty())
        {
            node* f = q.front();
            q.pop();
            TreeNode* local = f->p;
            // cout << "level: " << f->level << " value: " << local->val << endl; 
            matrix[f->level].push_back(local->val);
            if(local->left!=NULL)
            {
                node* sub_node = new node();
                sub_node->p = local->left;
                sub_node->level = f->level + 1;
                q.push(sub_node);
            }
            
            if(local->right!=NULL)
            {
                node* sub_node = new node();
                sub_node->p = local->right;
                sub_node->level = f->level + 1;
                q.push(sub_node);
            }
            
            
        }
        int i;
        for(i =0;i<2000;i++)
        {
            if(matrix[i].size()==0){break;}
            if(i%2!=0)
            {
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
        matrix.resize(i);
        return matrix;
    }
    
};