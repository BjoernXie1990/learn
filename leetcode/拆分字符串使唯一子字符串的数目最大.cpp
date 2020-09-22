class Solution {
public:
    unordered_set<string> set_t;
    int ans = 0;
    int n = 0;
    int maxUniqueSplit(string s) {
        n = s.size();
        dfs(s,0);
        return ans==0 ? -1 : ans;
    }
    
    void dfs(string& s,int idx) {
        if(idx == s.size()) {
            ans = max((int)set_t.size(),ans);
            return ;
        }
        string str("");
        for(int i = idx; i < n; i++) {
            str += s[i];
            if(set_t.find(str) == set_t.end())  {
                set_t.insert(str);
                dfs(s,i+1);
                set_t.erase(set_t.find(str));
            }
        }
    }
};

����һ���ַ��� s �������ָ��ַ����������ز�ֺ�Ψһ���ַ����������Ŀ��

�ַ��� s ��ֺ���Եõ����� �ǿ����ַ��� ����Щ���ַ������Ӻ�Ӧ���ܹ���ԭΪԭ�ַ��������ǲ�ֳ�����ÿ�����ַ����������� Ψһ�� ��

ע�⣺���ַ��� ���ַ����е�һ�������ַ����С�

?

ʾ�� 1��

���룺s = "ababccc"
�����5
���ͣ�һ������ַ���Ϊ ['a', 'b', 'ab', 'c', 'cc'] ���� ['a', 'b', 'a', 'b', 'c', 'cc'] ������ֲ�������ĿҪ����Ϊ���е� 'a' �� 'b' �������˲�ֹһ�Ρ�
ʾ�� 2��

���룺s = "aba"
�����2
���ͣ�һ������ַ���Ϊ ['a', 'ba'] ��
ʾ�� 3��

���룺s = "aa"
�����1
���ͣ��޷���һ������ַ�����
?

��ʾ��

1 <= s.length?<= 16

s ������СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
