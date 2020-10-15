class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[n + 1][m + 1];
        memset(dp,0x3f,sizeof dp);

        dp[0][0] = 0;
        // s1
        for(int i = 1; i <= n; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        
        // s2
        for(int i = 1; i <= m; i++) dp[0][i] = dp[0][i-1] + s2[i-1];
         
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(s1[i-1] == s2[j-1])  dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
        
        return dp[n][m];
    }
};

���������ַ���s1, s2���ҵ�ʹ�����ַ����������ɾ���ַ���ASCIIֵ����С�͡�

ʾ�� 1:

����: s1 = "sea", s2 = "eat"
���: 231
����: �� "sea" ��ɾ�� "s" ���� "s" ��ֵ(115)�����ܺ͡�
�� "eat" ��ɾ�� "t" ���� 116 �����ܺ͡�
����ʱ�������ַ�����ȣ�115 + 116 = 231 ���Ƿ�����������С�͡�
ʾ��?2:

����: s1 = "delete", s2 = "leet"
���: 403
����: �� "delete" ��ɾ�� "dee" �ַ������ "let"��
�� 100[d]+101[e]+101[e] �����ܺ͡��� "leet" ��ɾ�� "e" �� 101[e] �����ܺ͡�
����ʱ�������ַ��������� "let"�������Ϊ 100+101+101+101 = 403 ��
�����Ϊ�������ַ���ת��Ϊ "lee" �� "eet"�����ǻ�õ� 433 �� 417 �Ľ�����ȴ𰸸���
ע��:

0 < s1.length, s2.length <= 1000��
�����ַ����е��ַ�ASCIIֵ��[97, 122]֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
