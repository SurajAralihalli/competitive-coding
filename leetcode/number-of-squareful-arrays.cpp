// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-squareful-arrays/description/
// Date: 18th Feb, 2023
// Tags: backtracking, multi-set

class Solution {
public:
    multiset<int> used;
    multiset<int> total;
    set<vector<int>> sol;
    int count;
    bool isValid(int a, int b) {
        int temp = sqrt(a+b);
        return ((temp*temp) == (a+b));
    }
    int numSquarefulPerms(vector<int>& nums) {
        count = 0;
        vector<int> vec;
        sort(nums.begin(), nums.end());
        for(auto i: nums) {
            total.insert(i);
        }
        dfs(nums, vec);
        return count;
    }

    void dfs(vector<int>& nums, vector<int>& vec) {
        int n = nums.size();

        if(vec.size() == n){
            count++;
            for(auto i : vec) {
                cout << i << " ";
            }
            cout << endl;
            return;
        }

        int prev = -1;
        for(auto i: nums) {
            if(i == prev) continue;

            if(used.count(i) < total.count(i)) {
                if(vec.empty()) {
                    vec.push_back(i);
                    used.insert(i);
                    dfs(nums, vec);
                    used.erase(used.lower_bound(i)); // erase one element
                    vec.pop_back();
                }
                else {
                    if(isValid(i, vec.back())) {
                        vec.push_back(i);
                        used.insert(i);
                        dfs(nums, vec);
                        used.erase(used.lower_bound(i)); // erase one element
                        vec.pop_back();
                    }
                }
            }

            prev = i;
        }
    }   
};
