����һ��ĳ���� N��N ���ص���Ƭ����.����ʾ���󡢡�#����ʾ½�أ�������ʾ��

.......
.##....
.##....
....##.
..####.
...###.
.......
���С��������ҡ��ĸ�����������һ���һƬ½�����һ�����죬������ͼ���� 2 �����졣

����ȫ���ů�����˺�����������ѧ��Ԥ��δ����ʮ�꣬�����Եһ�����صķ�Χ�ᱻ��ˮ��û��

������˵���һ��½�������뺣������(���������ĸ������������к���)�����ͻᱻ��û��

������ͼ�еĺ���δ�������������ӣ�

.......
.......
.......
.......
....#..
.......
.......
������㣺���տ�ѧ�ҵ�Ԥ�⣬��Ƭ���ж��ٵ���ᱻ��ȫ��û��

�����ʽ
��һ�а���һ������N��

���� N �� N �У�����һ�����ַ���#���͡�.�����ɵ� N��N �ַ����󣬴���һ�ź�����Ƭ����#����ʾ½�أ���.����ʾ����

��Ƭ��֤�� 1 �С��� 1 �С��� N �С��� N �е����ض��Ǻ���

�����ʽ
һ��������ʾ�𰸡�

���ݷ�Χ
1��N��1000
��������1��
7
.......
.##....
.##....
....##.
..####.
...###.
.......
�������1��
1
��������2��
9
.........
.##.##...
.#####...
.##.##...
.........
.##.#....
.#.###...
.#..#....
.........
�������2��
1


#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int x,y;
    node(int a,int b) {
        x = a;
        y = b;
    }
};

const int N = 1010;
char f[N][N];
int vis[N][N];
int n = 0;
int dir[4][2] = {-1,0,1,0,0,1,0,-1};

bool BFS(int x,int y) {
    //cout << x <<" " << y <<" "<< f[x][y] << endl;
    queue<node> que;
    que.push(node(x,y));
    vis[x][y] = 1;
    
    bool ret = false;
    
    while(!que.empty()) {
        node qf = que.front();
        que.pop();
        
        int cnt = 0;        // ��Χ�м���½��
        for(int i = 0; i < 4; i++) {
            int tx = qf.x + dir[i][0];
            int ty = qf.y + dir[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= n || f[tx][ty] == '.') 
                continue;       // ����
            // ½��
            cnt ++;
            if(vis[tx][ty] == 1) continue;
            que.push(node(tx,ty));
            vis[tx][ty] = 1;
        }
        // cout << cnt << " ";
        if(cnt == 4) ret = true;        // ������½�ز�����û
    }
    
    return ret;
}

int main() {
    cin >> n;
    memset(f,0x00,sizeof f);
    getchar();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) scanf("%c",&f[i][j]);
        getchar();
    }
    
    memset(vis,0x00,sizeof vis);
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(f[i][j] == '.' || vis[i][j] == 1) continue;
            
            if(!BFS(i,j)) ans++;
        }
    
    cout << ans;
    return 0;
}
