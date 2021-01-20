class Solution {
public:
    int f[1010];
    int find(int x) {
        if( x != f[x] ) f[x] = find(f[x]);
        return f[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for(int j = 1; j < m; j++) {
                string s = accounts[i][j];
                if(mp.count(s)) {
                    int x = find(mp[s]);
                    int y = find(i);
                    f[x] = y;
                } else mp[s] = i;
            }
        }

        vector<vector<string> > res;
        unordered_map<int,vector<string> > hash;
        for(auto& e : mp) {
            int v = find(e.second);
            hash[v].push_back(e.first);
        }
        for(auto& e : hash) {
            auto& vec = e.second;
            sort(vec.begin(),vec.end());
            vector<string> t = {accounts[e.first][0]};
            t.insert(t.end(),vec.begin(),vec.end());
            res.push_back(t);
        }
        return res;
    }
};

����һ���б� accounts��ÿ��Ԫ�� accounts[i]?��һ���ַ����б����е�һ��Ԫ�� accounts[i][0]?��?���� (name)������Ԫ���� emails ��ʾ���˻��������ַ��

���ڣ�������ϲ���Щ�˻�����������˻�����һЩ��ͬ�������ַ���������˻��ض�����ͬһ���ˡ���ע�⣬��ʹ�����˻�������ͬ�����ƣ�����Ҳ�������ڲ�ͬ���ˣ���Ϊ���ǿ��ܾ�����ͬ�����ơ�һ�����������ӵ�������������˻������������˻���������ͬ�����ơ�

�ϲ��˻��󣬰����¸�ʽ�����˻���ÿ���˻��ĵ�һ��Ԫ�������ƣ�����Ԫ���ǰ�˳�����е������ַ���˻��������������˳�򷵻ء�

?

ʾ�� 1��

���룺
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
�����
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
���ͣ�
��һ���͵����� John ��ͬһ���ˣ���Ϊ�����й�ͬ�������ַ "johnsmith@mail.com"�� 
�ڶ��� John �� Mary �ǲ�ͬ���ˣ���Ϊ���ǵ������ַû�б������ʻ�ʹ�á�
�������κ�˳�򷵻���Щ�б������ [['Mary'��'mary@mail.com']��['John'��'johnnybravo@mail.com']��
['John'��'john00@mail.com'��'john_newyork@mail.com'��'johnsmith@mail.com']] Ҳ����ȷ�ġ�
?

��ʾ��

accounts�ĳ��Ƚ���[1��1000]�ķ�Χ�ڡ�
accounts[i]�ĳ��Ƚ���[1��10]�ķ�Χ�ڡ�
accounts[i][j]�ĳ��Ƚ���[1��30]�ķ�Χ�ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/accounts-merge
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
