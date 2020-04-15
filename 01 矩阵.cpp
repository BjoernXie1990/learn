//����һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ��롣

//��������Ԫ�ؼ�ľ���Ϊ 1 ��

//ʾ�� 1:
//����:

//0 0 0
//0 1 0
//0 0 0
//���:

//0 0 0
//0 1 0
//0 0 0
//ʾ�� 2:
//����:

//0 0 0
//0 1 0
//1 1 1
//���:

//0 0 0
//0 1 0
//1 2 1
//ע��:
//���������Ԫ�ظ��������� 10000��
//����������������һ��Ԫ���� 0��
//�����е�Ԫ��ֻ���ĸ�����������: �ϡ��¡����ҡ�


class Solution {
public:
    //BFS
    vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > ans(row, vector<int> (col,-1));
        int count = row * col;//δͳ�Ƶĸ�����

        queue<node> que;
        //�Ȱ����о���Ϊ0�ĸ������
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == 0)
                {
                    count--;
                    que.push(GetNode(i,j));
                    ans[i][j] = 0;
                }
                    
        int path = 1;
        while(count && !que.empty())
        {
            //�ҵ�ǰpath���ĸ���
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                node n = que.front();
                que.pop();

                static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
                for(int j = 0; j < 4; j++)
                {
                    int tx = n._row + dir[j][0];
                    int ty = n._col + dir[j][1];

                    //�ж��Ƿ�Խ��
                    if(tx < 0 || tx >= row || ty < 0 || ty >= col)
                        continue;
                    //�жϵ�ǰλ���Ƿ���ʹ�
                    if(ans[tx][ty] != -1)
                        continue;
                    ans[tx][ty] = path;
                    que.push(GetNode(tx,ty));
                    count--;
                }
            }
            path++;
        }
        return ans;

    }

    typedef struct node{
        int _row;
        int _col;
    }node;

    node GetNode(int row,int col)
    {
        node n;
        n._col = col;
        n._row = row;
        return n;
    }
    //��̬�滮
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col,0));

        //�ж�������������
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j])//�Ȱ�1����ʼ��Ϊ���ֵ
                    dp[i][j] = 0x0000ffff;
                //�ж�����
                if(dp[i][j])
                {
                    if(i > 0)
                        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);//��
                    if(j > 0)
                        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);//�Ϸ�
                }
            }
        
        //�ж��ң���
        for(int i = row - 1; i >= 0; i--)
            for(int j = col - 1; j >= 0; j--)
            {
                if(dp[i][j])
                {
                    if(i+1 < row)
                        dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if(j+1 < col)
                        dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                }
            }
        return dp;
    }
};
