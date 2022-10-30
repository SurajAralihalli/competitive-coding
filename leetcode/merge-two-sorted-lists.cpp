// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/merge-two-sorted-lists/
// Date: 30th October, 2022
// Tags: linked-list

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur;
        ListNode* head=NULL;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                if(head==NULL)
                {
                    head = l1;
                    cur = l1;
                }
                else
                {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            }
            else
            {
                if(head==NULL)
                {
                    head = l2;
                    cur = l2;
                }
                else
                {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        
        if(l1!=NULL)
        {
            if(head==NULL)
            {
                head = l1;
            }
            else
            {
                cur->next = l1;
            }
        }
        else
        {
            if(head==NULL)
            {
                head = l2;
            }
            else
            {
                cur->next = l2;
            }
        }
        
        return head;
    }
};
