#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6010;
int happy[N];
int h[N],e[N],ne[N],id;
int f[N][2];
bool is_father[N];
int n;

void add(int u,int v) {
    e[id] = v, ne[id] = h[u], h[u] = id++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v);
        
        f[u][0] += max(f[v][0],f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> happy[i];
    
    memset(h,-1,sizeof h);
    
    for(int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        add(b,a);
        is_father[a] = true;
    }
    
    int root = 1;
    while(is_father[root]) root++;
    
    dfs(root);
    
    cout << max(f[root][0],f[root][1]) << endl;
    return 0;
}


Ural��ѧ��N��ְԱ�����Ϊ1~N��

���ǵĹ�ϵ����һ����У��Ϊ�����������ڵ�����ӽڵ��ֱ����˾��

ÿ��ְԱ��һ������ָ���������� Hi ���������� 1��i��N��

����Ҫ�ٿ�һ����������ᣬ������û��ְԱԸ���ֱ����˾һ��λᡣ

���������������ǰ���£����췽ϣ������һ����ְԱ�λᣬʹ�����вλ�ְԱ�Ŀ���ָ���ܺ������������ֵ��

�����ʽ
��һ��һ������N��

������N�У��� i �б�ʾ i ��ְԱ�Ŀ���ָ��Hi��

������N-1�У�ÿ������һ������L, K,��ʾK��L��ֱ����˾��

�����ʽ
������Ŀ���ָ����

���ݷ�Χ
1��N��6000,
?128��Hi��127
����������
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
���������
5
