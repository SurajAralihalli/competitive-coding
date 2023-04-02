// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/merge-k-sorted-lists/
// Date: 14th November, 2021
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> min_heap;
        for(auto i:lists)
        {
            if(i!=NULL)
            {
                min_heap.push({i->val,i});
            }
        }
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(!min_heap.empty())
        {
            ListNode* t = min_heap.top().second;
            min_heap.pop();
            if(head==NULL)
            {
                head = t;
                prev = t;
            }
            else
            {
                prev->next = t;
                prev = t;
            }
            if(t->next!=NULL)
            {
                min_heap.push({t->next->val,t->next});
            }
            
        }
        return head;
    }
};
