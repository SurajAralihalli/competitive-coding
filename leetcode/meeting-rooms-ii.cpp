// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/meeting-rooms-ii/
// Date: 6th Nov, 2022
// Tags: greedy, intervals, interval

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //minHeap
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > minHeap;
    
        // sort based on Start times
        sort(intervals.begin(), intervals.end(), sortAsc);

        int n = intervals.size();
        minHeap.push({intervals[0][1], intervals[0]});

        for(int i=1;i <n; i++)
        {
            vector<int> top = minHeap.top().second;
            vector<int> cur = intervals[i];
            // check compatible
            
            // curStart time > topEnd time
            if(cur[0]>=top[1])
            {
                minHeap.pop();
                minHeap.push({cur[1], cur});
            }
            else
            {
                minHeap.push({cur[1], cur});
            }
        }

        return minHeap.size();
    }
    
    static bool sortAsc(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
};
