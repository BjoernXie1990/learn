����һ��������������?A��������Ҫ�õ�ͨ�� A ���½�·������С�͡�

�½�·�����Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ�С�

?

ʾ����

���룺[[1,2,3],[4,5,6],[7,8,9]]
�����12
���ͣ�
���ܵ��½�·���У�
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
����С���½�·����?[1,4,7]�����Դ���?12��

?

��ʾ��

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        vector<vector<int> > dp = A;

        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int num = INT_MAX;
                for(int k = -1; k <= 1; k++)
                {
                    int y = k + j;
                    if(y < 0 || y >= m)  continue;

                    num = min(num,dp[i-1][y] + A[i][j]);
                }

                dp[i][j] = num;
            }
        
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(dp[n-1][j],ans);
        return ans;
    }
};
