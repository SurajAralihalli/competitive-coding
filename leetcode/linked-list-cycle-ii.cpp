// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/linked-list-cycle-ii/
// Date: 3rd Nov, 2022
// Tags: linked-list, pointer

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;
        if(head==NULL || head->next == NULL) return NULL;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            // loop found
            if(slow==fast)
            {
                while(start!=slow)
                {
                    start=start->next;
                    slow=slow->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
