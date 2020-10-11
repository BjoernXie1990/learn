class Solution {
public:
    int n,m;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n - 2; i++)
            for(int j = 0; j < m - 2; j++)
                ans += check(grid,i,j) == true ? 1 : 0;
        return ans;
    }

    bool check(vector<vector<int> >& grid,int x,int y) {
        static int vis[10];
        memset(vis,0x00,sizeof(vis));

        int num = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        if(num != grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y]) return false;

        // �У��У�����Ԫ���Ƿ�Ϊ 1-9
        for(int i = 0; i < 3; i++) {
            int r = 0, c = 0;
            for(int j = 0; j < 3; j++) {
                int idx = grid[x+i][y+j];
                if(idx > 9 || idx == 0 || vis[idx] == 1) return false;
                vis[idx] = 1;
                r += idx;

                // ��
                idx = grid[x+j][y+i];
                c += idx;
            }
            if(r != num || c != num) return false;
        }
        return true;
    }
};


3 x 3 �Ļ÷���һ������д� 1 �� 9 �Ĳ�ͬ���ֵ� 3 x 3 ��������ÿ�У�ÿ���Լ������Խ����ϵĸ���֮�Ͷ���ȡ�

����һ����������ɵ� grid�������ж��ٸ� 3 �� 3 �� ���÷��� �Ӿ��󣿣�ÿ���Ӿ����������ģ���

?

ʾ����

����: [[4,3,8,4],
      [9,5,1,9],
      [2,7,6,2]]
���: 1
����: 
������Ӿ�����һ�� 3 x 3 �Ļ÷���
438
951
276

����һ�����ǣ�
384
519
762

�ܵ���˵���ڱ�ʾ���������ľ�����ֻ��һ�� 3 x 3 �Ļ÷��Ӿ���
��ʾ:

1 <= grid.length?<= 10
1 <= grid[0].length?<= 10
0 <= grid[i][j] <= 15

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/magic-squares-in-grid
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
