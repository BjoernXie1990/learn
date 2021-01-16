class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int dp[n+1][m+1];
        memset(dp,0x00,sizeof dp);

        dp[0][0] = 1;
        auto check = [&](int a,int b)->bool{
            if(a == 0) return false;
            if(p[b - 1] == '.') return true;
            return s[a - 1] == p[b - 1];
        };

        for(int i = 0; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if(check(i,j-1))    dp[i][j] |= dp[i-1][j];
                } else if(check(i,j))
                    dp[i][j] |= dp[i-1][j-1];
            }
        
        return dp[n][m];
    }
};

��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ����ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣

ʾ�� 1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����
ʾ�� 2:

����:
s = "aa"
p = "a*"
���: true
����:?��Ϊ '*' �������ƥ���������ǰ�����һ��Ԫ��, ������ǰ���Ԫ�ؾ��� 'a'����ˣ��ַ��� "aa" �ɱ���Ϊ 'a' �ظ���һ�Ρ�
ʾ��?3:

����:
s = "ab"
p = ".*"
���: true
����:?".*" ��ʾ��ƥ�����������'*'�������ַ���'.'����
ʾ�� 4:

����:
s = "aab"
p = "c*a*b"
���: true
����:?��Ϊ '*' ��ʾ������������� 'c' Ϊ 0 ��, 'a' ���ظ�һ�Ρ���˿���ƥ���ַ��� "aab"��
ʾ�� 5:

����:
s = "mississippi"
p = "mis*is*p*."
���: false
s?����Ϊ�գ���ֻ������?a-z?��Сд��ĸ��
p?����Ϊ�գ���ֻ������?a-z?��Сд��ĸ�Լ��ַ�?.?��?*���������� '*'��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
