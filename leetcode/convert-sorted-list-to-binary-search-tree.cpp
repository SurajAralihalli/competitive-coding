// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Date: 28th October, 2021
// Tags: recursion, trees, linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

//Approach 1
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n =0;
        ListNode* p =head;
        while(p!=NULL)
        {
            n++;
            p = p-> next;
        }
        
        return construct(head, n);
    }
    
    TreeNode* construct(ListNode* head, int n)
    {

        if(n==0) return NULL;
        ListNode* p = head;
        int center = ceil((double)n/2);
        int s=1;
        while(true)
        {
            if(s==center) break;
            s++;
            p = p->next;
        }
        
        TreeNode* node = new TreeNode(p->val);
        
        int numberOfNodesRight = n - center;
        int numberOfNodesLeft = n - numberOfNodesRight - 1;
    
        node->left = construct(head, numberOfNodesLeft);
        node->right = construct(p->next, numberOfNodesRight);
        
        return node;
        
    }
};

//Approach 2
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int c =0;
        ListNode* t = head;
        while(t!=NULL)
        {
            c++;
            t= t->next;
        }
        return buildTree(head,c);
    }
    
    TreeNode* buildTree(ListNode* start,int n)
    {
        if(n==0)
        {
            return NULL;
        }
        else if(n==1)
        {
                    TreeNode* node = new TreeNode();
                    node->val = start->val;
                    cout << start->val << " " << n << endl;
                    node->left = NULL;
                    node->right = NULL;
                    return node;
        }
        
        else
        {

            int m = n/2;
            ListNode* p = start;
            for(int i=0;i<m;i++)
            {
                p= p->next;
            }
            TreeNode* node = new TreeNode();
            node->val = p->val;
            node->left = buildTree(start, m);
            int r =  n%2==0?m-1:m;
            node->right = buildTree(p->next,r);
            return node;
        }
        return NULL;
    }
    
};
