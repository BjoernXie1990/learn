class Solution {
public:
    int numSquares(int n) {
        vector<int> f;      // ��ȫƽ����
        for(int i = 1; i * i <= n; i++) f.push_back(i*i);

        // �������� dp[n] ��ʾ����Ϊn ʱ����С����
        // ��ȫ������ÿ����Ʒ����������
        int dp[n+1];
        memset(dp,0x3f,sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < f.size(); i++) {
            for(int j = f[i]; j <= n; j++)
                dp[j] = min(dp[j],dp[j - f[i]] + 1);
        }

        return dp[n];
    }
};


����������?n���ҵ����ɸ���ȫƽ����������?1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�

ʾ��?1:

����: n = 12
���: 3 
����: 12 = 4 + 4 + 4.
ʾ�� 2:

����: n = 13
���: 2
����: 13 = 4 + 9.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/perfect-squares
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
