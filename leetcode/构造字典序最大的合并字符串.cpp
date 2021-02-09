class Solution {
public:
    string res;
    int n,m;
    string largestMerge(string s, string t) {
        n = s.size(), m = t.size();
        res = "";
        for(int i = 0, j = 0; i < n || j < m; ) {
            if(i == n || (j != m && s.substr(i) <= t.substr(j))) {
                res += t[j ++];
            } else  {
                res += s[i++];
            }
        }
        
        return res;
    }
};

���������ַ��� word1 �� word2 ������Ҫ��������ʽ����һ�����ַ��� merge ����� word1 �� word2 �ǿգ�ѡ�� ����ѡ��֮һ ����������

��� word1 �ǿգ��� word1 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word1 ���Ƴ���
���磬word1 = "abc" �� merge = "dv" ����ִ�д�ѡ�����֮��word1 = "bc" ��ͬʱ merge = "dva" ��
��� word2 �ǿգ��� word2 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word2 ���Ƴ���
���磬word2 = "abc" �� merge = "" ����ִ�д�ѡ�����֮��word2 = "bc" ��ͬʱ merge = "a" ��
��������Թ�����ֵ��� ��� �ĺϲ��ַ��� merge ��

������ͬ�������ַ��� a �� b �Ƚ��ֵ����С������� a �� b ���ֲ�ͬ�ĵ�һ��λ�ã�a ���ַ�����ĸ���еĳ���˳��λ�� b ����Ӧ�ַ�֮�󣬾���Ϊ�ַ��� a ���ֵ�����ַ��� b �������磬"abcd" ���ֵ���� "abcc" ������Ϊ�����ַ������ֲ�ͬ�ĵ�һ��λ���ǵ��ĸ��ַ����� d ����ĸ���еĳ���˳��λ�� c ֮��

?

ʾ�� 1��

���룺word1 = "cabaa", word2 = "bcaaa"
�����"cbcabaaaaa"
���ͣ������ֵ������ĺϲ��ַ��������е�һ�ַ���������ʾ��
- �� word1 ��ȡ��һ���ַ���merge = "c"��word1 = "abaa"��word2 = "bcaaa"
- �� word2 ��ȡ��һ���ַ���merge = "cb"��word1 = "abaa"��word2 = "caaa"
- �� word2 ��ȡ��һ���ַ���merge = "cbc"��word1 = "abaa"��word2 = "aaa"
- �� word1 ��ȡ��һ���ַ���merge = "cbca"��word1 = "baa"��word2 = "aaa"
- �� word1 ��ȡ��һ���ַ���merge = "cbcab"��word1 = "aa"��word2 = "aaa"
- �� word1 �� word2 ��ʣ�µ� 5 �� a ���ӵ� merge ��ĩβ��
ʾ�� 2��

���룺word1 = "abcabc", word2 = "abdcaba"
�����"abdcabcabcaba"
?

��ʾ��

1 <= word1.length, word2.length <= 3000
word1 �� word2 ����СдӢ�����
ͨ������1,833�ύ����5,514

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-merge-of-two-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
