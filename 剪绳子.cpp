����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��

ʾ�� 1��

����: 2
���: 1
����: 2 = 1 + 1, 1 �� 1 = 1
ʾ��?2:

����: 10
���: 36
����: 10 = 3 + 3 + 4, 3 ��?3 ��?4 = 36
��ʾ��

2 <= n <= 58

class Solution {
public:
    int cuttingRope(int n)
    {
        vector<int> dp(n+1,0);
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
            for(int j = 1; j < i; j++)
                dp[i] = max(dp[i],max(j,dp[j]) * (i - j));
        return dp[n];
    }

    int cuttingRope1(int n) {
        if(n <= 3) return n-1;

        int div = n / 3;
        int rem = n % 3;
        int ret = 1;

        for(int i = 0; i < div; i++)
        {
            ret *= (i < div - 1) ? 3 : (rem == 2 ? 3*rem : (3 + rem));
        }

        return ret;
    }
};
