// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/linked-list-cycle/
// Date: 21st June, 2021
// Tags: 2 pointers. linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = NULL;
        if(head==NULL){return false;}
        if(head->next!=NULL) {f=head->next->next;}
        while(s!=NULL && f!=NULL)
        {
            if(s==f) {return true;}
            s=s->next;
            if(f->next!=NULL) 
            {
                f=f->next->next;
            }
            else
            {
                f=NULL;
            }
        }
        return false;
    }
};
