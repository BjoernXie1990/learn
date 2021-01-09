class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);   // 0 δ������ 1 �ɻ�  2 dfs�б�����
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(!DFS(i,vis,graph)) vis[i] = 1;
            else res.push_back(i);
        }

        return res;
    }

    bool DFS(int u,vector<int>& vis,vector<vector<int>>& graph) {
        if(vis[u]) return vis[u] == 2;

        vis[u] = 1;
        for(auto& e : graph[u]) {
            if(vis[e] == 2) continue;
            if(vis[e] == 1 || !DFS(e,vis,graph)) return false;
        }

        vis[u] = 2;
        return true;
    }
};

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<set<int> > mp(n);        // �����¼
        vector<int> cnt(n);             // ����
        queue<int> que;
        for(int i = 0; i < n; i++) {
            cnt[i] = graph[i].size();
            if(cnt[i] == 0) {
                que.push(i);
                continue;
            }
            for(auto& e : graph[i])
                mp[e].insert(i);
        }

        vector<int> res;
        while(!que.empty()) {
            int f = que.front();
            que.pop();

            res.push_back(f);
            for(auto& e : mp[f]) {
                cnt[e] --;
                if(cnt[e] == 0) que.push(e);
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};


������ͼ��, ���Ǵ�ĳ���ڵ��ÿ��ת�򴦿�ʼ, ����ͼ��������ߡ� ������ǵ���Ľڵ����յ� (����û�������������), ����ֹͣ��

����, �������������ߵ��յ㣬��ô���ǵ���ʼ�ڵ������հ�ȫ�ġ� �������˵, ����һ����Ȼ�� K,? ����ѡ������￪ʼ����, �������˲��� K �������ֹͣ��һ���յ㡣

��Щ�ڵ������ǰ�ȫ�ģ� �������һ����������顣

������ͼ�� N ���ڵ㣬��ǩΪ 0, 1, ..., N-1, ���� N ��?graph?�Ľڵ���.? ͼ�����µ���ʽ����: graph[i] �ǽڵ� j ��һ���б����� (i, j) ��ͼ��һ������ߡ�

ʾ����
���룺graph = [[1,2],[2,3],[5],[0],[5],[],[]]
�����[2,4,5,6]
��������ͼ��ʾ��ͼ��



��ʾ��

graph �ڵ��������� 10000.
ͼ�ı������ᳬ�� 32000.
ÿ�� graph[i] ������Ϊ��ͬ�������б� ������ [0, graph.length - 1]?��ѡȡ��
ͨ������6,670�ύ����14,079

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-eventual-safe-states
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
