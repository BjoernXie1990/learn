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


����һ��points?���飬��ʾ 2D ƽ���ϵ�һЩ�㣬����?points[i] = [xi, yi]?��

���ӵ�?[xi, yi] �͵�?[xj, yj]?�ķ���Ϊ����֮��� �����پ���?��|xi - xj| + |yi - yj|?������?|val|?��ʾ?val?�ľ���ֵ��

���㷵�ؽ����е����ӵ���С�ܷ��á�ֻ����������֮�� ���ҽ���?һ����·��ʱ������Ϊ���е㶼�����ӡ�

?

ʾ�� 1��



���룺points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
�����20
���ͣ�

���ǿ��԰�����ͼ��ʾ�������е�õ���С�ܷ��ã��ܷ���Ϊ 20 ��
ע�⵽����������֮��ֻ��Ψһһ��·�����ൽ�
ʾ�� 2��

���룺points = [[3,12],[-2,5],[-4,1]]
�����18
ʾ�� 3��

���룺points = [[0,0],[1,1],[1,0],[-1,1]]
�����4
ʾ�� 4��

���룺points = [[-1000000,-1000000],[1000000,1000000]]
�����4000000
ʾ�� 5��

���룺points = [[0,0]]
�����0
?

��ʾ��

1 <= points.length <= 1000
-106?<= xi, yi <= 106
���е�?(xi, yi)?������ͬ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/min-cost-to-connect-all-points
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
