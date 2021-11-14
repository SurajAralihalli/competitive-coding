// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Date: 14th November, 2021
// Tags: linkedlist

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t=0;
        ListNode* p =head;
        while(p!=NULL)
        {
            t++;
            p=p->next;
        }
        
        int s = t-n+1;
        
        if(s==1)
        {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
        else
        {
            p = head;
            for(int i=1;i<s-1;i++)
            {
                p= p->next;
            }
            ListNode* nextN = p->next;
            p->next = nextN->next;
            delete nextN;
        }
        return head;
    }
};
