class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int cnt[26];
        memset(cnt, -1,sizeof cnt);

        int n = s.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(cnt[idx] == -1) cnt[idx] = i;
            else {
                ans = max(ans, i - cnt[idx] - 1);
            }
        }

        return ans;
    }
};

����һ���ַ��� s�����㷵�� ������ͬ�ַ�֮�������ַ����ĳ��� �����㳤��ʱ�����������ַ���������������������ַ��������� -1 ��

���ַ��� ���ַ����е�һ�������ַ����С�

?

ʾ�� 1��

���룺s = "aa"
�����0
���ͣ����ŵ����ַ��������� 'a' ֮��Ŀ����ַ�����
ʾ�� 2��

���룺s = "abca"
�����2
���ͣ����ŵ����ַ����� "bc" ��
ʾ�� 3��

���룺s = "cbzxy"
�����-1
���ͣ�s �в����ڳ��ֳ������ε��ַ������Է��� -1 ��
ʾ�� 4��

���룺s = "cabbac"
�����4
���ͣ����ŵ����ַ����� "abba" �������ķ����Ž���� "bb" �� "" ��
?

��ʾ��

1 <= s.length <= 300
s ֻ��СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
