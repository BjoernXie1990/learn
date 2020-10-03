class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int sum[r+1][c+1];
        memset(sum,0x00,sizeof(sum));

        vector<int> ans(4,0);
        int cnt = INT_MIN;

        // ������ʱ O(n^2 * m^2)
        // for(int i = 0; i < r; i++) 
        //     for(int j = 0; j < c; j++) sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];
        // for(int i = 0; i < r; i++)
        //     for(int j = i; j < r; j++)
        //         for(int n = 0; n < c; n++)
        //             for(int m = n; m < c; m++) {
        //                 int num = sum[j+1][m+1] - sum[j+1][n] - sum[i][m+1] + sum[i][n];
        //                 if(num > cnt) {
        //                     cnt = num;
        //                     ans[0] = i;
        //                     ans[1] = n;
        //                     ans[2] = j;
        //                     ans[3] = m;
        //                 }
        //             }

        // ac
        int dp[c];
        for(int i = 0; i < r; i++){
            memset(dp,0x00,sizeof(dp));

            for(int j = i; j < r; j++) {
                int cur = 0;
                int lefedown = i;
                for(int k = 0; k < c; k++) {
                    dp[k] += matrix[j][k];
                    if(cur > 0) cur += dp[k];
                    else {
                        cur = dp[k];
                        lefedown = k;
                    }

                    if(cur > cnt) {
                        cnt = cur;
                        ans[0] = i;
                        ans[1] = lefedown;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        
        return ans;
                        
    }
};

����һ������������������ 0 ��ɵ� N �� M?���󣬱�д�����ҳ�Ԫ���ܺ������Ӿ���

����һ������ [r1, c1, r2, c2]������ r1, c1 �ֱ�����Ӿ������Ͻǵ��кź��кţ�r2, c2 �ֱ�������½ǵ��кź��кš����ж�������������Ӿ��󣬷�������һ�����ɡ�

ע�⣺�����������ԭ�������Ķ�

ʾ����

���룺
[
?  [-1,0],
?  [0,-1]
]
�����[0,1,0,1]
���ͣ������б�ֵ�Ԫ�ؼ�Ϊ�������ʾ�ľ���
?

˵����

1 <= matrix.length, matrix[0].length <= 200

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-submatrix-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
