class Solution {
public:
    int f[100005];
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x]; 
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for(int i = 0; i < n; i++) f[i] = i;
        for(auto& e : pairs) {
            int x = find(e[0]);
            int y = find(e[1]);
            if(x != y) f[x] = y;
        }
        
        unordered_map<int,multiset<int> > mp;
        for(int i = 0; i < n; i++)  mp[find(i)].insert(s[i]);

        for(int i = 0; i < n; i++) {
            auto it = mp[find(i)].begin();
            s[i] = *it;
            mp[find(i)].erase(it);
        }

        return s;
    }
};


����һ���ַ���?s���Լ����ַ����е�һЩ�������ԡ�����?pairs������?pairs[i] =?[a, b]?��ʾ�ַ����е�������������Ŵ� 0 ��ʼ����

����� �����ν��� ��?pairs?������һ�����������ַ���

�����ھ������ɴν�����s?���Ա�ɵİ��ֵ�����С���ַ�����

?

ʾ�� 1:

���룺s = "dcab", pairs = [[0,3],[1,2]]
�����"bacd"
���ͣ� 
���� s[0] �� s[3], s = "bcad"
���� s[1] �� s[2], s = "bacd"
ʾ�� 2��

���룺s = "dcab", pairs = [[0,3],[1,2],[0,2]]
�����"abcd"
���ͣ�
���� s[0] �� s[3], s = "bcad"
���� s[0] �� s[2], s = "acbd"
���� s[1] �� s[2], s = "abcd"
ʾ�� 3��

���룺s = "cba", pairs = [[0,1],[1,2]]
�����"abc"
���ͣ�
���� s[0] �� s[1], s = "bca"
���� s[1] �� s[2], s = "bac"
���� s[0] �� s[1], s = "abc"
?

��ʾ��

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] <?s.length
s?��ֻ����СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/smallest-string-with-swaps
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
