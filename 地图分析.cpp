//������������һ�ݴ�СΪ?N x N �ġ���ͼ��������?grid��
//�����ÿ�������򡻣���Ԫ�񣩶���?0?��?1?��Ǻ��ˡ�����?0?������1?����½�أ�
//��֪������½��������Զ�ĺ�������������һ�����뷵�ظú����������������½������ľ��롣

//��������˵�ľ����ǡ������پ��롻��?Manhattan Distance����(x0, y0) ��?(x1, y1)?
//����������֮��ľ�����?|x0 - x1| + |y0 - y1|?��

//������ǵĵ�ͼ��ֻ��½�ػ��ߺ����뷵��?-1��

//?

//ʾ�� 1��



//���룺[[1,0,1],[0,0,0],[1,0,1]]
//�����2
//���ͣ� 
//�������� (1, 1) ������½������֮��ľ��붼�ﵽ���������Ϊ 2��
//ʾ�� 2��



//���룺[[1,0,0],[0,0,0],[0,0,0]]
//�����4
//���ͣ� 
//�������� (2, 2) ������½������֮��ľ��붼�ﵽ���������Ϊ 4��
//?

//��ʾ��

//1 <= grid.length == grid[0].length?<= 100
//grid[i][j]?����?0?����?1



typedef struct node
{
    int x;//������
    int y;//������
    int path;//����õ���Զ��½�ؾ���
}node;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};//���������ĸ�����
        queue<node> q;//����½�ص�λ��
        int row = grid.size();
        int col = grid[0].size();

        //���α�������������½��λ��
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(grid[i][j])//�����½�أ��ͼ���ṹ���У�Ȼ�����
                    q.push(CreatNode(i,j,0));
        int maxPath = -1;

        while(!q.empty())
        {
            node head = q.front();//ȡ������ͷԪ��
            int x = head.x;
            int y = head.y;
            int path = head.path;
            q.pop();

            for(int i = 0; i < 4; i++)//�����ĸ�����
            {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                int tpath = path + 1;

                //�ж��Ƿ�Խ�磬�����Ƿ���½��
                if(tx < 0 || tx >= row || ty < 0 || ty >= col || grid[tx][ty])
                    continue;
                grid[tx][ty] = 1;//��ǰ�����Ƴ�½��
                q.push(CreatNode(tx,ty,tpath));//½�����
                //�����Ƿ�����Զ�ľ���
                if(maxPath < tpath)
                    maxPath = tpath;
            }
        }
        return maxPath;
    }

    //����λ�ýṹ��
    node CreatNode(int x,int y,int path)
    {
        node pos;
        pos.x = x;
        pos.y = y;
        pos.path = path;
        return pos;
    }
};
