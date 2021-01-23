class UnionFind {
    public:
        UnionFind(int n) :f(n){
            cnt = n;
            for(int i = 0; i < n; i++)  f[i] = i;
        }

        int find(int x) {
            if(x != f[x]) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x);
            y = find(y);
            if(x == y) return false;
            f[x] = y;
            cnt--;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

const int N = 210;

struct edge{
    int u,v,w,id;
    bool operator<(const edge& t) const {
        return w < t.w;
    }
}e[N];

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        memset(e,0x00,sizeof e);
        int m = edges.size();
        for(int i = 0; i < m; i++) e[i] = {edges[i][0],edges[i][1],edges[i][2],i};
        sort(e,e + m);
        
        // ������С��������Ȩֵ
        int val = 0;
        UnionFind uf(n);
        for(int i = 0; i < m; i++) {
            if(uf.merge(e[i].u,e[i].v)) val += e[i].w;
        }

        vector<vector<int> > res(2);
        for(int i = 0; i < m; i++) {
            // ����ؼ���
            uf = UnionFind(n);
            int tval = 0;
            for(int j = 0; j < m; j++) {
                if(i != j && uf.merge(e[j].u,e[j].v)) tval += e[j].w;
            }
            if(uf.get() != 1 || (uf.get() == 1 && tval > val)) {
                res[0].push_back(e[i].id);
                continue;
            }

            // ����α�ؼ���
            uf = UnionFind(n);
            tval = e[i].w;
            uf.merge(e[i].u,e[i].v);
            for(int j = 0; j < m; j++) {
                if(i != j && uf.merge(e[j].u,e[j].v)) tval += e[j].w;
            }
            if(uf.get() == 1 && tval == val) res[1].push_back(e[i].id);
        }

        return res;
    }
};

����һ�� n?����Ĵ�Ȩ������ͨͼ���ڵ���Ϊ 0?�� n-1?��ͬʱ����һ������ edges?������ edges[i] = [fromi, toi, weighti]?��ʾ��?fromi?��?toi?�ڵ�֮����һ����Ȩ����ߡ���С������?(MST) �Ǹ���ͼ�бߵ�һ���Ӽ��������������нڵ���û�л���������Щ�ߵ�Ȩֵ����С��

�����ҵ�����ͼ����С�����������йؼ��ߺ�α�ؼ��ߡ������ͼ��ɾȥĳ���ߣ��ᵼ����С��������Ȩֵ�����ӣ���ô���Ǿ�˵����һ���ؼ��ߡ�α�ؼ������ǿ��ܻ������ĳЩ��С�������е����������������С�������еıߡ�

��ע�⣬����Էֱ�������˳�򷵻عؼ��ߵ��±��α�ؼ��ߵ��±ꡣ

?

ʾ�� 1��



���룺n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
�����[[0,1],[2,3,4,5]]
���ͣ���ͼ�����˸���ͼ��
��ͼ�����е���С��������

ע�⵽�� 0 ���ߺ͵� 1 ���߳�������������С�������У����������ǹؼ��ߣ����ǽ��������±���Ϊ����ĵ�һ���б�
�� 2��3��4 �� 5 ������ MST ��ʣ��ߣ�����������α�ؼ��ߡ����ǽ�������Ϊ����ĵڶ����б�
ʾ�� 2 ��



���룺n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
�����[[],[0,1,2,3]]
���ͣ����Թ۲쵽 4 ���߶�����ͬ��Ȩֵ����ѡ�����е� 3 �������γ�һ�� MST ������ 4 ���߶���α�ؼ��ߡ�
?

��ʾ��

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti?<= 1000
���� (fromi, toi)?���Զ��ǻ�����ͬ�ġ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
