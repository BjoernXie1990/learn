class Twitter {
public:
    typedef pair<int,int> PII;
    typedef long long LL;

    unordered_map<int,list<PII> > mp; // user time ����
    unordered_map<int,set<int> > hash;  // ��ע�б�
    int size;
    /** Initialize your data structure here. */
    Twitter() {
        size = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        mp[userId].push_front({size,tweetId});
        size++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<PII,vector<PII>, less<PII> > pq;
        // ��ע����
        for(auto& e : hash[userId]) 
            for(auto& ee : mp[e])   pq.push(ee);
        // �Լ�
        for(auto& e : mp[userId]) 
            pq.push(e);
        
        vector<int> res;
        res.reserve(10);
        while(pq.size() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return ;
        hash[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        hash[followerId].erase(followeeId);
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
 
 
 ���һ���򻯰������(Twitter)���������û�ʵ�ַ������ģ���ע/ȡ����ע�����û����ܹ�������ע�ˣ������Լ��������ʮ�����ġ���������Ҫ֧�����µļ������ܣ�

postTweet(userId, tweetId): ����һ���µ�����
getNewsFeed(userId): ���������ʮ�����ġ�ÿ�����Ķ��������ɴ��û���ע���˻������û��Լ������ġ����ı��밴��ʱ��˳��������Ŀ�ʼ����
follow(followerId, followeeId): ��עһ���û�
unfollow(followerId, followeeId): ȡ����עһ���û�
ʾ��:

Twitter twitter = new Twitter();

// �û�1������һ�������� (�û�id = 1, ����id = 5).
twitter.postTweet(1, 5);

// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
twitter.getNewsFeed(1);

// �û�1��ע���û�2.
twitter.follow(1, 2);

// �û�2������һ�������� (����id = 6).
twitter.postTweet(2, 6);

// �û�1�Ļ�ȡ����Ӧ������һ���б����а����������ģ�id�ֱ�Ϊ -> [6, 5].
// ����id6Ӧ��������id5֮ǰ����Ϊ������5֮���͵�.
twitter.getNewsFeed(1);

// �û�1ȡ����ע���û�2.
twitter.unfollow(1, 2);

// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
// ��Ϊ�û�1�Ѿ����ٹ�ע�û�2.
twitter.getNewsFeed(1);

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-twitter
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
