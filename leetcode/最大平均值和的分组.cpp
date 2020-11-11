class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        double f[n+1][K+1];
        double sum[n+1];
        memset(sum,0x00,sizeof sum);
        memset(f,0x00,sizeof f);

        for(int i = 1; i <= n; i++) {
            sum[i] = A[i-1] + sum[i-1];
            f[i][1] = sum[i] / i;
        }

        for(int i = 1; i <= n; i++)
            for(int k = 2; k <= K; k++)
                for(int j = 0; j < i; j++)
                    f[i][k] = max(f[i][k],f[j][k-1] + (sum[i] - sum[j]) / (i - j));
        
        return f[n][K];
    }
};


���ǽ�����������?A?�ֳ�?K?�����ڵķǿ������� �����ǵķ�����ÿ���������ڵ�ƽ��ֵ���ܺ͹��ɡ������������ܵõ����������Ƕ��١�

ע�����Ǳ���ʹ�� A �����е�ÿһ�������з��飬���ҷ�����һ����Ҫ��������

ʾ��:
����: 
A = [9,1,2,3,9]
K = 3
���: 20
����: 
A �����ŷ�����[9], [1, 2, 3], [9]. �õ��ķ����� 9 + (1 + 2 + 3) / 3 + 9 = 20.
����Ҳ���԰� A �ֳ�[9, 1], [2], [3, 9].
�����ķ���õ��ķ���Ϊ 5 + 2 + 6 = 13, ���������ֵ.
˵��:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
�������?10^-6?�ڱ���Ϊ����ȷ�ġ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-sum-of-averages
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
