class Solution {
public:
    const int mod = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp,0x00,sizeof dp);
        for(int i = 1; i <= n; i++) dp[i][i] = 1;   // i-i��ɵĻ��Ĵ�Ϊ1��

        for(int len = 2; len <= n; len ++)  // ���䳤��
            for(int i = 1; i <= n; i ++) {  // ���������
                int j = i + len - 1;
                if(j > n) break;
                if(s[i-1] != s[j-1]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod ;
                    dp[i][j] = (dp[i][j] + (mod - dp[i + 1][j - 1]) % mod) % mod ;
                    continue;
                }

                // s[i-1] == s[j-1]
                int le = i + 1, ri = j - 1;
                while(le < j && s[le - 1] != s[i - 1]) le++;
                while(ri > i && s[ri - 1] != s[i - 1]) ri--;

                // +2 ����Ϊ s[i-1]�� s[i-1]s[j-1] Ҳ���Ǳ��м��������2������
                if(ri < le) dp[i][j] = (dp[i+1][j-1]*2 + 2) % mod;          // i-j û�к� s[i-1]��ͬ����ĸ��aba
                else if(le == ri) dp[i][j] = (dp[i+1][j-1] * 2 + 1) % mod;  // ֻ��һ����ͬ��ĸ  aaa
                else dp[i][j] = (dp[i + 1][j - 1] * 2 % mod + (mod - dp[le + 1][ri - 1])) % mod ;  // ����2��
            }

        return dp[1][n];
    }
};

����һ���ַ��� S���ҳ� S �в�ͬ�ķǿջ��������и����������ظ������� 10^9 + 7 ��ģ��

ͨ���� S ��ɾ�� 0 �������ַ�����������С�

���һ���ַ�����������ת����ַ�����һ�£���ô���ǻ����ַ����С�

�������ĳ��??i��A_i != B_i����ô?A_1, A_2, ... ��?B_1, B_2, ... �������ַ������ǲ�ͬ�ġ�

?

ʾ�� 1��

���룺
S = 'bccb'
�����6
���ͣ�
6 ����ͬ�ķǿջ������ַ����зֱ�Ϊ��'b', 'c', 'bb', 'cc', 'bcb', 'bccb'��
ע�⣺'bcb' ��Ȼ�������ε�������һ�Ρ�
ʾ�� 2��

���룺
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
�����104860361
���ͣ�
���� 3104860382 ����ͬ�ķǿջ��������У��� 10^9 + 7 ȡģΪ 104860361��
?

��ʾ��

�ַ���?S?�ĳ��Ƚ���[1, 1000]��Χ�ڡ�
ÿ���ַ�?S[i]?�����Ǽ���?{'a', 'b', 'c', 'd'}?�е�ĳһ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-different-palindromic-subsequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
