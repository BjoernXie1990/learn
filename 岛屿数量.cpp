//����һ����?'1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������

//�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�

//���⣬����Լ��������������߾���ˮ��Χ��

//ʾ�� 1:

//����:
//11110
//11010
//11000
//00000
//���:?1
//ʾ��?2:

//����:
//11000
//11000
//00100
//00011
//���: 3
//����: ÿ������ֻ����ˮƽ��/����ֱ���������ڵ�½�����Ӷ��ɡ�


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        vector<vector<int> > visit(row, vector<int> (col,0));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '0' || visit[i][j])
                    continue;

                visit[i][j] = 1;
                dfs(grid,visit,row,col,i,j);
                ans++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visit, int row, int col,int r, int c)
    {
        static int dir[8][2] = {1,0,0,1,-1,0,0,-1};

        for(int i = 0; i < 4; i++)
        {
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if(x < 0 || x >= row || y < 0 || y >= col)
                continue;
            if(grid[x][y] == '0' ||  visit[x][y])
                continue;
            visit[x][y] = 1;
            dfs(grid,visit,row,col,x,y);
        }
    }
};
