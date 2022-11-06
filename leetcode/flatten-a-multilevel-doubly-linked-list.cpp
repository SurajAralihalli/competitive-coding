// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Date: 6th Nov, 2022
// Tags: linked-list, stack

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> prevLevel;
        
        Node* prev = NULL;
        Node* cur = head;
        while(cur!=NULL || !prevLevel.empty())
        {
            if(cur==NULL)
            {
                cur = prevLevel.top();
                prev->next = cur;
                if(cur!=NULL)
                {
                    cur->prev = prev;
                }
                prevLevel.pop();
            }
            else
            {
                if(cur->child!=NULL)
                {
                    prevLevel.push(cur->next);
                    prev =cur;
                    cur->next = cur->child;
                    if(cur->next!=NULL)
                    {
                        cur->next->prev = cur;
                    }
                    cur->child = NULL;
                    cur = cur->next;
                }
                else
                {
                    prev =cur;
                    cur = cur->next;
                }
            }
            
        }
        
        return head;
        
    }
};
