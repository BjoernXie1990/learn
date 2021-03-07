const int N = 2 * 1e4 + 10, M = N * 4;
int h[N], ne[M], e[M], w[M],id;
int dist[N],st[N];

class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long LL;
    const int MOD = 1e9 + 7;
    vector<int> cnt;
    vector<bool> vis;
    
    void add(int u,int v,int t) {
        e[id] = v, w[id] = t, ne[id] = h[u], h[u] = id ++;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(h,-1,sizeof h);
        id = 0;
        cnt.resize(n + 1,-1);
        vis.resize(n + 1,false);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            add(u,v,t);
            add(v,u,t);
        }
        dijkstra(n);
        
//         for(int i = 1; i <= n; i++)
//             cout << dist[i] << " ";
//         cout << endl;
        
        return dfs(1,n) % MOD;
    }
    
int dijkstra(int n) {
    memset(dist, 0x3f, sizeof dist);
    memset(st,0x00,sizeof st);
    dist[n] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII> > pq;     // С����
    pq.push({0,n});
    
    while(!pq.empty()) {
        PII t = pq.top();
        pq.pop();
        
        int distance = t.first, ver = t.second;
        if(st[ver]) continue;  // �ų���ǰ�ڵ��Ѿ��ҵ����·�����
        st[ver] = true;
        
        for(int i = h[ver]; i != -1 ; i = ne[i]) {
            int v = e[i];
            if(dist[v] > distance + w[i]) {
                dist[v] = distance + w[i];
                pq.push({dist[v],v});
            }
        }
    }
    
    if(dist[1] == 0x3f3f3f3f) return -1;
    return dist[1];
}
    
    LL dfs(int u,int end) { 
        if(u == end) return 1;
        if(cnt[u] != -1) {
            return cnt[u];
        }
        
        vis[u] = true;
        
        LL res = 0;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i], t = w[i];
            //cout << dist[u] << " " << dist[v] << " " << u << " " << v <<endl;
            
            if(vis[v] || dist[u] <= dist[v]) continue;
            //if(v == end) cout << dist[u] << " " << dist[v] << " " << u << " " << v <<  " " << vis[v] << endl;
            res = (res + dfs(v,end)) % MOD;
        }
        
        vis[u] = false;
        cnt[u] = res;
        
        return cnt[u];
    }
    
    
};


����һ����Ȩ������ͨͼ������һ�������� n ����ʾͼ���� n ���ڵ㣬������ 1 �� n ���ڵ��ţ������һ������ edges ������ÿ�� edges[i] = [ui, vi, weighti] ��ʾ����һ��λ�ڽڵ� ui �� vi ֮��ıߣ������ߵ�Ȩ��Ϊ weighti ��

�ӽڵ� start �������ڵ� end ��·����һ������ [z0, z1, z2, ..., zk] �Ľڵ����У����� z0 = start ��zk = end �������з��� 0 <= i <= k-1 �Ľڵ� zi �� zi+1 ֮�����һ���ߡ�

·���ľ��붨��Ϊ����·�������бߵ�Ȩ���ܺ͡��� distanceToLastNode(x) ��ʾ�ڵ� n �� x ֮��·������̾��롣����·�� Ϊ���� distanceToLastNode(zi) > distanceToLastNode(zi+1) ��һ��·�������� 0 <= i <= k-1 ��

���شӽڵ� 1 �������ڵ� n �� ����·���� ���������ֿ��ܴܺ��뷵�ض� 109 + 7 ȡ�� �Ľ����

?

ʾ�� 1��


���룺n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
�����3
���ͣ�ÿ��Բ������ɫ�Ľڵ��ź���ɫ�� distanceToLastNode ֵ����������·���ֱ��ǣ�
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
ʾ�� 2��


���룺n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
�����1
���ͣ�ÿ��Բ������ɫ�Ľڵ��ź���ɫ�� distanceToLastNode ֵ��Ψһһ������·���ǣ�1 --> 3 --> 7 ��
?

��ʾ��

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
���������ڵ�֮���������һ����
���������ڵ�֮�����ٴ���һ��·��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-restricted-paths-from-first-to-last-node
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
