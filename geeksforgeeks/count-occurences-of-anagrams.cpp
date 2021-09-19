// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
// Date: 18th September, 2021
// Tags: sliding-window

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int k = pat.size();
	    int n = txt.size();
	   // cout <<  n << ":" << k << endl;
	    int i=0;
	    int j=0;
	    int c=0;
	    vector<int> p(26,0);
	    vector<int> t(26,0);
	    for(auto i: pat)
	    {
	        t[i-'a']++;
	    }
	    while(j<n)
	    {
	        
	        int w = j-i+1;
	        p[txt[j]-'a']++;
	        if(w<k)
	        {
	            j++;
	        }
	        if(w==k)
	        {
	            bool flag = true;
	            for(int x=0;x<26;x++)
	            {
	                if(t[x]!=p[x])
	                {
	                    flag=false;
	                    break;
	                }
	            }
	            if(flag) c++;
	           // cout << "here " << c << endl;
	            j++;
	            p[txt[i]-'a']--;
	            i++;
	        }
	    }
	    
	    return c;
	}

};
