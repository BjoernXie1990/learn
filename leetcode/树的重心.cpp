#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool vis[N];
int n,a,b;
int ans = N;

void add(int from,int to) {
    e[idx] = to, ne[idx] = h[from], h[from] = idx, idx++;
}

int dfs(int u) {
    vis[u] = true;
    
    int res = 0, sum = 1;   // res �����ͨ��ͼ�Ľڵ�����sum ��ǰ��(��Ϊu)�нڵ������
    for(int i = h[u]; i != -1 ; i = ne[i]) {
        int v = e[i];
        if(vis[v])
            continue;
        
        int s = dfs(v);
        res = max(res,s);
        sum += s;
    }
    
    res = max(res, n - sum);
    ans = min(ans,res);
    
    return sum;
}

int main() {
    cin >> n;
    memset(h,-1,sizeof h);
    
    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    
    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}


����һ���������а���n����㣨���1~n����n-1������ߡ�

�����ҵ��������ģ������������ɾ����ʣ�������ͨ���е��������ֵ��

���Ķ��壺������ָ���е�һ����㣬����������ɾ����ʣ�������ͨ���е��������ֵ��С����ô����ڵ㱻��Ϊ�������ġ�

�����ʽ
��һ�а�������n����ʾ���Ľ������

������n-1�У�ÿ�а�����������a��b����ʾ��a�͵�b֮�����һ���ߡ�

�����ʽ
���һ������m����ʾ������ɾ����ʣ�������ͨ���е��������ֵ��

���ݷ�Χ
1��n��105
��������
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
���������
4
