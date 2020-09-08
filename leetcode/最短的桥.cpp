�ڸ����Ķ�ά����������?A?�У������������������������������� 1 �γɵ�һ������顣��

���ڣ����ǿ��Խ�?0?��Ϊ?1����ʹ�������������������һ������

���ر��뷭ת��?0 ����С��Ŀ�������Ա�֤�������� 1����

?

ʾ�� 1��

���룺[[0,1],[1,0]]
�����1
ʾ�� 2��

���룺[[0,1,0],[0,0,0],[0,0,1]]
�����2
ʾ�� 3��

���룺[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
�����1
?

��ʾ��

1 <= A.length =?A[0].length <= 100
A[i][j] == 0 ��?A[i][j] == 1


class Solution {
public:
    int n,m;
    vector<vector<bool> > vis;
    using key = pair<int,int>;
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        m = A[0].size();
        vis = vector<vector<bool> > (n,vector<bool> (m,false));

        queue<key> que;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    dfs(que,A,i,j); //  dfs���һ������
                    return bfs(que,A);  //bfs���������
                }
            }
        }
        return -1;
    }

    void dfs(queue<key>& que,vector<vector<int> >& A,int x,int y) {
        que.push(make_pair(x,y));
        vis[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int tx = dir[i][0] + x;
            int ty = dir[i][1] + y;
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || A[tx][ty] == 0) continue;

            dfs(que,A,tx,ty);
        }
    }

    int bfs(queue<key>& que,vector<vector<int> >& A) {
        int ret = 0;
        while(que.empty() == false) {
            int size = que.size();

            while(size--) {
                auto f = que.front();
                que.pop();

                for(int i = 0; i < 4; i++) {
                    int tx = dir[i][0] + f.first;
                    int ty = dir[i][1] + f.second;
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) continue;

                    if(A[tx][ty] == 1) return ret;
                    vis[tx][ty] = true;
                    que.push(make_pair(tx,ty));
                }
            }
            ret++;
        }

        return ret;
    }
};
