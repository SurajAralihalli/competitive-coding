// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reorder-list/
// Date: 21st November, 2021
// Tags: link-list, linklist

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
    void reorderList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* mid = NULL;
        
        //find mid
        while(p1!=NULL && p2!=NULL)
        {
            p1 = p1->next;
            if(p2->next!=NULL) p2 = p2->next->next;
            else p2 = NULL;
        }
        mid = p1;
        
        //reverse from mid
        ListNode* cur = mid;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        
        while(cur!=NULL)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        mid = prev;
        
        // //Print
        // ListNode* temp = head;
        // while(temp)
        // {
        //     cout << temp->val << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
        // temp = mid;
        // while(temp)
        // {
        //     cout << temp->val << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
        
        p1 = head;
        ListNode* fn = NULL;
        ListNode* mn = NULL;
        while(p1 && mid)
        {
            fn = p1->next;
            p1->next = mid;
            mn = mid->next;
            mid->next = fn;
            p1 = fn;
            mid = mn;   
        }
        
        if(mid==NULL)
        {
            p1->next = NULL;
        }
        else
        {
            mid->next = NULL;
        }
        
        
    }
};
