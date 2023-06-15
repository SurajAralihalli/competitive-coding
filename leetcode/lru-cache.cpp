// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/lru-cache/
// Date: 2nd July, 2021
// Tags: hashmap, doubly-linked-list, linked-list, design

// Approach 3
class LRUCache {
public:
    list<pair<int,int>> linkedList;
    unordered_map<int, list<pair<int,int>>::iterator> map;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()) {
            auto node = map[key];
            int value = node->second;
            linkedList.erase(node);
            linkedList.push_back({key, value});
            map[key] = prev(linkedList.end(),1);
            return value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()) {
            auto node = map[key];

            linkedList.erase(node);
            linkedList.push_back({key, value});
            map[key] = prev(linkedList.end(),1);
        }
        else {
            if(linkedList.size() < capacity) {
                linkedList.push_back({key, value});
                map[key] = prev(linkedList.end(),1);
                
            }
            else {
                auto node = linkedList.begin();
                map.erase(node->first);
                linkedList.erase(node);
                
                linkedList.push_back({key, value});
                map[key] = prev(linkedList.end(),1);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//Approach 2
class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
    Node(int key, int value, Node* prev, Node* next) {
        this->key = key;
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int count;
    LinkedList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addAtEnd(Node* node) {
        if(count == 0) {
            node->prev = NULL;
            node->next = NULL;
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            node->next = NULL;
            tail = node;
        }
        count++;
    }

    void removeNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;

        if(next!=NULL) { 
            next->prev = prev;
        }
        else { //removing tail node
            tail = prev;
        }

        if(prev!=NULL) {
            prev->next = next;
        }
        else { //removing head node
            head = next;
        }
        // delete node;
        count--;
    }

};

class LRUCache {
public:
    LinkedList* linkedList;
    unordered_map<int, Node*> map;
    int capacity;
    LRUCache(int capacity) {
        linkedList = new LinkedList();
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()) {
            Node* node = map[key];
            int value = node->value;
            linkedList->removeNode(node);
            linkedList->addAtEnd(node);
            return value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()) {
            Node* node = map[key];
            node->value = value;

            linkedList->removeNode(node);
            linkedList->addAtEnd(node);
        }
        else {
            if(linkedList->count < capacity) {
                Node* node = new Node(key, value, NULL, NULL);
                map[key] = node;
                linkedList->addAtEnd(node);
            }
            else {
                map.erase(linkedList->head->key);
                Node* oldNode = linkedList->head;
                linkedList->removeNode(linkedList->head);
                delete oldNode;
                
                Node* node = new Node(key, value, NULL, NULL);
                map[key] = node;
                linkedList->addAtEnd(node);
            }
        }
    }
};

//Approach 1
class LRUCache {
    
private:
    struct node
    {
        int key;
        int val;
        node* prev;
        node* next;
    };
    unordered_map<int,node *> map;
    node* head = NULL;
    node* tail = NULL;
    int capacity;
    int count;
    
    void add_to_top_dlist(node* dnode)
    {
        if(head!=NULL)
        {
            dnode->next = head;
            head->prev = dnode;
        }
        else
        {
            tail = dnode;
        }
        dnode->prev = NULL;
        head = dnode;
        
        // cout << endl<<head->val << "*" << tail->val << endl;
    }
    
    void remove_node(node* dnode)
    {
        node* p = dnode->prev;
        node* n = dnode->next;
        
        if(p!=NULL)
        {
            p->next = n;
        }
        else
        {
            //removing node is head node
            head = n;
            
            
        }
        if(n!=NULL)
        {
            n->prev = p;
        }
        else
        {
            //removing node is tail node
            tail = p;
        }
        
        delete dnode;
        
    }
    
    void print_map()
    {
        for(auto i = map.begin();i!=map.end();i++)
        {
            cout << i->first << ":" << i->second->val << " , ";
        }
        cout << endl;
    }
    
    void print_dlist()
    {
        node* thead = head;
        while(thead!=NULL)
        {
            cout << thead->key << ":" << thead->val << " , ";
            thead = thead->next;
        }
        cout << endl;
    }
    
    node* create_node(int key, int value)
    {
        node* dnode = new node();
        dnode->key = key;
        dnode->val= value;
        dnode->next = NULL;
        dnode->prev = NULL;
        
        return dnode;
    }
    
    
    
public:
    
    LRUCache(int capacity) {
       this->capacity = capacity;
       this->count=0;
    }
    
    int get(int key) {
        
        // cout << "get " + to_string(key);
        // print_map();
        // print_dlist();
        
        if(map.find(key)!=map.end())
        {
            node * dnode =  map[key];
            int value = dnode->val;
            remove_node(dnode);
            node* newd = create_node(key,value);
            add_to_top_dlist(newd);
            map[key] = newd;
            return value;
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        // cout << "put " + to_string(key) + ":" + to_string(value);
        if(map.find(key)!=map.end())
        {
            //update
            node * dnode =  map[key];
            dnode->val = value;
            remove_node(dnode);
            node* newd = create_node(key,value);
            add_to_top_dlist(newd);
            map[key] = newd;
        }
        else
        {
            //new
            node* dnode = new node();
            dnode->key = key;
            dnode->val = value;
            dnode->next = NULL;
            dnode->prev = NULL;
            map[key] = dnode;
            add_to_top_dlist(dnode);
            count++;
        }

        if(count>capacity)
        {
            node * temp = tail;
            map.erase(temp->key);
            remove_node(temp);
            count--;
        }
        
        
        // print_map();
        // print_dlist();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
