// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Date: 2nd Sept, 2022
// Tags: linked-list, pointer

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = new ListNode();
        first->next = head;
        first->val = 10;
        
        ListNode* top = head;
        int count =0;
        while(top!=NULL)
        {
            top=top->next;
            count++;
        }
        
        top = first;
        
        while(count>=k)
        {
            count-=k;
            ListNode* ret = reverse(top,k);
            top = ret;
            
        }
        
        return first->next;
        
    }
    
    ListNode* reverse(ListNode* first, int k)
    {
        ListNode* cur = first->next;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int i=0;
        
        while(cur!=NULL && i!=k)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            i++;
        }
        
        ListNode* lastnode = first->next;
        
        lastnode->next = cur;
        first->next = prev;
        
        return lastnode;
    }
};
