struct edge{
    int u,v,w;
    bool operator<(const edge& t) const {
        return w < t.w;
    }
};

class Solution {
public:
    vector<edge> edges;
    vector<vector<int> > p;
    int n;
    int get(int x,int y) {
        return abs(p[x][0] - p[y][0]) + abs(p[x][1] - p[y][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        p = points;
        edges.reserve(n*n);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                edges.push_back({i,j,get(i,j)});

        return kruskal();
    }

    vector<int> f;
    vector<bool> st;
    void init() {
        st.resize(n,false);
        f.reserve(n);
        for(int i = 0; i < n; i++) f[i] = i;
    }

    int find(int x) {
        if(f[x] != x) f[x] = find(f[x]);
        return f[x];
    }

    int kruskal() {
        init();

        sort(edges.begin(),edges.end());

        int res = 0;
        int cnt = 1;
        for(auto& e : edges) {
            if(cnt == n) break;
            int idx = e.u, idy = e.v;
            int x = find(idx);
            int y = find(idy);
            if(x == y) continue;
            f[x] = y;
            res += e.w;
            cnt++;
        }
        return res;
    }
};


给你一个points?数组，表示 2D 平面上的一些点，其中?points[i] = [xi, yi]?。

连接点?[xi, yi] 和点?[xj, yj]?的费用为它们之间的 曼哈顿距离?：|xi - xj| + |yi - yj|?，其中?|val|?表示?val?的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有?一条简单路径时，才认为所有点都已连接。

?

示例 1：



输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
示例 2：

输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
示例 3：

输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
示例 4：

输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
示例 5：

输入：points = [[0,0]]
输出：0
?

提示：

1 <= points.length <= 1000
-106?<= xi, yi <= 106
所有点?(xi, yi)?两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
