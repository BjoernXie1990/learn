class Solution {
public:
    const int mod = 1e9 + 7;
    using ll = long long;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        long long dp[n][m][2];
        memset(dp,0x00,sizeof(dp));
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        
        for(int i = 1; i < m; i++)  {
                dp[0][i][0] = grid[0][i] * dp[0][i-1][0];
                dp[0][i][1] = grid[0][i] * dp[0][i-1][1];
        }
        
        for(int i = 1; i < n; i++) {
            dp[i][0][0] = grid[i][0] * dp[i-1][0][0];
            dp[i][0][1] = grid[i][0] * dp[i-1][0][1];
        }
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                long long up1 = dp[i-1][j][0] * grid[i][j];
                long long up2 = dp[i-1][j][1] * grid[i][j];
                
                long long left1 = dp[i][j-1][0] * grid[i][j];
                long long left2 = dp[i][j-1][1] * grid[i][j];
                dp[i][j][0] = Min(up1,up2,left1,left2);
                dp[i][j][1] = Max(up1,up2,left1,left2);
            }
        
        return dp[n-1][m-1][1] >= 0 ? dp[n-1][m-1][1] % mod : -1;
    }
    
    long long Min(ll a,ll b,ll c,ll d) {
        return min(min(a,b),min(c,d));
    }
    long long Max(ll a,ll b,ll c,ll d) {
        return max(max(a,b),max(c,d));
    }
};

����һ����СΪ rows x cols �ľ��� grid ���������λ�����Ͻ� (0, 0) ��ÿһ����������ھ����� ���� �� ���� �ƶ���

�ڴ����Ͻ� (0, 0) ��ʼ�����½� (rows - 1, cols - 1) ����������·���У��ҳ����� ���Ǹ��� ��·����·���Ļ�����·�����ʵĵ�Ԫ�������������ĳ˻���

���� ���Ǹ��� �� 109?+ 7 ȡ�� �Ľ�����������Ϊ�������򷵻� -1 ��

ע�⣬ȡ�����ڵõ�����֮��ִ�еġ�

?

ʾ�� 1��

���룺grid = [[-1,-2,-3],
?            [-2,-3,-3],
?            [-3,-3,-2]]
�����-1
���ͣ��� (0, 0) �� (2, 2) ��·�����޷��õ��Ǹ��������Է��� -1
ʾ�� 2��

���룺grid = [[1,-2,1],
?            [1,-2,1],
?            [3,-4,1]]
�����8
���ͣ����Ǹ�����Ӧ��·���Ѿ��ô����� (1 * 1 * -2 * -4 * 1 = 8)
ʾ�� 3��

���룺grid = [[1, 3],
?            [0,-4]]
�����0
���ͣ����Ǹ�����Ӧ��·���Ѿ��ô����� (1 * 0 * -4 = 0)
ʾ�� 4��

���룺grid = [[ 1, 4,4,0],
?            [-2, 0,0,1],
?            [ 1,-1,1,1]]
�����2
���ͣ����Ǹ�����Ӧ��·���Ѿ��ô����� (1 * -2 * 1 * -1 * 1 * 1 = 2)
?

��ʾ��

1 <= rows, cols <= 15
-4 <= grid[i][j] <= 4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-non-negative-product-in-a-matrix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
