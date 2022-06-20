
// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/
// Date: 20th June, 2022
// Tags: sliding-window

// postive numbers only
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int i =0;
        int j =0;
        int sum = 0;
        int maxWindowSize = 0;
        while(j<N)
        {
            sum += A[j];
            int w = j-i+1;
            if(sum==K)
            {
                maxWindowSize = max(maxWindowSize, w);
                j++;
            }
            else if(sum<K)
            {
                j++;
            }
            else 
            {
                while(sum<=K)
                {
                    sum -= A[i];
                    i++;
                }
                j++;
            }
            
        }
        
        return maxWindowSize;
    } 

};


// with negative numbers too
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int i =0;
        int j =0;
        int sum = 0;
        int maxWindowSize = 0;
        unordered_map<int,int> map;
        
        // initialize cumulative sum
        map[0] = -1;
        
        for(int i=0;i<N;i++)
        {
            sum += A[i];
            
            if(map.find(sum) == map.end()) 
            {
                map[sum] = i;
            }
            
            int reqSum = sum - K;
            
            if(map.find(reqSum)!=map.end())
            {
               int windowSize = i - map[reqSum];
               maxWindowSize = max(maxWindowSize, windowSize);
            }
        }
        
        
        return maxWindowSize;
    } 

};

