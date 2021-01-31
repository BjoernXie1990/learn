
const int N = 1e4 * 2 + 10;
struct edge{
    int u,v,w;
    bool operator<(const edge& t) const  {
        return w < t.w;
    }
}e[N];

class unionFind{
    public:
        unionFind(int n) : f(n) {
            for(int i = 0; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            f[x] = y;
            return true;
        }
    private:
        vector<int> f;
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        memset(e,0x00,sizeof e);
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                int idx = i * m + j;
                if(i > 0) e[cnt ++] = {idx, (i-1)*m + j,abs(heights[i][j] - heights[i-1][j])};
                if(j > 0) e[cnt ++] = {idx, idx - 1, abs(heights[i][j] - heights[i][j-1])};
            }
        sort(e,e+cnt);

        unionFind uf(n*m);
        for(int i = 0; i < cnt; i++) {
            int x = e[i].u, y = e[i].v, w = e[i].w;
            uf.merge(x,y);
            if(uf.find(0) == uf.find(n * m - 1) )  return w;
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
