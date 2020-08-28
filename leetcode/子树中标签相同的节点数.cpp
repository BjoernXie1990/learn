����һ����������һ����ͨ���޻�����ͼ����������ɱ�Ŵ� 0? �� n - 1 �� n ���ڵ���ɣ���ǡ���� n - 1 �� edges �����ĸ��ڵ�Ϊ�ڵ� 0 �����ϵ�ÿһ���ڵ㶼��һ����ǩ��Ҳ�����ַ��� labels �е�һ��Сд�ַ������Ϊ i �� �ڵ�ı�ǩ���� labels[i] ��

������ edges �� edges[i] = [ai, bi] ����ʽ�������ø�ʽ��ʾ�ڵ� ai �� bi ֮�����һ���ߡ�

����һ����СΪ n �����飬���� ans[i] ��ʾ�� i ���ڵ����������ڵ� i ��ǩ��ͬ�Ľڵ�����

�� T �е��������� T �е�ĳ���ڵ㼰�����к���ڵ���ɵ�����

?

ʾ�� 1��



���룺n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
�����[2,1,1,1,1,1,1]
���ͣ��ڵ� 0 �ı�ǩΪ 'a' ���� 'a' Ϊ���ڵ�������У��ڵ� 2 �ı�ǩҲ�� 'a' ����˴�Ϊ 2 ��ע�����е�ÿ���ڵ㶼�����������һ���֡�
�ڵ� 1 �ı�ǩΪ 'b' ���ڵ� 1 �����������ڵ� 1��4 �� 5�����ǽڵ� 4��5 �ı�ǩ��ڵ� 1 ��ͬ���ʶ���Ϊ 1�������ýڵ㱾����
ʾ�� 2��



���룺n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
�����[4,2,1,1]
���ͣ��ڵ� 2 ��������ֻ�нڵ� 2 �����Դ�Ϊ 1 ��
�ڵ� 3 ��������ֻ�нڵ� 3 �����Դ�Ϊ 1 ��
�ڵ� 1 �������а����ڵ� 1 �� 2 ����ǩ���� 'b' ����˴�Ϊ 2 ��
�ڵ� 0 �������а����ڵ� 0��1��2 �� 3����ǩ���� 'b'����˴�Ϊ 4 ��
ʾ�� 3��



���룺n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
�����[3,2,1,1,1]
ʾ�� 4��

���룺n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"
�����[1,2,1,1,2,1]
ʾ�� 5��

���룺n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels = "aaabaaa"
�����[6,5,4,1,3,2,1]
?

��ʾ��

1 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai,?bi < n
ai !=?bi
labels.length == n
labels ����СдӢ����ĸ���

class Solution {
public:
    unordered_map<int,vector<int> > map_t;
    vector<bool> vis;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vis.resize(n+1,false);
        for(auto& eoch : edges){
            map_t[eoch[0]].push_back(eoch[1]);
            map_t[eoch[1]].push_back(eoch[0]);
        }

        vector<int> ans(n,0);
        dfs(ans,labels,0);

        return ans;
    }

    vector<int> dfs(vector<int>& ans,string& labels,int root){
       vis[root] = true;
       vector<int> tmp(26,0);

       for(auto eoch : map_t[root]){
           if(vis[eoch] == true)    continue;

            auto child = dfs(ans,labels,eoch);
            for(int i = 0; i < 26; i++)
                tmp[i] += child[i];
       }
       ans[root] = ++tmp[labels[root] - 'a'];
       return tmp;
    }
};
