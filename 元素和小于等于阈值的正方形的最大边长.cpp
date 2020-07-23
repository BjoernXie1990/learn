����һ����СΪ?m x n?�ľ���?mat?��һ��������ֵ?threshold��

���㷵��Ԫ���ܺ�С�ڻ������ֵ����������������߳������û�������������������򷵻� 0?��
?

ʾ�� 1��



���룺mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
�����2
���ͣ��ܺ�С�� 4 �������ε����߳�Ϊ 2����ͼ��ʾ��
ʾ�� 2��

���룺mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
�����0
ʾ�� 3��

���룺mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
�����3
ʾ�� 4��

���룺mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
�����2
?

��ʾ��

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold?<= 10^5



class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int> > dp(n+1,vector<int> (m+1,0));

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
        
        int ans = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= i && k <= j; k++)
                {
                    int tmp = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
                    if(tmp > threshold) break;

                    ans = max(ans,k);
                }

        return ans;
    }
};
