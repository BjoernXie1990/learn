class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int dp[n + 1];
        memset(dp,0x00,sizeof dp);

        sort(words.begin(),words.end(),[](const string& a,const string& b)->bool{
            return a.size() < b.size();
        });
        unordered_map<string,int> hash;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            hash[words[i]] = i;
            dp[i] = 1;

            string word = words[i];
            int m = word.size();
            if(m == 1) continue;

            for(int j = 0; j < m; j++) {
                string tmp = word.substr(0,j) + word.substr(j+1);
                if(hash.count(tmp)) dp[i] = max(dp[i], dp[hash[tmp]] + 1);
            }

            ans = max(ans,dp[i]);
        }

        return ans;
    }
};


����һ�������б�����ÿ�����ʶ���СдӢ����ĸ��ɡ�

������ǿ�����?word1?���κεط����һ����ĸʹ����?word2����ô������Ϊ?word1?��?word2?��ǰ�����磬"abc"?��?"abac"?��ǰ��

�����ǵ���?[word_1, word_2, ..., word_k]?��ɵ����У�k >= 1������?word_1?��?word_2?��ǰ��word_2?��?word_3?��ǰ���������ơ�

�Ӹ��������б� words ��ѡ�񵥴���ɴ��������ش���������ܳ��ȡ�
?

ʾ����

���룺["a","b","ba","bca","bda","bdca"]
�����4
���ͣ��������֮һΪ "a","ba","bda","bdca"��
?

��ʾ��

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i]?����СдӢ����ĸ��ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-string-chain
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
