class Solution {
public:
    unordered_map<int,set<int> > um;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        for(auto& eoch : roads) {
            um[eoch[0]].insert(eoch[1]);
            um[eoch[1]].insert(eoch[0]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                ans = max(ans,BFS(i,j,n));
            }
        
        return ans;
    }
    
    int BFS(int a,int b,int n) {

        int ret = 0;
        for(auto& v : um[a]) {
            if(v == b) continue;
            ret++;
        }
        for(auto& v : um[b]) {
            if(v == a) continue;
            ret++;
        }
        
        int oper = um[a].find(b) == um[a].end() ? 0 : 1;
        return ret + oper;
    }
};

n �����к�һЩ������Щ���еĵ�· roads ��ͬ���һ��������ʩ���硣ÿ�� roads[i] = [ai, bi] ����ʾ�ڳ��� ai �� bi ֮����һ��˫���·��

������ͬ���й��ɵ� ���ж� �� ������ ����Ϊ�������������� ֱ�� �����ĵ�·�������������һ����·ֱ���������������У���������·ֻ���� һ�� ��

����������ʩ����� ��������� �����в�ͬ���ж��е� ��������� ��

�������� n ������ roads����������������ʩ����� ��������� ��

?

ʾ�� 1��



���룺n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
�����4
���ͣ����� 0 �� 1 ���������� 4����Ϊ���� 4 ����·����� 0 �� 1 ������λ�� 0 �� 1 ֮��ĵ�·ֻ����һ�Ρ�
ʾ�� 2��



���룺n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
�����5
���ͣ����� 5 ����·����� 1 �� 2 ������
ʾ�� 3��

���룺n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
�����5
���ͣ�2 �� 5 ��������Ϊ 5��ע�Ⲣ�����еĳ��ж���Ҫ����������
?

��ʾ��

2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi?<= n-1
ai?!=?bi
ÿ�Գ���֮�� ���ֻ��һ��?��·����
ͨ������1,961�ύ����4,404

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximal-network-rank
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
