// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
// Date: 18th September, 2021
// Tags: sliding-window

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0;
        int j=0;
        int sum=0;
        int maxi = INT_MIN;
        
        
        
        while(j<N)
        {
            int w = j-i+1;
            sum+= Arr[j];
            if(w<K)
            {
                j++;
            }
            else if(w==K)
            {
                
                maxi = max(sum,maxi);
                // cout << j << " " << sum << endl;
                sum-= Arr[i];
                i++;
                j++;
                // cout << sum << endl;
                
                
            }
        }
        return maxi;
    }
};
