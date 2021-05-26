// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/course-schedule/
// Date: 26th May, 2021
// Tags: dfs, graph, toposort

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    vector<int> visited(numCourses,0);
    vector< vector<int> > matrix;
    vector<int> order;
    vector<int> instack(numCourses,0);
    order.reserve(numCourses);
    matrix.assign(numCourses,vector<int>(numCourses,0));
    bool isCycle = false;
    
    for(auto i : prerequisites)
    {
        matrix[i[0]][i[1]]=1;
    }
    
    for(int i=0;i<numCourses;i++)
    {
        if(visited[i]==0)
        {
            dfs_visit(i, matrix, order, visited, instack, isCycle);
        }
    }
    
    return !isCycle;
    }
    
    static void dfs_visit(int node, vector< vector<int> >& matrix,vector<int>& order,vector<int>& visited,vector<int> & instack, bool& isCycle)
    {
        visited[node]=1;
        instack[node]=1;
        for(int i=0;i<visited.size();i++)
        {
            if(matrix[node][i]==1)
            {
                if(visited[i]==0)
                {
                    dfs_visit(i,matrix,order,visited,instack, isCycle);
                }
                // there is a cycle
                else if(instack[i]==1)
                {
                    isCycle = true;
                }
            }
        }
        instack[node]=0;
        // gives the order
        order.push_back(node);
    }
    
};