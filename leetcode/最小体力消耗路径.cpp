class Solution {
public:
// ���鼯
    class Union {
    public:
        Union(int n) {
            fa.reserve(n);
            for(int i = 0; i < n; i++) fa[i] = i;
        }

        int find(int p) {
            while(p != fa[p]) {
                fa[p] = fa[fa[p]];
                p = fa[p];
            }
            return fa[p];
        }

        void check(int x,int y) {
            int tx = find(x);
            int ty = find(y);
            if(tx == ty) return ;
            fa[ty] = tx;
        }

        bool connect(int x,int y) {
            int tx = find(x);
            int ty = find(y);
            return tx == ty;
        }
    private:
        vector<int> fa;
    };
    struct Edge {
        int x,y,z;
        Edge(int _x,int _y,int _z) :x(_x),y(_y),z(_z)
        {}
        bool operator<(const Edge& b) {
            return z < b.z;
        }
    };
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<Edge> e;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) {
                int idx = i * m + j;
                if(i > 0) e.push_back({idx - m,idx,abs(h[i][j] - h[i-1][j])});
                if(j > 0) e.push_back({idx - 1,idx,abs(h[i][j] - h[i][j-1])});
            }
        
        Union un(n*m);
        sort(e.begin(),e.end());

        for(auto& ed : e) {
            un.check(ed.x,ed.y);
            if(un.connect(0,n * m - 1)) return ed.z;
        }

        return 0;
    }
};


��׼���μ�һ��Զ��������һ����ά?rows x columns?�ĵ�ͼ?heights?������?heights[row][col]?��ʾ����?(row, col)?�ĸ߶ȡ�һ��ʼ���������Ͻǵĸ���?(0, 0)?������ϣ��ȥ�����½ǵĸ���?(rows-1, columns-1)?��ע���±�� 0 ��ʼ��ţ�����ÿ�ο����� �ϣ��£�����?�ĸ�����֮һ�ƶ�������Ҫ�ҵ��ķ� ���� ��С��һ��·����

һ��·���ķѵ� ����ֵ?��·�������ڸ���֮�� �߶Ȳ����ֵ?�� ���ֵ?�����ġ�

���㷵�ش����Ͻ��ߵ����½ǵ���С?��������ֵ?��

?

ʾ�� 1��



���룺heights = [[1,2,2],[3,8,2],[5,3,5]]
�����2
���ͣ�·�� [1,3,5,3,5] �������ӵĲ�ֵ����ֵ���Ϊ 2 ��
����·����·�� [1,2,2,2,5] ���ţ���Ϊ��һ��·����ֵ���ֵΪ 3 ��
ʾ�� 2��



���룺heights = [[1,2,3],[3,8,4],[5,3,5]]
�����1
���ͣ�·�� [1,2,3,4,5] �����ڸ��Ӳ�ֵ����ֵ���Ϊ 1 ����·�� [1,3,5,3,5] ���š�
ʾ�� 3��


���룺heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
�����0
���ͣ���ͼ��ʾ·������Ҫ�����κ�������
?

��ʾ��

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/path-with-minimum-effort
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
