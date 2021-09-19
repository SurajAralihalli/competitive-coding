// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
// Date: 18th September, 2021
// Tags: sliding-window

public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0;
        int j=0;
        int sum=0;
        int maxi = INT_MIN;
        // sum+= Arr[0];
        while(j<N)
        {
            int w = j-i+1;
            if(w<K)
            {
                sum+= Arr[j];
                j++;
            }
            else if(w==K)
            {
                sum+= Arr[j];
                j++;
                maxi = max(sum,maxi);
                // cout << j << " " << sum << endl;
                sum-= Arr[i];
                i++;
                // cout << sum << endl;
                
                
            }
        }
        return maxi;
    }
};
