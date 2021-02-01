class unionFind{
    public:
        unionFind(int n) :f(n) {
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

const int N = 50 * 50 * 2 + 10;
struct edge{
    int u,v,w;
    bool operator<(const edge& t) const  {
        return w < t.w;
    }
}e[N];

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                if(i > 0) e[cnt ++] = {idx,idx - n, max(grid[i][j],grid[i-1][j])};
                if(j > 0) e[cnt ++] = {idx,idx - 1, max(grid[i][j],grid[i][j-1])};
            }
        
        sort(e,e+cnt);
        unionFind uf(n*n);
        int res = 0;
        for(int i = 0; i < cnt; i++) {
            int x = e[i].u, y = e[i].v, w = e[i].w;
            if(w > res) res = w;
            uf.merge(x,y);
            if(uf.find(0) == uf.find(n*n-1)) return res;
        }
        return 0;
    }
};

��һ�� N x N �����귽��?grid �У�ÿһ�������ֵ grid[i][j] ��ʾ��λ�� (i,j) ��ƽ̨�߶ȡ�

���ڿ�ʼ�����ˡ���ʱ��Ϊ?t?ʱ����ʱ��ˮ����ˮ��������λ�õ�ˮλΪ?t?������Դ�һ��ƽ̨�����������ڵ�����һ��ƽ̨������ǰ���Ǵ�ʱˮλ����ͬʱ��û������ƽ̨���ٶ������˲���ƶ����޾��룬Ҳ����Ĭ���ڷ����ڲ��ζ��ǲ���ʱ�ġ���Ȼ��������Ӿ��ʱ�������������귽�����档

������귽�������ƽ̨ (0��0) ���������ٺ�ʱ�������ܵ������귽�������ƽ̨?(N-1, N-1)��

?

ʾ�� 1:

����: [[0,2],[1,3]]
���: 3
����:
ʱ��Ϊ0ʱ����λ�����귽���λ��Ϊ (0, 0)��
��ʱ�㲻���������ⷽ����Ϊ�ĸ����ڷ���ƽ̨�ĸ߶ȶ����ڵ�ǰʱ��Ϊ 0 ʱ��ˮλ��

��ʱ�䵽�� 3 ʱ����ſ�������ƽ̨ (1, 1). ��Ϊ��ʱ��ˮλ�� 3�����귽���е�ƽ̨û�б�ˮλ 3 ���ߵģ�����������������귽���е�����λ��
ʾ��2:

����: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
���: 16
����:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

���յ�·���üӴֽ����˱�ǡ�
���Ǳ���ȵ�ʱ��Ϊ 16����ʱ���ܱ�֤ƽ̨ (0, 0) �� (4, 4) ����ͨ��
?

��ʾ:

2 <= N <= 50.
grid[i][j] �� [0, ..., N*N - 1] �����С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/swim-in-rising-water
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
