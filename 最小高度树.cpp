����һ������������������ͼ�����ǿ�ѡ���κ�һ���ڵ���Ϊ����ͼ��˿��Գ�Ϊ���������п��ܵ����У�������С�߶ȵ�������Ϊ��С�߶���������������һ��ͼ��д��һ�������ҵ����е���С�߶������������ǵĸ��ڵ㡣

��ʽ

��ͼ����?n?���ڵ㣬���Ϊ?0?��?n - 1����������?n?��һ�������?edges?�б�ÿһ���߶���һ�Ա�ǩ����

����Լ���û���ظ��ı߻������?edges?�С��������еı߶�������ߣ� [0, 1]��?[1, 0]?����ͬ�ģ���˲���ͬʱ������?edges?�

ʾ�� 1:

����: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

���: [1]
ʾ�� 2:

����: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

���: [3, 4]
˵��:

?�������Ķ��壬����һ������ͼ�������κ���������ֻͨ��һ��·�����ӡ� ���仰˵��һ���κ�û�м򵥻�·����ͨͼ����һ������
���ĸ߶���ָ���ڵ��Ҷ�ӽڵ�֮�������·���ϱߵ�������


class Solution {
public:
    //��ʱ
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        if(n == 0)  return {};
        if(edges.size() == 0)
        {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
                tmp.push_back(i);
            return tmp;
        }
        int minH = INT_MAX;
        unordered_map<int,vector<int> > ans;
        unordered_map<int,set<int> > map;

        for(auto& eoch : edges)
        {
            map[eoch[1]].insert(eoch[0]);
            map[eoch[0]].insert(eoch[1]);
        }
        
        for(int i = 0; i < n; i++)
        {
            unordered_map<int,int> visit;
            int tmp = dfs(map,visit,i);
            ans[tmp].push_back(i);
            minH = min(minH,tmp);
        }
        
        return ans[minH];
    }

    int dfs(unordered_map<int,set<int> >& map,unordered_map<int,int>& visit, int u)
    {
        int ret = INT_MIN;
        for(auto& v : map[u])
        {
            if(visit.find(v) != visit.end() || visit[v] == 1)
                continue;
            visit[u] = 1;
            ret = max(ret,1 + dfs(map,visit,v));
            visit[u] = 0;
        }
        return ret==INT_MIN ? 0 : ret;
    }

	//�������� 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)  return {};
        if(edges.size() == 0)
        {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
                tmp.push_back(i);
            return tmp;
        }

        unordered_map<int,unordered_set<int> > map;
        for(auto& edge : edges)
        {
            map[edge[0]].insert(edge[1]);
            map[edge[1]].insert(edge[0]);
        }

        queue<int> que;
        for(int i = 0; i < n; i++)
            if(map[i].size() == 1)
                que.push(i);
        
        while(n > 2)
        {
            int size = que.size();
            n -= size;
            while(size--)
            {
                int f = que.front();
                que.pop();
                for(auto& v : map[f])
                {
                    map[v].erase(f);
                    if(map[v].size() == 1) que.push(v);
                }
            }
        }

        vector<int> ans;
        while(!que.empty())
        {
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};
