// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/closest-dessert-cost/description/
// Date: 17th Feb, 2023
// Tags: backtracking

class Solution {
public:
    int target;
    int closestSum;
    int closest(int a,int b){ 
        if(a==0)
            return b;
        if(b==0)
            return a;
        if(abs(target-a)==abs(target-b))
            return a<b?a:b;
        return abs(target-a)<abs(target-b)?a:b;
    }
    
    void dfs(vector<int>&top,int index,int sum){

        closestSum = closest(sum, closestSum);

        if(sum>=target) {
            return;
        }
        else {
            for(int i=index; i < top.size(); i++) {
                dfs(top,i+1,sum+top[i]);
                dfs(top,i+1,sum+(top[i]*2));
            }
        }

        return;
    }
    
    int closestCost(vector<int>& base, vector<int>& top, int t) {
        target=t;//i made target global so that i don't need to pass it in any function
        int ans=0;
        for(int i=0;i<base.size();i++){
            dfs(top, 0, base[i]);
        } 
        return closestSum;
    }
};
