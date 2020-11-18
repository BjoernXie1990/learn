class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int leb[n + 1],ria[n + 2];
        memset(leb,0x00,sizeof leb);
        memset(ria,0x00,sizeof ria);
        for(int i = 0; i < n; i ++) leb[i + 1] = leb[i] + (s[i] == 'b' ? 1 : 0);
        for(int i = n - 1; i >= 0; i--) ria[i + 1] = ria[i + 2] + (s[i] == 'a' ? 1 : 0);

        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            ans = min(ans,leb[i] + ria[i] - 1);
        }
        return ans;
    }
};


����һ���ַ���?s?�����������ַ�?'a' ��?'b'???? ��

�����ɾ��?s?��������Ŀ���ַ���ʹ��?s ƽ��?�����ǳ�?s?ƽ���?���������±��?(i,j)?����?i < j ��?s[i] = 'b'?ͬʱ?s[j]= 'a'?��

���㷵��ʹ s?ƽ��?�� ����?ɾ��������

?

ʾ�� 1��

���룺s = "aababbab"
�����2
���ͣ������ѡ����������һ�ַ�����
�±�� 0 ��ʼ��ɾ���� 2 �͵� 6 ���ַ���"aababbab" -> "aaabbb"����
�±�� 0 ��ʼ��ɾ���� 3 �͵� 6 ���ַ���"aababbab" -> "aabbbb"����
ʾ�� 2��

���룺s = "bbaaaaabb"
�����2
���ͣ�Ψһ�����Ž���ɾ����ǰ�������ַ���
?

��ʾ��

1 <= s.length <= 105
s[i]?Ҫô��?'a' Ҫô��?'b'??��?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
