// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/add-two-numbers/
// Date: 8th May, 2021
// Tags: linked lists

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* f1 = l1;
        ListNode* f2 = l2;
        ListNode* cur = new ListNode;
        ListNode* next;
        ListNode* head = cur;
        
        
        ListNode* tail;
        int sum =0;
        int carry =0;
        int a =0;
        int b =0;
        while(carry!=0 || f1!=NULL || f2!=NULL)
        {
            if(f1!=NULL)
            {
                a = f1->val;
                f1=f1->next;
            }
            else
                a = 0;
            
            if(f2!=NULL){
                b = f2->val;
                f2 = f2->next;
            }
            else
                b = 0;
            
            
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            
            
            cur->val = sum;
            if(f1==NULL && f2==NULL && carry==0)
            {
                cur->next = NULL;
                tail = cur;
            }
            else
                cur->next = new ListNode;

            cur = cur->next;
            
        }
//         ListNode* rhead;
//         ListNode* rcur = head;
//         ListNode* prev = NULL;
//         ListNode* rnext = NULL;
//         while(rcur!=NULL)
//         {
//             rnext = rcur->next;
//             rcur->next = prev;
//             prev = rcur;
//             rcur = rnext;
            
            
            
            
//         }
//         return prev;
        return head;
    }
};