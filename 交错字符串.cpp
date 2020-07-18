���������ַ���?s1, s2, s3, ��֤?s3?�Ƿ�����?s1?��?s2 ������ɵġ�

ʾ�� 1:

����: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
���: true
ʾ��?2:

����: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
���: false


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool> > dp(n+1,vector<bool> (m+1,false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            if(s1[i-1] == s3[i-1])  dp[i][0] = dp[i-1][0];
            else break;
        
        for(int j = 1; j <= m; j++)
            if(s2[j-1] == s3[j-1])  dp[0][j] = dp[0][j-1];
            else break;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                
                if(s2[j-1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
            }
        return dp[n][m];
    }
};
