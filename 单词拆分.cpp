����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж�?s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�

˵����

���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��

����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
ʾ�� 2��

����: s = "applepenapple", wordDict = ["apple", "pen"]
���: true
����: ���� true ��Ϊ "applepenapple" ���Ա���ֳ� "apple pen apple"��
?    ע��������ظ�ʹ���ֵ��еĵ��ʡ�
ʾ�� 3��

����: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
���: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1,false);
        unordered_set<string> m(wordDict.begin(),wordDict.end());
        dp[0] = true;

        //��󵥴ʳ���
        int maxLen = 0;
        for(auto& str : wordDict)
            maxLen = max(maxLen,(int)str.size());

        for(int i = 1; i <= len; i++)
            for(int j = max(0,i-maxLen); j < i; j++)
                if(dp[j] && m.find(s.substr(j,i-j)) != m.end())
                {
                    dp[i] = true;
                }    

        return dp[len];
    }

};
