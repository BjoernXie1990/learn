class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> f(n,0);

        for(int i = 1, j = 0; i < n; i++) {
            while(j && s[j] != s[i])
                j = f[j - 1];
            if(s[j] == s[i])
                j++;
            f[i] = j;
        }

        return s.substr(0,f[n-1]);
    }
};


������ǰ׺������ԭ�ַ����м���?�ǿ� ǰ׺Ҳ�Ǻ�׺��������ԭ�ַ����������ַ�����

����һ���ַ��� s�����㷵������ �����ǰ׺��

������������������ǰ׺���򷵻�һ�����ַ�����

?

ʾ�� 1��

���룺s = "level"
�����"l"
���ͣ������� s �Լ���һ���� 4 ��ǰ׺��"l", "le", "lev", "leve"���� 4 ����׺��"l", "el", "vel", "evel"������ļ���ǰ׺Ҳ�Ǻ�׺���ַ����� "l" ��
ʾ�� 2��

���룺s = "ababab"
�����"abab"
���ͣ�"abab" ����ļ���ǰ׺Ҳ�Ǻ�׺���ַ�������Ŀ����ǰ��׺��ԭ�ַ������ص���
ʾ�� 3��

���룺s = "leetcodeleet"
�����"leet"
ʾ�� 4��

���룺s = "a"
�����""
?

��ʾ��

1 <= s.length <= 10^5
s ֻ����СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-happy-prefix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
