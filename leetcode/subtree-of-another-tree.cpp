// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subtree-of-another-tree/
// Date: 28th July, 2022
// Tags: trees, bfs


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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            bool result = isSameTree(node, subRoot);
            if(result) return result;
            
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return false;
    }
    
    
    
    bool isSameTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1!=NULL and root2!=NULL)
        {
            return (root1->val == root2->val) && (isSameTree(root1->left, root2->left)) && (isSameTree(root1->right, root2->right));
        }
        else if(root1==NULL and root2==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
