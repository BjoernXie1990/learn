����һ�� �����޻�ͼ �� n ���ڵ���Ϊ 0 �� n-1 ���Լ�һ�������� edges ������ edges[i] = [fromi, toi] ��ʾһ���ӵ�  fromi ���� toi ������ߡ�

�ҵ���С�ĵ㼯ʹ�ô���Щ������ܵ���ͼ�����е㡣��Ŀ��֤�������Ψһ��

�����������˳�򷵻���Щ�ڵ��š�

 

ʾ�� 1��



���룺n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
�����[0,3]
���ͣ��ӵ����ڵ�����޷��������нڵ㡣�� 0 �������ǿ��Ե��� [0,1,2,5] ���� 3 �������ǿ��Ե��� [3,4,2,5] ������������� [0,3] ��
ʾ�� 2��



���룺n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
�����[0,2,3]
���ͣ�ע�⵽�ڵ� 0��3 �� 2 �޷��������ڵ㵽��������Ǳ��뽫���ǰ����ڽ���㼯�У���Щ�㶼�ܵ���ڵ� 1 �� 4 ��
 

��ʾ��

2 <= n <= 10^5
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi < n
���е�� (fromi, toi) ������ͬ��

class Solution {
public:
    unordered_map<int,set<int> > map_from;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> sum(n,0);
        for(auto eoch : edges){
            map_from[eoch[0]].insert(eoch[1]);
            sum[eoch[1]]++;
        }
        
//         queue<int> que;
//         vector<bool> vis(n,false);
//         for(int i = 0; i < n; i++)
//             if(sum[i] == 0){
//                 que.push(i);
//                 vis[i] = true;
//             }
        
         vector<int> ans;
        
//         while(!que.empty())
//         {
//             int size = que.size();
//             while(size--){
//                 int f = que.front();
//                 que.size();
            
//                 ans.push_back(f);
//                 dfs(f,sum,vis);
//             }
            
            
//             for(int i = 0; i < n; i++)
//                 if(sum[i] == 0 && vis[i] == false){
//                     que.push(i);
//                     vis[i] = true;
//                 }
//         }
        
        for(int i = 0; i < n; i++)
            if(sum[i] == 0){
                ans.push_back(i);
            }
        return ans;
    }
    
    void dfs(int u,vector<int>& sum,vector<bool>& vis){
        for(auto& v : map_from[u]){
            if(vis[v] == true)  continue;
            
            vis[v] = true;
            sum[v]--;
        }
    }
};
