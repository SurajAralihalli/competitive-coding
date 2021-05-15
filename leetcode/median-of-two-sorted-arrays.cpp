// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Date: 15th May, 2021

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> nums3;
        nums3.reserve(nums1.size()+nums2.size());
        int s1 = nums1.size();
        int s2 = nums2.size();
        int l1 = 0;
        int l2 = 0;
        while(l1<s1 || l2<s2)
        {
            int a;
            int b;
            if(l1<s1)
            {
                a = nums1[l1];
            }
            if(l2<s2)
            {
                b = nums2[l2];
            }
            
            if(l1<s1 && l2<s2)
            {
                int mini = min(a,b);
                nums3.push_back(mini);
                if(a==mini)
                {
                    l1++;
                }
                else
                {
                    l2++;
                }
            }
            else if(l1<s1)
            {
                nums3.push_back(a);
                l1++;
            }
            else
            {
                nums3.push_back(b);
                l2++;
            }
            
        }
        for(int i=0;i<nums3.size();i++)
        {
            cout << nums3[i] << " ";
        }
        cout << endl;
        
        
        double median;
        if((s1+s2)%2!=0)
        {
            median = (double)nums3[((s1+s2)/(int)2)];
            // cout << nums3[((s1+s2)/(int)2)];
        }
        else
        {
            median = (nums3[((s1+s2)/(int)2)-1] + nums3[((s1+s2)/(int)2)])/double(2);
            // cout << nums3[(s1+s2)/(int)2] << " " <<  nums3[((s1+s2)/(int)2)+1];
        }
        
        
        return median;
        
    }
};