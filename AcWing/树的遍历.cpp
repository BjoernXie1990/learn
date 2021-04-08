#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 50, M = N * 2;
int mid[N],last[N];
int n;
int h[N],ne[M],e[M],id;

void add(int u,int v) {
    e[id] = v, ne[id] = h[u], h[u] = id ++;
}

int dfs(int lea,int ria,int leb,int rib) {
    if(lea > ria || leb > rib) {
        return -1;
    }
    
    int root = last[ria];
    int pos = leb;
    while(mid[pos] != root)
        pos ++;
        
    int leLen = pos - leb;
    int leId = dfs(lea, lea + leLen - 1, leb, pos - 1);
    int riId = dfs(lea + leLen, ria - 1, pos + 1, rib);
    
    add(root,riId);
    add(root,leId);
    
    return root;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> last[i];
    for(int i = 0; i < n; i++) 
        cin >> mid[i];
    
    memset(h, -1, sizeof h);
    int root = dfs(0, n - 1, 0, n - 1);
    
    queue<int> que;
    que.push(root);
    
    int cnt = 0;
    while(que.size()) {
        int size = que.size();
        while(size --) {
            int f = que.front();
            que.pop();
            cout << f << " ";
            
            for(int v = h[f]; v != -1; v = ne[v]) {
                if(e[v] != -1)
                    que.push(e[v]);
            }
        }

    }
    
    return 0;
}


һ��������������ÿ���ڵ��Ȩֵ������ͬ��

���ڸ������ĺ���������������������������Ĳ��������

�����ʽ
��һ�а������� N����ʾ�������Ľڵ�����

�ڶ��а��� N ����������ʾ�������ĺ��������

�����а��� N ����������ʾ�����������������

�����ʽ
���һ�� N ����������ʾ�������Ĳ��������

���ݷ�Χ
1��N��30
����������
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
���������
4 1 6 3 5 7 2
