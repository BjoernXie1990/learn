����һ����ά�ַ���������?grid?����СΪ?m x n?������Ҫ���?grid?���Ƿ���� ��ֵͬ �γɵĻ���

һ������һ����ʼ�ͽ�����ͬһ�����ӵĳ��� ���ڵ��� 4?��·��������һ�������ĸ��ӣ�������ƶ������ϡ��¡������ĸ��������ڵĸ���֮һ�������ƶ���ǰ���������������� ��ͬ��ֵ?��

ͬʱ����Ҳ���ܻص���һ���ƶ�ʱ���ڵĸ��ӡ��ȷ�˵����??(1, 1) -> (1, 2) -> (1, 1)?�ǲ��Ϸ��ģ���Ϊ�� (1, 2)?�ƶ��� (1, 1) �ص�����һ���ƶ�ʱ�ĸ��ӡ�

��� grid?������ֵͬ�γɵĻ������㷵�� true?�����򷵻� false?��

?

ʾ�� 1��



���룺grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
�����true
���ͣ�����ͼ��ʾ���� 2 ���ò�ͬ��ɫ������Ļ���

ʾ�� 2��



���룺grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
�����true
���ͣ�����ͼ��ʾ��ֻ�и�����ʾ��һ���Ϸ�����

ʾ�� 3��



���룺grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
�����false
?

��ʾ��

m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid?ֻ����СдӢ����ĸ��



class Solution {
public:
    using key = pair<int,int>;
    struct node{
        int _x;
        int _y;
        key _pre;
        node(int x,int y,int px,int py)
            :_x(x),_y(y)
        {
            _pre = make_pair(px,py);
        }
    };
    int n,m;
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool> > vis(n,vector<bool> (m,false));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(vis[i][j] == true)   continue;

                int ret = BFS(grid,vis,i,j);
                
                if(ret == true) return true;
            }
        return false;
    }

    bool BFS(vector<vector<char>>& grid,vector<vector<bool> >& vis,int x,int y){
        static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
        queue<node> que;
        que.push(node(x,y,-1,-1));
        char ch = grid[x][y];

        while(!que.empty()){
            auto f = que.front();
            que.pop();

            for(int i = 0; i < 4; i++){
                int tx = f._x + dir[i][0];
                int ty = f._y + dir[i][1];

                if(tx < 0 || tx >= n || ty < 0 || ty >= m || 
                        (tx == f._pre.first && ty == f._pre.second) || grid[tx][ty] != ch)
                        continue;
                
                if(vis[tx][ty] == true) return true;

                vis[tx][ty] = true;
                que.push(node(tx,ty,f._x,f._y));
            }
        }
        //û�гɻ�
        return false;
    } 
};
