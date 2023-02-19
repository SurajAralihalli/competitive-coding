// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/car-pooling/description/
// Date: 19th Feb, 2023
// Tags: greedy, intervals, interval

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), sortAsc);
        // for(auto i:trips) {
        //     cout << i[0] << " " << i[1] << " " << i[2] <<endl;
        // }
        priority_queue< pair<int, vector<int>> , vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        int cap = capacity;
        if(trips[0][0] <= cap) {
            cap -= trips[0][0];
            pq.push({trips[0][2], trips[0]});
        }
        else {
            return false;
        }
        int n = trips.size();
        for(int i=1; i < n; i++ ) {
            auto new_trip = trips[i];
            
            while(!pq.empty() && pq.top().second[2] <= new_trip[1])
            {
                cap += pq.top().second[0] ;
                pq.pop() ;
            }
            
			//step - 2
            pq.push({new_trip[2], new_trip});

            cap-=new_trip[0] ;
			
			//step - 3
            if(cap<0){
                return false ;
            }
                
        }

        return true;
    }

    static bool sortAsc(vector<int>& lhs, vector<int>& rhs) {
        return lhs[1]<rhs[1] || (lhs[1]==rhs[1] && lhs[2]<rhs[2]);
    }
};
