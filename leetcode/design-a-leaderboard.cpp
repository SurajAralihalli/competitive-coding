// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-a-leaderboard/
// Date: 6th Nov, 2022
// Tags: hahs, hash-table

class Leaderboard {
public:
    set<pair<int,int>, greater<pair<int,int>>> mySet;
    unordered_map<int,int> idScore;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        mySet.erase({idScore[playerId],playerId});
        idScore[playerId]+=score;
        mySet.insert({idScore[playerId],playerId});
    }
    
    int top(int K) {
        int count =0;
        for(auto i=mySet.begin();i!=mySet.end() && K!=0; i++)
        {
            count+= i->first;
            K--;
        }
        return count;
    }
    
    void reset(int playerId) {
        mySet.erase({idScore[playerId],playerId});
        idScore[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
