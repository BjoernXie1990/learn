class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int le = 0 , cnt = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            cnt += abs(s[i] - t[i]);
            while(le <= i && cnt > maxCost) {
                cnt -= abs(s[le] - t[le]);
                le++;
            }
            res = max(res,i - le + 1);
        }

        return res;
    }
};


��������������ͬ���ַ�����s �� t��

�� s?�еĵ�?i?���ַ��䵽?t?�еĵ� i ���ַ���Ҫ?|s[i] - t[i]|?�Ŀ�������������Ϊ 0����Ҳ���������ַ��� ASCII ��ֵ�Ĳ�ľ���ֵ��

���ڱ���ַ��������Ԥ����?maxCost����ת���ַ���ʱ���ܿ���Ӧ��С�ڵ��ڸ�Ԥ�㣬��Ҳ��ζ���ַ�����ת�������ǲ���ȫ�ġ�

�������Խ� s �����ַ���ת��Ϊ���� t �ж�Ӧ�����ַ������򷵻ؿ���ת������󳤶ȡ�

��� s ��û�����ַ�������ת���� t �ж�Ӧ�����ַ������򷵻� 0��

?

ʾ�� 1��

���룺s = "abcd", t = "bcdf", cost = 3
�����3
���ͣ�s �е� "abc" ���Ա�Ϊ "bcd"������Ϊ 3��������󳤶�Ϊ 3��
ʾ�� 2��

���룺s = "abcd", t = "cdef", cost = 3
�����1
���ͣ�s �е���һ�ַ�Ҫ���� t �ж�Ӧ���ַ����俪������ 2����ˣ���󳤶�Ϊ 1��
ʾ�� 3��

���룺s = "abcd", t = "acde", cost = 0
�����1
���ͣ����޷������κθĶ���������󳤶�Ϊ 1��
?

��ʾ��

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s ��?t?��ֻ��СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/get-equal-substrings-within-budget
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
