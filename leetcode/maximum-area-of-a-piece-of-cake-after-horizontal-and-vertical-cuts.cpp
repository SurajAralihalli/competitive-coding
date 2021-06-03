// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Date: 3rd June, 2021
// Tags: array, mod, fmod, pow


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        if(horizontalCuts[0]!=0){
            horizontalCuts.insert(horizontalCuts.begin(),0);
        }
        
        if(verticalCuts[0]!=0){
            verticalCuts.insert(verticalCuts.begin(),0);
        }
        
        if(horizontalCuts.back()!=h){
            horizontalCuts.push_back(h);
        }
        
        if(verticalCuts.back()!=w){
            verticalCuts.push_back(w);
        }
        
        int max_w = 0;
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            max_w = max(max_w,horizontalCuts[i+1]-horizontalCuts[i] );
        }
        
        int max_h = 0;
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            max_h = max(max_h,verticalCuts[i+1]-verticalCuts[i] );
        }
        cout << max_w  <<" "<< max_h << endl;
        
        double area = double(max_w)*double(max_h);
        double mod = ((pow(10,9) + 7));
        
        return int(fmod(area,mod));
    }
};