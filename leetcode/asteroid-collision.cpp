// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/asteroid-collision/
// Date: 15th Nov, 2021
// Tags: stk

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto i: asteroids)
        {
            int asteroid = i;
            bool asteroidAlive = true;
            while(!stk.empty() && (stk.top()>0 && asteroid<0))
            {
                int top = stk.top();
                if(abs(asteroid)>top)
                {
                    stk.pop();
                }
                else if(abs(asteroid)==top)
                {
                    stk.pop();
                    asteroidAlive = false;
                    break;
                }
                else
                {
                    asteroidAlive = false;
                    break;
                }
            }
            if(asteroidAlive == true)
            {
                stk.push(asteroid);
            }
        }
        
        vector<int> vec;
        while(!stk.empty())
        {
            vec.push_back(stk.top());
            stk.pop();
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
