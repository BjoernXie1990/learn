class Solution {
public:
    const int N = 40010;
    int f[40010],sz[40010];
    int dir[4][2] = {-1,0,0,-1,1,0,0,1};
    void init() {
        for(int i = 0; i < N; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if(f[x] != x) f[x] = find(f[x]);
        return f[x];
    }

    void merge(int a,int b) {
        a = find(a);
        b = find(b);
        if(a == b) return ;
        f[a] = b;
        sz[b] += sz[a];
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int h = grid.size(), w = grid[0].size();
        init();
        vector<vector<int> > status = grid;
        for(auto& e : hits) status[e[0]][e[1]] = 0;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(status[i][j] == 1) {
                    if(i == 0) merge(h*w,i * w + j);
                    if(i > 0 && status[i-1][j]) merge(i * w + j,(i - 1) * w + j);
                    if(j > 0 && status[i][j-1]) merge(i * w + j,i * w + j - 1);
                }
        
        vector<int> res(hits.size(),0);
        for(int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if(grid[r][c] == 0) continue;
            int prev = sz[find(h*w)];
            if(r == 0) merge(c,h*w);
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if(nr >= 0 && nc >= 0 && nr < h && nc < w && status[nr][nc])    merge(r * w + c, nr * w + nc);
            }
            int size = sz[find(h*w)];
            res[i] = max(0,size - prev - 1);
            status[r][c] = 1;
        }
        return res;
    }
};

��һ�� m x n �Ķ�Ԫ�������� 1 ��ʾש�飬0 ��ʾ�հס�ש�� �ȶ���������䣩��ǰ���ǣ�

һ��שֱ�����ӵ�����Ķ���������
������һ�����ڣ�4?������֮һ��ש�� �ȶ� �������ʱ
����һ������ hits ��������Ҫ��������ש���λ�á�ÿ������?hits[i] = (rowi, coli) λ���ϵ�ש��ʱ����Ӧλ�õ�ש�飨�����ڣ�����ʧ��Ȼ��������ש�������Ϊ��һ�������������䡣һ��ש����䣬������������������ʧ���������������������ȶ���ש���ϣ���

����һ������ result ������ result[i] ��ʾ�� i ������������Ӧ�����ש����Ŀ��

ע�⣬��������ָ����û��ש��Ŀհ�λ�ã�������������������û��ש����䡣

?

ʾ�� 1��

���룺grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
�����[2]
���ͣ�
����ʼΪ��
[[1,0,0,0]��
 [1,1,1,0]]
���� (1,0) ���Ӵֵ�ש�飬�õ�����
[[1,0,0,0]
 [0,1,1,0]]
�����Ӵֵ�ש�����ȶ�����Ϊ���ǲ����붥��������Ҳ��������һ���ȶ���ש���ڣ�������ǽ����䡣�õ�����
[[1,0,0,0],
 [0,0,0,0]]
��ˣ����Ϊ [2] ��
ʾ�� 2��

���룺grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
�����[0,0]
���ͣ�
����ʼΪ��
[[1,0,0,0],
 [1,1,0,0]]
���� (1,1) ���Ӵֵ�ש�飬�õ�����
[[1,0,0,0],
 [1,0,0,0]]
ʣ�µ�ש�����ȶ������Բ�����䡣���񱣳ֲ��䣺
[[1,0,0,0], 
 [1,0,0,0]]
���������� (1,0) ���Ӵֵ�ש�飬�õ�����
[[1,0,0,0],
 [0,0,0,0]]
ʣ�µ�ש����Ȼ���ȶ��ģ����Բ�����ש����䡣
��ˣ����Ϊ [0,0] ��
?

��ʾ��

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[i][j] Ϊ 0 �� 1
1 <= hits.length <= 4 * 104
hits[i].length == 2
0 <= xi?<= m - 1
0 <=?yi <= n - 1
���� (xi, yi) ������ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/bricks-falling-when-hit
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
