// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/clone-graph/
// Date: 10th July, 2022
// Tags: graph, dfs


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* ,Node*> map;
    Node* cloneGraph(Node* node) {
        
        if(node) 
        {
            dfs(node);
            return map[node];
        }
        return NULL;
        
    }
    void dfs(Node* node)
    {
        // visited already
        if(map.find(node)!=map.end())
        {
            return;
        }
        else
        {
            Node* cloneNode = new Node(node->val);
            // mark visited
            map[node] = cloneNode;
            // dfs
            for(auto neighbour: node->neighbors)
            {
                dfs(neighbour);
                cloneNode -> neighbors.push_back(map[neighbour]);
            }
            return;
        }
        
    }
};
