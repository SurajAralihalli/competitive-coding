// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/the-skyline-problem/
// Date: 10th September, 2021
// Tags: skyline

// This code failed with memory exceeded error
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector< vector <int> > arr;
        vector< vector <int> > ans;
        vector<int> temp;
        int n = buildings.size();
        
        int mini = buildings.front()[0];
        long long maxi = buildings.back()[1];
        temp.assign(maxi+2,0);
        for(auto b: buildings)
        {
            for(int i=b[0];i<=b[1];i++)
            {
                if(temp[i]<b[2] || (temp[i+1]<b[2] && i+1 <= b[1]))
                {
                    temp[i] = b[2];
                }
            }
        }
        
        for(int i=1;i<maxi+2;i++)
        {
            if(temp[i]==0 && i-1>=0)
            {
                temp[i-1]=0;
            }
            
        }
        
        for(auto i: temp)
        {
            cout << i << " ";
        }
         // for(int i=0;i<maxi+2;i++)
         // {
         //     cout << i << " " << temp[i] << " ";
         // }
        cout << endl;
        // cout << "bool calculate "<< int(temp[0]!=0) << endl;
        for(int i=0;i<maxi+2;i++)
        {
            cout << i << endl;
            // cout << "bool calculate "<< int(temp[0]!=0) << endl;
            if( (i==0) )
            {   
                if(int(temp[0]!=0))
                {
                    // cout << "here" << endl;
                    ans.push_back({i,temp[i]});
                }
                
            }
            else if(temp[i]!=temp[i-1])
            {
                ans.push_back({i,temp[i]});
            }
        }
        
        return ans;
    }
    
    static bool sort_f(vector<int> a, vector<int> b)
    {
        return a[0] <= b[0];
    }
};
