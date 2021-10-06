// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reverse-linked-list/
// Date: 6th October, 2021
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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxt = NULL;
        while(cur!=NULL)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        return prev;
    }
};
