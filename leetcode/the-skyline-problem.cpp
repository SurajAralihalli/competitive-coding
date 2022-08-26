// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/the-skyline-problem/
// Date: 25th August, 2022
// Tags: heap, priority-queue, line-sweep

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> coordinates;
        for(auto b: buildings)
        {
            vector<int> left = {b[0],b[2],0};
            vector<int> right = {b[1],b[2],1};
            coordinates.push_back(left);
            coordinates.push_back(right);
        }
        
        sort(coordinates.begin(), coordinates.end(), comp1);
        
        auto comp2 = [](int a,int b) {return a>b;};
        //max heap - priority queue
        multiset<int, decltype(comp2)> pq(comp2);
        
        int maxHeight = 0;
        pq.insert(0);
        
        vector<vector<int>> sol;
        
        for(auto coord: coordinates)
        {
            int x = coord[0];
            int h = coord[1];
            int se = coord[2];
            
            //start
            if(se==0)
            {
                pq.insert(h);
                if(*pq.begin()!=maxHeight)
                {
                    maxHeight = h;
                    sol.push_back({x,maxHeight});
                }
            }
            else
            {
                pq.erase(pq.find(h));
                if(*pq.begin()!=maxHeight)
                {
                    maxHeight = *pq.begin();
                    sol.push_back({x,maxHeight});
                }
            }
        }
        
        
        return sol;
        
    }
    
    static bool comp1(vector<int> a, vector<int> b)
    {
        int x1 = a[0];
        int h1 = a[1];
        int se1 = a[2];
        
        int x2 = b[0];
        int h2 = b[1];
        int se2 = b[2];
        
        //starts
        if(x1 == x2 && se1==se2 && se1==0)
        {
            return h1 > h2;
        }
        //ends
        else if(x1 == x2 && se1==se2 && se1==1)
        {
            return h1 < h2;
        }
        else if(x1 == x2 && se1!=se2 && h1==h2)
        {
            return se1 < se2;
        }
        else if(x1 == x2 && se1!=se2)
        {
            return se2 > se1;
        }
        else
        {
            return x1 < x2;
        }
    }
    
};
