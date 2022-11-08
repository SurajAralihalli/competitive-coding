// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-browser-history/
// Date: 8th Nov, 2022
// Tags: stack, string

class BrowserHistory {
public:
    stack<string> pastPages;
    stack<string> futurePages;
    BrowserHistory(string homepage) {
        pastPages.push(homepage);
    }
    
    void visit(string url) {
        pastPages.push(url);
        while(!futurePages.empty())
        {
            futurePages.pop();
        }
    }
    
    string back(int steps) {
        for(int i=0;i<steps && pastPages.size()>1;i++)
        {
            futurePages.push(pastPages.top());
            pastPages.pop();
        }
        return pastPages.top();
    }
    
    string forward(int steps) {
        for(int i=0;i<steps && !futurePages.empty();i++)
        {
            pastPages.push(futurePages.top());
            futurePages.pop();
        }
        return pastPages.top();
        
    }
};
