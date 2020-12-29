class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //if(k == 0 || n < 2) return 0;

        if(k >= n / 2) return Fun(prices,n);

        int f[n][k+1][2];
        memset(f,0x00,sizeof f);
        for(int j = k; j > 0; j--) {
            f[0][j][0] = 0;
            f[0][j][1] = -prices[0];
        }
        
        for(int i = 1; i < n; i++)
            for(int j = k; j > 0; j--) {
                f[i][j][0] = max(f[i - 1][j][0], f[i-1][j][1] + prices[i]);
                f[i][j][1] = max(f[i - 1][j][1], f[i-1][j-1][0] - prices[i]);
            }

        return f[n-1][k][0];
    }

    int Fun(vector<int>& prices,int n) {
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};
����һ����������?prices �����ĵ� i ��Ԫ��?prices[i] ��һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

?

ʾ�� 1��

���룺k = 2, prices = [2,4,1]
�����2
���ͣ��ڵ� 1 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 2 �� (��Ʊ�۸� = 4) ��ʱ����������ʽ������ܻ������ = 4-2 = 2 ��
ʾ�� 2��

���룺k = 2, prices = [3,2,6,5,0,3]
�����7
���ͣ��ڵ� 2 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 3 �� (��Ʊ�۸� = 6) ��ʱ������, ��ʽ������ܻ������ = 6-2 = 4 ��
     ����ڵ� 5 �� (��Ʊ�۸� = 0) ��ʱ�����룬�ڵ� 6 �� (��Ʊ�۸� = 3) ��ʱ������, ��ʽ������ܻ������ = 3-0 = 3 ��
?

��ʾ��

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
