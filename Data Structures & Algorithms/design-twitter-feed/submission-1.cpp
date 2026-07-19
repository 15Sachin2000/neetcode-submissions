class Twitter {
public:
    unordered_map<int,set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int count;
    Twitter() {
        count=0;
    }

    // void checkAndCreateEntry(int userId){
    //     if(mp.find(userId)==mp.end()){
    //         vector<vector<int>> v(2);
    //         mp[userId]=v;
    //     }
    // }
    
    void postTweet(int userId, int tweetId) {
        // checkAndCreateEntry(userId);
        // mp[userId][1].push_back(tweetId)
        if(tweets.find(userId)==tweets.end()){
            vector<pair<int,int>> p;
            tweets[userId]=p;
        }
        tweets[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
        if(tweets.find(userId)!=tweets.end()){
            for(pair<int,int> p:tweets[userId]){
                pq.push(p);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
        if(followers.find(userId)!=followers.end()){
            for(auto u:followers[userId]){
                if(tweets.find(u)!=tweets.end() && u!=userId){
            for(pair<int,int> p:tweets[u]){
                pq.push(p);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto p=pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // if(followers.find(followerId)==followers.end()){
        //     set<int> s
        //     followers[followerId]=s;
        // }
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
