class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        user_follow.clear();
        user_tweet.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!user_tweet.count(userId)){
            vector<pair<int,int> > tweets;
            tweets.push_back(make_pair(time++,tweetId));
            user_tweet[userId] = tweets;
        }else{
            user_tweet[userId].push_back(make_pair(time++,tweetId));
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int> > tweets = user_tweet[userId];
        for(int i=0; i<user_follow[userId].size(); ++i){
            int followId = user_follow[userId][i];
            for(int j=0; j<user_tweet[followId].size(); ++j){
                tweets.push_back(user_tweet[followId][j]);
            }
        }
        sort(tweets.begin(),tweets.end());
        vector<int> res;
        for(int i=tweets.size()-1; i>=0 && res.size() < 10; --i){
            res.push_back(tweets[i].second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(!user_follow.count(followerId)){
            vector<int> follows;
            follows.push_back(followeeId);
            user_follow[followerId] = follows;
        }else{
            for(int i=0; i<user_follow[followerId].size() ;++i) if(user_follow[followerId][i] == followeeId) return;

            user_follow[followerId].push_back(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        for(int i=0; i< user_follow[followerId].size(); ++i){
            if(user_follow[followerId][i] == followeeId){
                user_follow[followerId].erase(user_follow[followerId].begin()+i);
                break;
            }
        }
    }
private:
    int time;
    map<int,vector<int> > user_follow;// uid-> uids
    map<int,vector<pair<int,int> > > user_tweet; //uid-> tweets(time:tid)
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
