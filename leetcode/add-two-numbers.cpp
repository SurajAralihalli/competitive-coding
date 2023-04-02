// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/add-two-numbers/
// Date: 8th May, 2021
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

// Approach 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry =0;
        while(p1!=NULL && p2!=NULL)
        {
            int sum = carry + p1->val + p2->val;
            carry = sum>=10 ? 1 : 0;
            sum = sum % 10;
            
            cur->next = new ListNode(sum);
            cur = cur->next;
            
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL)
        {
            int sum = carry + p1->val;
            carry = sum>=10 ? 1 : 0;
            sum = sum % 10;
            
            cur->next = new ListNode(sum);
            cur = cur->next;
            
            p1=p1->next;
        }
        while(p2!=NULL)
        {
            int sum = carry + p2->val;
            carry = sum>=10 ? 1 : 0;
            sum = sum % 10;
            
            cur->next = new ListNode(sum);
            cur = cur->next;
            
            p2=p2->next;
        }
        
        if(carry)
        {
            int sum = carry;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        
        return head->next;
    }
};

// Approach 1
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
