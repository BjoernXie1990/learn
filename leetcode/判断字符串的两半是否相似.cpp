class Solution {
public:
    bool halvesAreAlike(string s) {
        int l = 0 ,r = 0;
        int n = s.size();
        
        int f[255];
        f['a'] = f['e'] = f['i'] = f['o'] = f['u'] = 1;
        f['A'] = f['E'] = f['I'] = f['O'] = f['U'] = 1;
        
        for(int i = 0; i < n/ 2; i++) {
            if(f[s[i]] == 1) l++;
        }
        
        for(int i = n/2; i < n; i++) {
            if(f[s[i]] == 1) r++;
        }
        
        return l == r;
    }
};

����һ��ż�����ȵ��ַ��� s �������ֳɳ�����ͬ�����룬ǰһ��Ϊ a ����һ��Ϊ b ��

�����ַ��� ���� ��ǰ�������Ƕ�������ͬ��Ŀ��Ԫ����'a'��'e'��'i'��'o'��'u'��'A'��'E'��'I'��'O'��'U'����ע�⣬s ����ͬʱ���д�д��Сд��ĸ��

��� a �� b ���ƣ����� true �����򣬷��� false ��

?

ʾ�� 1��

���룺s = "book"
�����true
���ͣ�a = "bo" �� b = "ok" ��a ���� 1 ��Ԫ����b Ҳ�� 1 ��Ԫ�������ԣ�a �� b ���ơ�
ʾ�� 2��

���룺s = "textbook"
�����false
���ͣ�a = "text" �� b = "book" ��a ���� 1 ��Ԫ����b ���� 2 ��Ԫ������ˣ�a �� b �����ơ�
ע�⣬Ԫ�� o �� b �г������Σ���Ϊ 2 ����
ʾ�� 3��

���룺s = "MerryChristmas"
�����false
ʾ�� 4��

���룺s = "AbCdEfGh"
�����true
?

��ʾ��

2 <= s.length <= 1000
s.length ��ż��
s �� ��д��Сд ��ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/determine-if-string-halves-are-alike
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
