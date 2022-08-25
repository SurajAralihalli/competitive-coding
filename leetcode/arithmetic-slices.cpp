// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/arithmetic-slices/
// Date: 24th August, 2022
// Tags: array, dp

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=1;
        int sol=0;
        int n = nums.size();
        if(n<3) return 0;
        int diff=nums[1]-nums[0];
        for(int i=1;i<n;i++)
        {
            cout << i << " " << count << endl;
            if(nums[i]-nums[i-1]==diff)
            {
                count++;
            }
            else
            {
                if(count>=3)
                {
                   sol += (count-2)*(count+1) - ((count*(count+1)/2) - 3);
                }
                
                count=2;
                diff = nums[i]-nums[i-1];
            }
            
        }
        if(count!=0)
        {
            sol += (count-2)*(count+1) - ((count*(count+1)/2) - 3);
        }
        return sol;
    }
};
