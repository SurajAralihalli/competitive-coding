// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/hand-of-straights/
// Date: 5th Nov, 2022
// Tags: greedy, hash-table

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        //ordered map asc
        map<int,int> map;
        for(int i=0;i<n;i++)
        {
            map[hand[i]]++;
        }
        
        for(auto h:map)
        {
            int i = h.first;
            int v = h.second;
            if(v!=0)
            {
                for(int j=i;j<=i+groupSize-1;j++)
                {
                    if(map.find(j)!=map.end())
                    {
                        
                        map[j] = map[j]-v;
                        if(map[j]<0)
                        {
                            return false;
                        }
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
        }
        
        for(auto i:map)
        {
            if(i.second>0) return false;
        }
        
        return true;
    }
};
