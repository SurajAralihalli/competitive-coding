// Author: Suraj Aralihalli
// Url: https://www.interviewbit.com/problems/meeting-rooms/
// Date: 17th July, 2022
// Tags: greedy, intervals

bool sortAsc(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

int Solution::solve(vector<vector<int> > &A) {
    
    //minHeap
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > minHeap;
    
    // sort based on Start times
    sort(A.begin(), A.end(), sortAsc);
    
    int n = A.size();
    minHeap.push({A[0][1], A[0]});
    
    for(int i=1;i <n; i++)
    {
        vector<int> top = minHeap.top().second;
        vector<int> cur = A[i];
        // check compatible
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
