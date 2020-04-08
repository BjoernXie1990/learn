//������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
//һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
//Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
//�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

//?

//ʾ�� 1��

//���룺m = 2, n = 3, k = 1
//�����3
//ʾ�� 1��

//���룺m = 3, n = 1, k = 0
//�����1



class Solution {
public:
    typedef struct node
    {
        int row;
        int col;
    };

    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<int> > visit(m,vector<int> (n,0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(GetNum(i,j) > k)
                    visit[i][j] = 1;//��ʾ������Ӳ������ߵ�
            }
        
        ans = bfs(visit,0,0,m,n);
        return ans;
    }

    int bfs(vector<vector<int> >& visit,int x,int y,int m,int n)
    {
        int dir[4][2] = {1,0,-1,0,0,1,0,-1};//�ĸ�����

        queue<node> que;
        que.push(GetNode(x,y));//ͷ������
        visit[x][y] = 1;
        int ans = 1; //��ʼλ��һ�����Ե���

        while(!que.empty())
        {
            int size = que.size();//��ȡ������Ԫ�ظ���
            for(int i = 0; i < size; i++)
            {
                node point = que.front();//��ȡ��ͷԪ��
                que.pop();//��ͷԪ�س�ջ
                int row = point.row;
                int col = point.col;

                //��ȡ�ýڵ���һ�����Ե����λ��
                for(int j = 0; j < 4; j++)
                {
                    int tx = dir[j][0] + row;
                    int ty = dir[j][1] + col;

                    //�ж�Խ��
                    if(tx < 0 || tx >= m || ty < 0 || ty >= n)
                        continue;
                    
                    //�Ƿ���Ե���
                    if(visit[tx][ty])
                        continue;
                    
                    //��ʱ������ӿ��Դﵽ
                    que.push(GetNode(tx,ty));//���
                    ans++;
                    visit[tx][ty] = 1;
                }
            }
        }

        return ans;
    }

    //����������Ϊ�ṹ��
    node GetNode(int row,int col)
    {
        node point;
        point.row = row;
        point.col = col;
        return point;
    }

    //��ȡ��λ�������λ����
    int GetNum(int row,int col)
    {
        int num = 0;
        while(row || col)
        {
            num += row % 10 + col % 10;
            row /= 10;
            col /= 10;
        }

        return num;
    }
};
