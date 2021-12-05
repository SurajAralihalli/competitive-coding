
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/most-frequent-subtree-sum/
// Date: 5th December, 2021
// Tags: trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> map;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        recursiveSum(root);
        vector<pair<int,int>> temp;
        vector<int> sol;
        for(auto i : map)
        {
            temp.push_back({i.first, i.second});
        }
        sort(temp.begin(),temp.end(),comp);
        int n = temp.size();
        int maxi = temp[0].second;
        for(int i=0;i<n;i++)
        {
            if(temp[i].second == maxi)
            {
                sol.push_back(temp[i].first);
                
            }
            else
            {
                break;
            }
        }
        
        return sol;
        
    }
    
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
    int recursiveSum(TreeNode* root)
    {
        if(root!=NULL)
        {
            int l = recursiveSum(root->left);
            int r = recursiveSum(root->right);
            int sum = l + r + root-> val;
            if(map.find(sum)==map.end())
            {
                map[sum] = 1;
                
            }
            else
            {
                map[sum]++;
            }
            return sum;
        }
        return 0;
    }
};
