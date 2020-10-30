class Solution {
public:
    const int mod = 1e9 + 7;
    
    int findPaths(int m, int n, int N, int ii, int jj) {
        static int dir[4][2] = {1,0,-1,0,0,1,0,-1};

        int dp[m][n][2];
        memset(dp,0x00,sizeof dp);
        for(int k = 0; k < N; k++)
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++) {
                    dp[i][j][k % 2] = 0;    // ���֮ǰ��״̬
                    for(int d = 0; d < 4; d++) {
                        int x = i + dir[d][0];
                        int y = j + dir[d][1];
                        if(x < 0 || y < 0 || y >= n || x >= m) {
                            dp[i][j][k % 2] = (dp[i][j][k % 2] + 1) % mod;
                        } else {
                            dp[i][j][k % 2] = (dp[x][y][(k + 1) % 2] + dp[i][j][k % 2]) % mod; 
                        }
                    }  
                }
        return dp[ii][jj][(N + 1) % 2];

        // bfs
        // using key = pair<int,int>;
        // queue<key> que;
        // que.push(make_pair(i,j));

        // int ans = 0;
        // while(!que.empty() && N--) {
        //     int size = que.size();
        //     while(size --) {
        //         auto f = que.front();
        //         que.pop();

        //         for(int i = 0; i < 4; i++) {
        //             int x = f.first + dir[i][0];
        //             int y = f.second + dir[i][1];

        //             if(x < 0 || x >= m || y < 0 || y >= n) {
        //                 ans = (ans + 1) % mod;
        //                 continue;
        //             }
        //             que.push(make_pair(x,y));
        //         }
        //     }
        // }

        // return ans;
    }
};

����һ�� m �� n �������һ���������ʼ����Ϊ?(i,j)?������Խ����Ƶ����ڵĵ�Ԫ���ڣ��������ϡ��¡������ĸ��������ƶ�ʹ�򴩹�����߽硣���ǣ����������ƶ�?N?�Ρ��ҳ����Խ����Ƴ��߽��·���������𰸿��ܷǳ��󣬷��� ��� mod 109?+ 7 ��ֵ��

?

ʾ�� 1��

����: m = 2, n = 2, N = 2, i = 0, j = 0
���: 6
����:

ʾ�� 2��

����: m = 1, n = 3, N = 3, i = 0, j = 1
���: 12
����:

?

˵��:

��һ�����磬�Ͳ����ٱ��ƶ��������ڡ�
����ĳ��Ⱥ͸߶��� [1,50] �ķ�Χ�ڡ�
N �� [0,50] �ķ�Χ�ڡ�
ͨ������5,749�ύ����15,332

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/out-of-boundary-paths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
