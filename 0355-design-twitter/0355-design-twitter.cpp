static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Twitter {
    unordered_map<int,unordered_map<int,bool>>follows; //UserID->{OtherUserID->true/false}
    vector<pair<int,int>>posts; //UserID and TweetID, most recent post at the end

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count=0;
        for(int i=posts.size()-1; i>=0 and count<10; --i){
            if(posts[i].first==userId || follows[userId][posts[i].first]){
                feed.push_back(posts[i].second);
                ++count;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId]=true;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId]=false;
    }
};








/*
class Twitter {
public:
    map<int, set<int>> friends;
    int curr=0;
    priority_queue<vector<int>>timeline;
    Twitter() {
        friends.clear();
        curr = 0;
        timeline = priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({curr++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>> userTimeline=timeline;
        int n = 0;
        while(!userTimeline.empty() && n < 10) {
            auto topTweet = userTimeline.top();
            userTimeline.pop(); 
            if(topTweet[2] == userId || friends[userId].count(topTweet[2])){
                ans.push_back(topTweet[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
 */

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */