// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-twitter/
// Date: 9th Oct, 2022
// Tags: array, hashing

class Twitter {
public:
    unordered_map<int, unordered_set<int>> fmap;
    list<pair<int, int>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=0;
        vector<int> top10;
        for(auto i=tweets.rbegin();i!=tweets.rend();i++)
        {
            // if follows
            if(fmap[userId].find(i->first)!=fmap[userId].end() || userId == i->first)
            {
                top10.push_back(i->second);
                count++;
            }
            if(count==10)
            {
                break;
            }
        }
        
        return top10;
    }
    
    void follow(int followerId, int followeeId) {
        fmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         fmap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
