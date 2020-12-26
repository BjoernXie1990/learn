����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի���

���бߵĳ��ȶ���1����ı��Ϊ1~n��

�������1�ŵ㵽n�ŵ����̾��룬�����1�ŵ��޷��ߵ�n�ŵ㣬���-1��

�����ʽ
��һ�а�����������n��m��

������m�У�ÿ�а�����������a��b����ʾ����һ����a�ߵ�b�ĳ���Ϊ1�ıߡ�

�����ʽ
���һ����������ʾ1�ŵ㵽n�ŵ����̾��롣

���ݷ�Χ
1��n,m��105
����������
4 5
1 2
2 3
3 4
1 3
1 4
���������
1


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n,m;
bool vis[N];

void add(int u,int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int bfs() {
    queue<int> que;
    que.push(1);
    vis[1] = true;
    
    int res = 0;
    
    while(!que.empty()) {
        int size = que.size();
        res++;
        
        while(size --) {
            int f = que.front();
            que.pop();
            
            for(int i = h[f]; ~i; i = ne[i]) {
                int v = e[i];
                if(vis[v])
                    continue;
                    
                que.push(v);
                vis[v] = true;
                
                if(v == n) return res;
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i <= m; i ++) {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    
    cout << bfs() << endl;
    return 0;
}
