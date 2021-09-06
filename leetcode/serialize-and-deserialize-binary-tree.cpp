// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Date: 6th September, 2021
// Tags: dfs, string, stoi, to_string, preorder



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = dfs_preorder(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return preorder_construct(ss);
        return NULL;
        
        
    }
    
    string dfs_preorder(TreeNode* root)
    {
        if(root!=NULL)
        {
            string val = to_string(root->val) + ";"+ dfs_preorder(root->left) + ";" + dfs_preorder(root->right);
            return val;
        }
        else
        {
            return "x";
        }
    }
    
    TreeNode* preorder_construct(stringstream& ss)
    {   
        string token;
        if(getline(ss,token,';'))
        {
            if(token=="x")
            {
                return NULL;
            }
            else
            {
                TreeNode* node = new TreeNode();
                node->val = stoi(token);
                node->left = preorder_construct(ss);
                node->right = preorder_construct(ss);
                return node;
            }
        }
        return NULL;
    }
};

