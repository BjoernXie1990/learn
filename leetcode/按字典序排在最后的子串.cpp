����һ���ַ���?s���ҳ����������Ӵ������ֵ������У��������������Ǹ��Ӵ���

?

ʾ�� 1��

���룺"abab"
�����"bab"
���ͣ����ǿ����ҳ� 7 ���Ӵ� ["a", "ab", "aba", "abab", "b", "ba", "bab"]�����ֵ������������Ӵ��� "bab"��
ʾ��?2��

���룺"leetcode"
�����"tcode"
?

��ʾ��

1 <= s.length <= 4 * 10^5
s ������СдӢ���ַ���


class Solution {
public:
    string lastSubstring(string s) {
        int p = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i-1] >= s[i])  continue;
            if(strcmp(&s[p],&s[i]) < 0) p = i;
        }
        return s.substr(p);
    }
};
