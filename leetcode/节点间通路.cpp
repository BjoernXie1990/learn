class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int> > mp(n);
        for(auto& e : graph) mp[e[0]].push_back(e[1]);

        queue<int> que;
        que.push(start);
        vector<bool> vis(n,false);
        vis[start] = true;

        while(!que.empty()) {
            int f = que.front();
            que.pop();

            for(auto& e : mp[f]) {
                if(vis[e]) continue;
                if(e == target) return true;
                vis[e] = true;
                que.push(e);
            }
        }

        return false;
    }
};

�ڵ��ͨ·����������ͼ�����һ���㷨���ҳ������ڵ�֮���Ƿ����һ��·����

ʾ��1:

 ���룺n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 �����true
ʾ��2:

 ���룺n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 ��� true
��ʾ��

�ڵ�����n��[0, 1e5]��Χ�ڡ�
�ڵ��Ŵ��ڵ��� 0 С�� n��
ͼ�п��ܴ����Ի���ƽ�бߡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/route-between-nodes-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
