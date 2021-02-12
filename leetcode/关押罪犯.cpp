#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
int h[N],e[M],ne[M],w[M],idx;
int color[N];
int n,m;

void add(int u,int v,int k) {
    e[idx] = v,w[idx] = k, ne[idx] = h[u],h[u] = idx++;
}

bool dfs(int id,int c,int k) {
    color[id] = c;
    for(int i = h[id]; ~i; i = ne[i]) {
        if(w[i] <= k) continue;
        int v = e[i];
        if(color[v]) {
            if(color[v] == color[id]) return false;
        } else if(!dfs(v,3-c,k)) return false;
    }
    return true;
}

bool check(int k) {
    memset(color,0x00,sizeof color);
    for(int i = 1; i <= n; i++)
        if(!color[i]) if(!dfs(i,1,k)) return false;
    return true;
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    int le = 0, ri = 1e9;
    while(le < ri) {
        int mid = le + ri >> 1;
        if(check(mid)) ri = mid;
        else le = mid + 1;
    }
    
    cout << le << endl;
    return 0;
}



S ����������������һ����Ѻ�� N ���ﷸ����ŷֱ�Ϊ1~N��

����֮��Ĺ�ϵ��ȻҲ������г��

�ܶ��ﷸ֮��������Թ�Ѿã�����͹������߱�����ʱ���ܱ�����ͻ��

�����á�Թ��ֵ����һ��������ֵ������ʾĳ�����ﷸ֮��ĳ�޳̶ȣ�Թ��ֵԽ�����������ﷸ֮��Ļ�ԹԽ�ࡣ

�������Թ��ֵΪ c ���ﷸ����Ѻ��ͬһ������������֮��ᷢ��Ħ���������Ӱ����Ϊ c �ĳ�ͻ�¼���

ÿ����ĩ������ֻὫ�����ڼ����е����г�ͻ�¼���Ӱ�����Ӵ�С�ų�һ���б�Ȼ���ϱ��� S �� Z �г����

����æ�� Z �г�ֻ��ȥ���б��еĵ�һ���¼���Ӱ���������Ӱ��ܻ������ͻῼ�ǳ�������ֳ���

����ϸ������ N ���ﷸ���ì�ܹ�ϵ�󣬾���ֳ�����ѹ���޴�

��׼�����ﷸ�����������������·��䣬��������ĳ�ͻ�¼�Ӱ��������С���Ӷ���ס�Լ�����ɴñ��

����ֻҪ����ͬһ�����ڵ�ĳ�����ﷸ���г�ޣ���ô����һ������ÿ���ĳ��ʱ����Ħ������ô��Ӧ��η����ﷸ������ʹ Z �г��������Ǹ���ͻ�¼���Ӱ������С�������Сֵ�Ƕ��٣�

�����ʽ
��һ��Ϊ���������� N �� M���ֱ��ʾ�ﷸ����Ŀ�Լ����ڳ�޵��ﷸ������

�������� M ��ÿ��Ϊ����������aj��bj��cj����ʾaj�ź�bj���ﷸ֮����ڳ�ޣ���Թ��ֵΪcj��

���ݱ�֤1��aj<bj<N,0<cj��109 ��ÿ���ﷸ���ֻ����һ�Ρ�

�����ʽ
�����1�У�Ϊ Z �г��������Ǹ���ͻ�¼���Ӱ������

��������ڼ�����δ�����κγ�ͻ�¼��������0��

���ݷ�Χ
N��20000,M��100000
����������
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
���������
3512
�Ѷȣ��е�
ʱ/�����ƣ�1s / 64MB
��ͨ������1331
�ܳ�������2341
��Դ�����㷨��������ָ�ϡ�, NOIP2010�����
�㷨��ǩ



#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010, M = 1e5 + 10;
int n,m;
int f[M];
struct node{
    int u,v,w;
    bool operator<(const node& t) const {
        return w > t.w;
    }
}e[M];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

bool merge(int x,int y) {
    int tx = find(x), ty = find(y);
    if(tx == ty) return false;
    f[tx] = find(y + n);
    f[ty] = find(x + n);
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e,e+m);
    for(long long i = 0; i <= (n << 1); i++) f[i] = i;
    
    int res = 0;
    for(int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(!merge(u,v)) {
            res = w;
            break;
        }
    }
    cout << res << endl;
    return 0;
}

