����һ������ͼgraph�������ͼΪ����ͼʱ����true��

��������ܽ�һ��ͼ�Ľڵ㼯�Ϸָ�������������Ӽ�A��B����ʹͼ�е�ÿһ���ߵ������ڵ�һ������A���ϣ�һ������B���ϣ����Ǿͽ����ͼ��Ϊ����ͼ��

graph�������ڽӱ�ʽ������graph[i]��ʾͼ����ڵ�i���������нڵ㡣ÿ���ڵ㶼��һ����0��graph.length-1֮�����������ͼ��û���Ի���ƽ�бߣ�?graph[i]?�в�����i������graph[i]��û���ظ���ֵ��


ʾ�� 1:
����: [[1,3], [0,2], [1,3], [0,2]]
���: true
����: 
����ͼ����:
0----1
|    |
|    |
3----2
���ǿ��Խ��ڵ�ֳ�����: {0, 2} �� {1, 3}��

ʾ�� 2:
����: [[1,2,3], [0,2], [0,1,3], [0,2]]
���: false
����: 
����ͼ����:
0----1
| \  |
|  \ |
3----2
���ǲ��ܽ��ڵ�ָ�������������Ӽ���
ע��:

graph �ĳ��ȷ�ΧΪ [1, 100]��
graph[i] �е�Ԫ�صķ�ΧΪ [0, graph.length - 1]��
graph[i] ������� i �������ظ���ֵ��
ͼ�������: ���j �� graph[i]���, ��ô i Ҳ���� graph[j]��ߡ�



class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n,-1);

        for(int i = 0; i < n; i++)
            if(visit[i] == -1 && !dfs(graph,i,0,visit))
                return false;
        
        return true;
    }

    bool dfs(vector<vector<int> >& graph,int i,int flag,vector<int>& visit)
    {
        if(visit[i] != -1)   return visit[i] == flag;

        visit[i] = flag;
        for(auto u : graph[i])
            if(!dfs(graph,u,!flag,visit))
                return false;
        return true;
    }
};
