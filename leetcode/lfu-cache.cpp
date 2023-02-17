// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/lfu-cache/description/
// Date: 17th Feb, 2023
// Tags: linked-list, map, hash, system-design

class LFUCache {
public:
    unordered_map<int, pair<int, list< pair<int, int> >:: iterator > > cache;
    unordered_map<int, list< pair<int, int> > > frequencies;
    int capacity;
    int minf;
    void insert(int key, int value, int f) {
        frequencies[f].push_back({key, value});
        cache[key] = {f, prev(frequencies[f].end(),1)};
    }
    LFUCache(int capacity) {
        this->capacity = capacity;
        minf =0;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()) {
            int f = cache[key].first;
            auto f_iter = cache[key].second;
            
            int value = f_iter->second;

            cache.erase(key);
            frequencies[f].erase(f_iter);

            if(frequencies[f].size()==0 && minf == f) {
                minf = f+1;
            }

            insert(key, value, f+1);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()) {
            auto f_iter = cache[key].second;
            int f = cache[key].first;

            cache.erase(key);
            frequencies[f].erase(f_iter);

            insert(key, value, f+1);

        }
        else {
            if(cache.size() == capacity) {
                int k = frequencies[minf].front().first;

                cache.erase(k);
                frequencies[minf].pop_front();
            }
            insert(key, value, 1);
            minf = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
