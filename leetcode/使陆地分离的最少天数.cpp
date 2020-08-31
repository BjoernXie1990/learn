����һ�������� 0 �� 1 ��ɵĶ�ά���� grid ������ 0 ��ʾˮ���� 1 ��ʾ½�ء�������ˮƽ�������ֱ���������ڵ� 1 ��½�أ������γɡ�

��� ǡ��ֻ��һ������ ������Ϊ½���� ��ͨ�� ������½�ؾ��� ����� ��

һ���ڣ����Խ��κε���½�ص�Ԫ��1������Ϊˮ��Ԫ��0����

����ʹ½�ط��������������

?

ʾ�� 1��



���룺grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
�����2
���ͣ�������Ҫ 2 ����ܵõ������½�ء�
��½�� grid[1][1] �� grid[0][2] ����Ϊˮ���õ���������ĵ��졣
ʾ�� 2��

���룺grid = [[1,1]]
�����2
���ͣ���������ж���ˮ��Ҳ��Ϊ�Ƿ���� ([[1,1]] -> [[0,0]])��0 ���졣
ʾ�� 3��

���룺grid = [[1,0,1,0]]
�����0
ʾ�� 4��

���룺grid = [[1,1,0,1,1],
?            [1,1,1,1,1],
?            [1,1,0,1,1],
?            [1,1,0,1,1]]
�����1
ʾ�� 5��

���룺grid = [[1,1,0,1,1],
?            [1,1,1,1,1],
?            [1,1,0,1,1],
?            [1,1,1,1,1]]
�����2
?

��ʾ��

1 <= grid.length, grid[i].length <= 30
grid[i][j] Ϊ 0 �� 1

class Solution {
public:
    int n,m;
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if(check(grid)) return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) continue;

                grid[i][j] = 0;
                if(check(grid)) return 1;
                grid[i][j] = 1;
            }
        }

        return 2;
    }

    bool check(vector<vector<int> >& grid){
        int count = 0;
        vector<vector<bool> > vis(n,vector<bool> (m,false));
        queue<pair<int,int> > que;
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) continue;
                count++;
                x = i;
                y = j;
            }
        }
        if(count == 0)  return true;

        que.push(make_pair(x,y));
        vis[x][y] = true;
        count--;
        while(que.empty() == false){
            auto f = que.front();
            que.pop();

            static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
            for(int i = 0; i < 4; i++){
                int tx = f.first + dir[i][0];
                int ty = f.second + dir[i][1];

                if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] == true || grid[tx][ty] == 0){
                    continue;
                }

                count--;
                vis[tx][ty] = true;
                que.push(make_pair(tx,ty));
            }
        }

        
        return count != 0;
    }
};
