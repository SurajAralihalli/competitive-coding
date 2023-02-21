// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reorder-list/
// Date: 21st November, 2021
// Tags: linked-list, linklist

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


//Approach 2
class Solution {
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        stack<ListNode*> stk;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow;
        while(mid!=NULL) {
            stk.push(mid);
            mid = mid->next;
        }

        ListNode* cur = head;
        ListNode* top;
        while(!stk.empty()){
            top = stk.top();
            stk.pop();
            cout << cur->val << " " << top->val << endl;
            top->next = cur->next;
            cur->next = top;
            cur = top->next;
        }

        top->next = NULL;

        return;
    }
};

//Approach 1
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
