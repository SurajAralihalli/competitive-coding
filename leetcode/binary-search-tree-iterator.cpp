// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/binary-search-tree-iterator/
// Date: 9th November, 2021
// Tags: trees

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
class BSTIterator {
public:
    TreeNode* cur = new TreeNode(INT_MIN,NULL,NULL);
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        stk.push(root);
        TreeNode* p = root;
        while(p!=NULL)
        {
            stk.push(p);
            if(p->left!=NULL)
            {
                p = p->left;
            }
            else
            {
                p = NULL;
            }
        }
        
    }
    
    int next() {
        TreeNode* p = stk.top();
        int s = p->val;
        p = p->right;
        stk.pop();
        while(p!=NULL)
        {
            stk.push(p);
            if(p->left!=NULL)
            {
                p = p->left;
            }
            else
            {
                p = NULL;
            }
        }
        return s;
        
    }
    
    bool hasNext() {
        return stk.size()>1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
