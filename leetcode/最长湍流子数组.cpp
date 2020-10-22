class Solution {
public:
/*
    static const int N = 40020;
    int dp[N][2];

    int maxTurbulenceSize(vector<int>& A) {
        memset(dp,0x00,sizeof dp);

        int n = A.size();
        int ans = 1;
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i][1] = 1;
            if(A[i] > A[i-1]) dp[i][1] += dp[i-1][0];
            else if(A[i] < A[i-1]) dp[i][0] += dp[i-1][1];

            ans = max(ans,max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
*/

    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int ans = 1;
        int up = 1, down = 1;

        for(int i = 1; i < n; i++) {
            if(A[i] > A[i-1]) up = down + 1, down = 1;
            else if(A[i] < A[i-1]) down = up + 1, up = 1;
            else up = 1, down = 1;

            ans = max(ans,max(up,down));
        }

        return ans;
    }
};

�� A?��������?A[i], A[i+1], ..., A[j]?������������ʱ�����ǳ���Ϊ���������飺

��?i <= k < j���� k?Ϊ����ʱ��?A[k] > A[k+1]���ҵ� k Ϊż��ʱ��A[k] < A[k+1]��
�� ��?i <= k < j���� k Ϊż��ʱ��A[k] > A[k+1]?���ҵ� k?Ϊ����ʱ��?A[k] < A[k+1]��
Ҳ����˵������ȽϷ������������е�ÿ������Ԫ�ض�֮�䷭ת����������������������顣

���� A ���������������ĳ��ȡ�

?

ʾ�� 1��

���룺[9,4,2,10,7,8,8,1,9]
�����5
���ͣ�(A[1] > A[2] < A[3] > A[4] < A[5])
ʾ�� 2��

���룺[4,8,12,16]
�����2
ʾ�� 3��

���룺[100]
�����1
?

��ʾ��

1 <= A.length <= 40000
0 <= A[i] <= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-turbulent-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
