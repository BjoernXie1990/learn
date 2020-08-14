���������ַ���S��T������S�����е���T�Ĳ�ͬ�����и����ж��ٸ���
�ַ���������������ԭ�����ַ���ɾ��һЩ�ַ���Ҳ���Բ�ɾ�����ڲ��ı����λ�õ�����µ�ʣ���ַ������磬"ACE"is a subsequence of"ABCDE"����"AEC"���ǣ�
���磺
S ="rabbbit", T ="rabbit"

class Solution {
public:
    /**
     * 
     * @param S string�ַ��� 
     * @param T string�ַ��� 
     * @return int����
     */
    int numDistinct(string S, string T) {
        // write code here
        int n = S.size();
        int m = T.size();
        
        int dp[n+1][m+1];
        memset(dp,0x00,sizeof(dp));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
        
        return dp[n][m];
    }
};
