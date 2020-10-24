class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        else if(n == 10) return 10;

        int dp[n + 1];        // dp[i] ��ʾ�� i λ�ж��ٲ�ͬ������x�ĸ���
        memset(dp,0x00,sizeof dp);
        dp[0] = 1;
        dp[1] = 10;
        // n == 0  0        ans = 1;
        // n == 1  1~9      ans = 9 + dp[0]
        // n == 2  ʮλ 1~9  ��Ӧ�ĸ�λ�� 0~9 - 1 �����  ans = 9 * 9 + dp[1]
        // n == 3  ��λ 1~9  ��Ӧ��ʮλ�� 0~9 - 1 �����  ��λ��0~9 - 2 �����  ans = 9 * 9 * 8 + dp[2]

        // dp[i] = dp[i-1] + (����ǰһ��״̬�У���ͬ�����ָ���) * ��ǰλ�����
        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - i + 1);

        return dp[n];
    }
};

����һ���Ǹ����� n�������λ���ֶ���ͬ������ x �ĸ��������� 0 �� x < 10n?��

ʾ��:

����: 2
���: 91 
����: ��ӦΪ��ȥ 11,22,33,44,55,66,77,88,99 �⣬�� [0,100) �����ڵ��������֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-numbers-with-unique-digits
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
