// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/decode-ways/
// Date: 10th September, 2021
// Tags: dp


class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        
        int n = s.size();
        dp.assign(n+1,-1);
        decode(s,0,n);
        // for(auto i:dp)
        // {
        //     cout << i << endl;
        // }
        return dp[0];
    }
    int decode(string s, int i, int n)
    {
        
        int ans;
        if(i>n)
        {
            return 0;
        }
        else if(i==n)
        {
            // cout << "just end of string" << endl;
            return 1;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        else if((int(s[i]) - int('1') +1 )>2)
        {
            // cout << ">2 case" << endl;
            ans = decode(s,i+1,n);
        }
        else if((int(s[i]) - int('1') + 1)>0)
        {
            // cout << "1 & 2 case" << endl;
            ans = decode(s,i+2,n);
            if((stoi(s.substr(i,2)))<27)
            {
                ans += decode(s,i+1,n);
            }
        }
        else
        {
            // cout << "0 case" << endl;
            ans =0;
        }
        
        dp[i] = ans;
        return dp[i];
    }
};




##################################################################################################################
## Alternative Itrative Logic


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        if(n>0 && s[0]!='0')
        {
            dp[0]=1;
        }
        for(int i=1;i<n;i++)
        {

                if(s[i-1]>'2' && s[i]!='0')
                {
                    dp[i] = dp[i-1];
                }
                else
                {
                    
                    if(s[i]=='0')
                    {
                        if(s[i-1]>'2' || s[i-1]=='0') return 0;
                        if(i>=2) dp[i] = dp[i-2];
                        else dp[i] = dp[i-1];
                    }
                    else
                    {
                        dp[i] = dp[i-1];
                        if(((s[i-1]=='2' && s[i]<'7') || s[i-1]=='1'))
                        {
                            if(i>=2) dp[i]+= dp[i-2];
                            else dp[i]+=1;
                        }
                    }

                }
            
            // for(auto i:dp)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
        }
        
        
        
        return dp[n-1];
    }
};
