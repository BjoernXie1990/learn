#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 210;
char f[N][N];
int dist[N][N];
int n,m;

int BFS(PII start) {
    memset(dist,0x00,sizeof dist);
    queue<PII> que;
    que.push(start);
    dist[start.first][start.second] = 1;
    
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    while(que.size()) {
        int cnt = que.size();
        while(cnt --) {
            auto fr = que.front();
            que.pop();
            
            for(int i = 0; i < 4; i++) {
                int x = fr.first + dir[i][0], y = fr.second + dir[i][1];
                if(x < 0 || y < 0 || x >= n || y >= m || f[fr.first][fr.second] == '#' || dist[x][y]) continue;
                dist[x][y] = dist[fr.first][fr.second] + 1;
                if(f[x][y] == 'E') {
                    return dist[x][y] - 1;
                }
                
                que.push({x,y});
            }
        }
    }
    
    return -1;
}

int main() {
    int T;
    cin >> T;
    while(T --) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> f[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(f[i][j] == 'S') {
                    int res = BFS({i,j});
                    
                    if(res == -1) puts("oop!");
                    else cout << res << endl;
                }
            }
    }
    
    return 0;
} 


������ٯ��һֻ�����������С���������ó��ľ����߸��ָ������Թ���

������Ҫ��սһ���ǳ�����Թ����о�Ա��Ϊ�˹���������ٯ���쵽���յ㣬�����յ����һ�鰢����ٯ��ϲ�������ҡ�

�����о�Ա����֪�������������ٯ�㹻��������������Ҫ����ʱ����ܳԵ����ҡ�

�Թ���һ�� R��C ���ַ���������ʾ��

�ַ� S ��ʾ������ٯ���ڵ�λ�ã��ַ� E ��ʾ�������ڵ�λ�ã��ַ� # ��ʾǽ�ڣ��ַ� . ��ʾ����ͨ�С�

������ٯ�� 1 ����λʱ���ڿ��Դӵ�ǰ��λ���ߵ������������ĸ������ϵ�����һ��λ�ã��������߳���ͼ�߽硣

�����ʽ
��һ����һ�������� T����ʾһ���� T �����ݡ�

ÿһ�����ݵĵ�һ�а����������ÿո�ֿ��������� R �� C����ʾ��ͼ��һ�� R��C �ľ���

�������� R �������˵�ͼ�ľ������ݣ�ÿһ�а����� C ���ַ����ַ���������Ŀ��������������֤���ҽ���һ�� S �� E��

�����ʽ
����ÿһ�����ݣ����������ٯ�Ե����ҵ����ٵ�λʱ�䡣

��������ٯ�޷��Ե����ң��������oop!����ֻ���������������ݣ���������ţ���

ÿ�����ݵ�������ռһ�С�

���ݷ�Χ
1<T��10,
2��R,C��200
����������
3
3 4
.S..
###.
..E.
3 4
.S..
.E..
....
3 4
.S..
####
..E.
���������
5
1
oop!
