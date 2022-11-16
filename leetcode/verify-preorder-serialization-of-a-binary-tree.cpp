// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Date: 15th Nov, 2021
// Tags: dfs, string preorder, serialize

class Solution {
public:
    bool isValid;
    int n;
    bool isValidSerialization(string preorder) {
        isValid = true;
        n = preorder.size();
        
        vector<string> preorderList;
        
        stringstream ss(preorder);
        string token;
        while(getline(ss, token, ','))
        {
            preorderList.push_back(token);
        }
        
        int index=0;
        deserialize(preorderList, index);
        
        if(index!=preorderList.size()-1)
        {
            isValid = false;
        }
        
        return isValid;
        
    }
    
    void deserialize(vector<string> &preorderList, int &index)
    {
        if(index<preorderList.size())
        {
            if(preorderList[index]!="#")
            {
                index++;
                if(index >= preorderList.size())
                {
                    isValid = false;
                }
                deserialize(preorderList, index);
                
                index++;
                if(index >= preorderList.size())
                {
                    isValid = false;
                }
                deserialize(preorderList, index);
            }
            else
            {
                //pass
            }
        }
    }
};
