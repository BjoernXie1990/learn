const int N = 1e5 + 10;

struct node{
    int a,b,c,d;
    bool operator<(const node& t) {
        return c < t.c;
    }
}e[N],q[N];

class Solution {
public:
    vector<int> p;

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> distanceLimitedPathsExist(int nn, vector<vector<int>>& ee, vector<vector<int>>& qq) {
        int n = ee.size(), m  = qq.size();
        p.resize(nn);
        for(int i = 0; i < nn; i++) p[i] = i;
        for(int i = 0; i < n; i++) e[i] = {ee[i][0],ee[i][1],ee[i][2]};
        for(int i = 0; i < m; i++) q[i] = {qq[i][0],qq[i][1],qq[i][2],i};
        sort(e,e+n);
        sort(q,q+m);

        vector<bool> ans(m,false);

        for(int i = 0, j = 0; i < m; i++) {
            while(j < n && e[j].c < q[i].c) {
                p[find(e[j].a)] = find(e[j].b);
                j++;
            }

            ans[q[i].d] = (find(q[i].a) == find(q[i].b));
        }

        return ans;
    }
};


����һ�� n?������ɵ�����ͼ�߼�?edgeList?������?edgeList[i] = [ui, vi, disi]?��ʾ��?ui �͵�?vi?֮����һ������Ϊ?disi?�ıߡ���ע�⣬������֮������� ����һ����?��

����һ����ѯ����queries?������?queries[j] = [pj, qj, limitj]?����������Ƕ���ÿ����ѯ?queries[j]?���ж��Ƿ���ڴ�?pj?��?qj?��·����������·���ϵ�ÿһ���߶� �ϸ�С��?limitj?��

���㷵��һ�� ��������?answer?������?answer.length == queries.length?����?queries[j]?�Ĳ�ѯ���Ϊ?true?ʱ��?answer ��?j?��ֵΪ?true?������Ϊ?false?��

?

ʾ�� 1��


���룺n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
�����[false,true]
���ͣ���ͼΪ�������������ݡ�ע�⵽ 0 �� 1 ֮���������رߣ��ֱ�Ϊ 2 �� 16 ��
���ڵ�һ����ѯ��0 �� 1 ֮��û��С�� 2 �ıߣ��������Ƿ��� false ��
���ڵڶ�����ѯ����һ��·����0 -> 1 -> 2�������߶�С�� 5 �����������ѯ���Ƿ��� true ��
ʾ�� 2��


���룺n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
�����[true,false]
���ͣ���ͼΪ�������ݡ�
?

��ʾ��

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
������֮������� ����?�ߡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/checking-existence-of-edge-length-limited-paths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
