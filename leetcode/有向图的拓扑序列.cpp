����һ��n����m���ߵ�����ͼ����ı����1��n��ͼ�п��ܴ����رߺ��Ի���

���������һ��������ͼ���������У�����������в����ڣ������-1��

��һ����ͼ�����е㹹�ɵ�����A���㣺����ͼ�е�ÿ����(x, y)��x��A�ж�������y֮ǰ�����A�Ǹ�ͼ��һ���������С�

�����ʽ
��һ�а�����������n��m

������m�У�ÿ�а�����������x��y����ʾ����һ���ӵ�x����y�������(x, y)��

�����ʽ
��һ�У���������������У����������һ���Ϸ����������м��ɡ�

�������-1��

���ݷ�Χ
1��n,m��105
����������
3 3
1 2
2 3
1 3
���������
1 2 3

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n,m;
int f[N];
int qq[N],hh,tt;

void add(int u,int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void bfs() {
    for(int i = 1; i <= n; i++) {
        if(f[i] == 0) {
            qq[tt++] = i;
        }
    }
    
    while(hh < tt) {
        int size = tt - hh;

        while(size --) {
            int t = qq[hh++];
            
            for(int i = h[t]; ~i; i = ne[i]) {
                int v = e[i];
                f[v]--;
                if(f[v] == 0) qq[tt++] = v;
            }
        }
    }
    
     // ��
    if(tt != n) {
        cout << "-1" << endl;
        return ;
    }
    
    for(int i = 0; i < n; i++)
        cout << qq[i] << " ";
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        add(a,b);
        f[b]++;
    }
    
    bfs();
    return 0;
}
