������ͬ����Ӳ�Һ�һ���ܽ�д��������������Դճ��ܽ���Ӳ�������������ÿһ������Ӳ�������޸���?

?

ʾ�� 1:

����: amount = 5, coins = [1, 2, 5]
���: 4
����: �����ַ�ʽ���Դճ��ܽ��:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
ʾ�� 2:

����: amount = 3, coins = [2]
���: 0
����: ֻ�����2��Ӳ�Ҳ��ܴճ��ܽ��3��
ʾ�� 3:

����: amount = 10, coins = [10] 
���: 1
?

ע��:

����Լ��裺

0 <= amount (�ܽ��) <= 5000
1 <= coin (Ӳ�����)?<= 5000
Ӳ�����಻���� 500 ��
������� 32 λ��������


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0x00,sizeof(dp));
        dp[0] = 1;

        int n = coins.size();
        sort(coins.begin(),coins.end());
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
