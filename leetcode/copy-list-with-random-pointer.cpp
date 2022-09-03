// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/copy-list-with-random-pointer/
// Date: 2nd Sept, 2022
// Tags: linked-list, pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Approach 2
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p=head;
        if(p==NULL) 
        {
            return NULL;
        }
        else if(p->next==NULL)
        {
            Node* c= new Node(p->val);
            if(p->random==p) 
            {
                c->random = c;
            }
            return c;
        }
        
        while(p!=NULL)
        {
            Node* c = new Node(p->val);
            c->next = p->next;
            p->next = c;
            
            p = c->next;
        }
        
        p=head;
        while(p!=NULL)
        {
            if(p->random!=NULL)
            {
                p->next->random = p->random->next;
            }
            
            p = p->next->next;
        }
        
        p=head;
        Node* newP=NULL;
        while(p->next->next!=NULL)
        {
            Node* c = p->next;
            p->next = c->next;
             
            c->next = c->next->next;
            p = p->next;
            
            if(newP==NULL)
            {
                newP = c;
            }
        }
        
        p->next = NULL;
        
        return newP;
        
    }
};

//Approach 1
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        unordered_map<Node*, Node*> map;
        Node* newP =NULL;
        while(p!=NULL)
        {
            Node* temp = new Node(p->val);
            map[p] = temp;
            p = p->next;
        }
        
        p = head;
        while(p!=NULL)
        {
            Node* c = map[p];
            c->next = map[p->next];
            c->random = map[p->random];
            
            p = p->next;
            if(newP==NULL)
            {
                newP = c;
            }
        }
        
        return newP;
    }
};
