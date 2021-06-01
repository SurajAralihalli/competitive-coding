// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Date: 1st June, 2021
// Tags: bfs, trees



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root!=NULL)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int n = q.size();
            Node * prev = NULL;
            for(int i=0;i<n;i++)
            {
                Node * t = q.front();
                // cout << t->val << endl;
                q.pop();
                t->next = prev;
                prev = t;
                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
                
            }
        }
        return root;
    }
};