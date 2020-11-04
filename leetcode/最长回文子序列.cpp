class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int f[n+1][n+1];
        memset(f,0x00,sizeof f);

        for(int i = 0; i <= n; i++) f[i][i] = 1;

        for(int i = n - 1; i > 0; i--)
            for(int j = i + 1; j <= n; j++) {
                if(s[i-1] == s[j-1]) f[i][j] = f[i+1][j-1] + 2;
                else f[i][j] = max(f[i+1][j],f[i][j-1]);
            }
        return f[1][n];
    }
};


����һ���ַ��� s ���ҵ�������Ļ��������У������ظ����еĳ��ȡ����Լ��� s ����󳤶�Ϊ 1000 ��

?

ʾ�� 1:
����:

"bbbab"
���:

4
һ�����ܵ������������Ϊ "bbbb"��

ʾ�� 2:
����:

"cbbd"
���:

2
һ�����ܵ������������Ϊ "bb"��

?

��ʾ��

1 <= s.length <= 1000
s ֻ����СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-palindromic-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
