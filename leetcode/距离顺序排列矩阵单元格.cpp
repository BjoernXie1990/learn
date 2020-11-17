class Solution {
public:
    typedef pair<int,int> PII;

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<PII> que;
        int f[R][C];
        memset(f,0x00,sizeof f);

        que.push(make_pair(r0,c0));
        f[r0][c0] = 1;
        vector<vector<int> > ans;

        while(!que.empty()) {
            int size = que.size();
            while(size --) {
                PII t = que.front();
                que.pop();
                ans.push_back({t.first,t.second});

                static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
                for(int i = 0; i < 4; i++) {
                    int x = t.first + dir[i][0];
                    int y = t.second + dir[i][1];
                    if(x < 0 || x >= R || y < 0 || y >= C || f[x][y]) continue;
                    que.push(make_pair(x,y));
                    f[x][y] = 1;
                }
            }
        }
        return ans;
    }
};

���� R �� C �еľ������еĵ�Ԫ�����������Ϊ (r, c)������ 0 <= r < R �� 0 <= c < C��

���⣬�����ڸþ����и�����һ������Ϊ?(r0, c0) �ĵ�Ԫ��

���ؾ����е����е�Ԫ������꣬������ (r0, c0) �ľ������С������˳���ţ����У�����Ԫ��(r1, c1) �� (r2, c2) ֮��ľ����������پ��룬|r1 - r2| + |c1 - c2|��������԰��κ������������˳�򷵻ش𰸡���

?

ʾ�� 1��

���룺R = 1, C = 2, r0 = 0, c0 = 0
�����[[0,0],[0,1]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1]
ʾ�� 2��

���룺R = 2, C = 2, r0 = 0, c0 = 1
�����[[0,1],[0,0],[1,1],[1,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 3��

���룺R = 2, C = 3, r0 = 1, c0 = 2
�����[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2,2,3]
����������ĿҪ��Ĵ�Ҳ�ᱻ��Ϊ��ȷ������ [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]��
?

��ʾ��

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/matrix-cells-in-distance-order
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
