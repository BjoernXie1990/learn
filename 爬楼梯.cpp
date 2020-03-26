//������������¥�ݡ���Ҫ n ������ܵ���¥����

//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

//ע�⣺���� n ��һ����������

class Solution {
public:
    //�ݹ�
    int climbStairs1(int n) {
        if(n < 3)
            return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
    //��̬�滮
    int climbStairs(int n) {
        if(n < 3)
            return n;
        int* dp = (int*)malloc(sizeof(int) * n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int num = dp[n-1];
        free(dp);
        return num;
    }
};
