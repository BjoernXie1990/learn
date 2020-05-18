//����һ�����飬���ĵ� i ��Ԫ����һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�

//���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�

//ע��:?�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

//ʾ��?1:

//����: [2,4,1], k = 2
//���: 2
//����: �ڵ� 1 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 2 �� (��Ʊ�۸� = 4) ��ʱ����������ʽ������ܻ������ = 4-2 = 2 ��
//ʾ�� 2:

//����: [3,2,6,5,0,3], k = 2
//���: 7
//����: �ڵ� 2 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 3 �� (��Ʊ�۸� = 6) ��ʱ������, ��ʽ������ܻ������ = 6-2 = 4 ��
//?    ����ڵ� 5 �� (��Ʊ�۸� = 0) ��ʱ�����룬�ڵ� 6 �� (��Ʊ�۸� = 3) ��ʱ������, ��ʽ������ܻ������ = 3-0 = 3 ��

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(k == 0 || len < 2) return 0;

        //ת��Ϊһ��̰������
        if(k >= len / 2) return Fun(prices);

        int dp[len][k+1][2];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < len; i++)
            for(int j = k; j > 0; j--)
                if(i == 0)
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0 - prices[i]; 
                }
                else
                {
                    dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0] - prices[i]);
                }
        return dp[len-1][k][0];
    }

    int Fun(vector<int>& prices)
    {
        int ans = 0;
        int len = prices.size();
        for(int i = 1; i < len; i++)
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        return ans;
    }

};
