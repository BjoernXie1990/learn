����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���

���ط���Ҫ������ٷָ������

ʾ��:

����:?"aab"
���: 1
����: ����һ�ηָ�Ϳɽ�?s �ָ�� ["aa","b"] �������������Ӵ���

class Solution {
public:
    int len = 0;
    int minCut(string s) {
        len = s.size();
        if(len < 2) return 0;

        vector<int> dp(len,0);
        for(int i = 0; i < len; i++)
            dp[i] = i;

        for(int i = 0; i < len; i++)
        {
            merge(s,i,i,dp);
            merge(s,i,i+1,dp);
        }
  
        return dp[len-1];
    }

    inline void merge(string& s,int le,int ri,vector<int>& dp)
    {
        while(le >= 0 && ri < len && s[le] == s[ri])
        {
            dp[ri] = min(dp[ri],((le == 0) ? 0 : (dp[le-1] + 1)));
            ri++;
            le--;
        }
    }
};
