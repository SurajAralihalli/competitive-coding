// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/odd-even-linked-list/
// Date: 30th Oct, 2022
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        else if(head->next==NULL) return head;
        
        ListNode* oddhead = head;
        ListNode* evenhead = NULL;
        
        ListNode* oddcur = head;
        ListNode* evencur = NULL;
        
        ListNode* oddprev = NULL;
        
        while(oddcur!=NULL && oddcur->next!=NULL)
        {
            if(evenhead==NULL)
            {
                evenhead = oddcur->next;
                evencur = oddcur->next;
            }
            else
            {
                evencur->next = oddcur->next;
                evencur = evencur->next;
            }
            oddcur->next = oddcur->next->next;
            oddprev = oddcur;
            oddcur = oddcur->next;
        }
        
        evencur->next = NULL;
        
        if(oddcur==NULL)
        {
            oddprev->next = evenhead;
        }
        else
        {
            oddcur->next = evenhead;
        }
        
        return oddhead;
    }
};
