class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int n = equations.size();
        int idx = 0;
        for(auto& e : equations) {
            if(mp.count(e[0]) == 0) mp[e[0]] = idx++;
            if(mp.count(e[1]) == 0) mp[e[1]] = idx++;
        }

        vector<vector<double> > f(idx,vector<double> (idx,0));
        for(int i = 0; i < n; i++) {
            int x = mp[equations[i][0]], y = mp[equations[i][1]];
            f[x][y] = values[i];
            f[y][x] = 1.0 / values[i];
        }

        for(int k = 0; k < idx; k++)
            for(int i = 0; i < idx; i++)
                for(int j = 0; j < idx; j++)
                    if(f[i][k] != 0 && f[k][j] != 0)
                        f[i][j] = f[i][k] * f[k][j];
        
        vector<double> res;
        for(auto& e : queries) {
            double t = -1.0;
            if(mp.count(e[0]) && mp.count(e[1])) {
                int x = mp[e[0]], y = mp[e[1]];
                if(f[x][y] != 0)    t = f[x][y];
            }
            res.push_back(t);
        }
        return res;
    }
};

����һ������������ equations ��һ��ʵ��ֵ���� values ��Ϊ��֪���������� equations[i] = [Ai, Bi] �� values[i] ��ͬ��ʾ��ʽ Ai / Bi = values[i] ��ÿ�� Ai �� Bi ��һ����ʾ�����������ַ�����

����һЩ������ queries ��ʾ�����⣬���� queries[j] = [Cj, Dj] ��ʾ�� j �����⣬���������֪�����ҳ� Cj / Dj = ? �Ľ����Ϊ�𰸡�

���� ��������Ĵ� ���������ĳ���޷�ȷ���Ĵ𰸣����� -1.0 �������𰸡�

?

ע�⣺����������Ч�ġ�����Լ�����������в�����ֳ���Ϊ 0 ��������Ҳ������κ�ì�ܵĽ����

?

ʾ�� 1��

���룺equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
�����[6.00000,0.50000,-1.00000,1.00000,-1.00000]
���ͣ�
������a / b = 2.0, b / c = 3.0
���⣺a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
�����[6.0, 0.5, -1.0, 1.0, -1.0 ]
ʾ�� 2��

���룺equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
�����[3.75000,0.40000,5.00000,0.20000]
ʾ�� 3��

���룺equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
�����[0.50000,2.00000,-1.00000,-1.00000]
?

��ʾ��

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj ��СдӢ����ĸ���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/evaluate-division
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
