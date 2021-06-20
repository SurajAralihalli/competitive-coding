
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Date: 20th May, 2021
// Tags: linked-list


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0;
        ListNode *heada = headA;
        while(heada!=NULL)
        {
            la++;
            heada=heada->next;
        }
        
        int lb = 0;
        ListNode *headb = headB;
        while(headb!=NULL)
        {
            lb++;
            headb=headb->next;
        }
        
        int lm = min(la,lb);
        if(la>lm)
        {
            for(int i =0;i<(la-lm);i++)
            {
                headA = headA->next;
            }
        }
        else if(lb>lm)
        {
            for(int i =0;i<(lb-lm);i++)
            {
                headB = headB->next;
            }
        }
        // cout << headA->val << " " << headB->val << endl;
        for(int i=0;i<lm;i++)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
            
        }
        return NULL;
        
        
    }
};
