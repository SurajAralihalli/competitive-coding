// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Date: 24th August, 2022
// Tags: stack, greedy, monotonic-stack

//Approach 2
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Date: 24th August, 2022
// Tags: stack, greedy, monotonic-stack


//Approach 2
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = -1;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            maxi = max(maxi, arr[i]);
            if(i==maxi)
            {
                count++;
            }
        }
        return count;
    }
};


//Approach 1
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i=0; i<arr.size(); i++)
        {
            map[arr[i]] = i;
        }
        
        int maxIndex = -1;
        int count = 0;
        bool sortedTillNow = true;
        for(int i=0; i<arr.size(); i++)
        {
            
            if(map[i] == i && map[i]>maxIndex)
            {
                count++;
                sortedTillNow = true;
            }
            else if(map[i] > maxIndex)
            {
                maxIndex = max(maxIndex, map[i]);
                
                if(sortedTillNow == true) count++;
                sortedTillNow = false;
                
            }
            else if(map[i] < maxIndex)
            {
                // do nothing
            }
            
            if(i==maxIndex)
            {
                sortedTillNow = true;
            }
            
        }
        
        return count;
    
    }
};
