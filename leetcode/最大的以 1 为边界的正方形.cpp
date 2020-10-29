class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dp[n+1][m+1][2]; // dp[i][j][0] ��ʾ i,j ������������1��������dp[i][j][1] ���ʾ���������1������
        memset(dp,0x00,sizeof dp);

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == 0) continue;

                dp[i][j][0] = dp[i][j-1][0] + 1;    // �����ж���������1
                dp[i][j][1] = dp[i-1][j][1] + 1;    // �����ж���������1
                int len = min(dp[i][j][1],dp[i][j][0]);     // ��С�߳�

                for(int k = len; k > 0; k--) {
                    if(dp[i][j-k+1][1] < k || dp[i-k+1][j][0] < k) continue;
                    ans = max(ans,k * k);
                }
            }
        
        return ans;
    }
};

����һ�������� 0 �� 1 ��ɵĶ�ά����?grid�������ҳ��߽�ȫ���� 1 ��ɵ���� ������ �����񣬲����ظ��������е�Ԫ����������������ڣ��򷵻� 0��

?

ʾ�� 1��

���룺grid = [[1,1,1],[1,0,1],[1,1,1]]
�����9
ʾ�� 2��

���룺grid = [[1,1,0,0]]
�����1
?

��ʾ��

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] Ϊ?0?��?1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-1-bordered-square
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
