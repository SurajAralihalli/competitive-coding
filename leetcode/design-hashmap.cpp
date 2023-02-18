// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-hashmap/description/
// Date: 17th Feb, 2023
// Tags: hashmap, system-design
 
class MyHashMap {
public:
    vector<list<pair<int, int>>> hashmap;
    int keysize;
    MyHashMap() {
        keysize = 2048;
        hashmap.assign(keysize, list<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int k = key%keysize;
        bool found = false;
        for (auto i = hashmap[k].begin(); i!=hashmap[k].end(); i++) {
            if(i->first == key) {
                i->second = value;
                found = true;
                break;
            }
        }
        if(!found) {
            hashmap[k].push_back({key, value});
        }
        
    }
    
    int get(int key) {
        int k = key%keysize;
        bool found = false;
        for (auto p: hashmap[k]) {
            if (p.first == key)
            {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int k = key%keysize; 
        list<pair<int, int>>::iterator iter;
        bool found = false;
        for (auto i = hashmap[k].begin(); i!=hashmap[k].end(); i++) {
            if(i->first == key) {
                iter = i;
                found = true;
                break;
            }
        }
        if(found) {
            hashmap[k].erase(iter);
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
