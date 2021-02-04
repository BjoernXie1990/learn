class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(255,0);
        int le = 0, cnt = 0, res = 0;
        for(int i = 0; i < s.size(); i++) {
            f[s[i]] ++;
            cnt = max(cnt,f[s[i]]);
            if(i - le + 1 - k > cnt) f[s[le++]] --;
            res = max(res,i - le + 1);
        }
        return res;
    }
};

����һ�����ɴ�дӢ����ĸ��ɵ��ַ���������Խ�����λ���ϵ��ַ��滻��������ַ����ܹ�������滻?k?�Ρ���ִ�������������ҵ������ظ���ĸ����Ӵ��ĳ��ȡ�

ע�⣺�ַ������� �� k ���ᳬ��?104��

?

ʾ�� 1��

���룺s = "ABAB", k = 2
�����4
���ͣ�������'A'�滻Ϊ����'B',��֮��Ȼ��
ʾ�� 2��

���룺s = "AABABBA", k = 1
�����4
���ͣ�
���м��һ��'A'�滻Ϊ'B',�ַ�����Ϊ "AABBBBA"��
�Ӵ� "BBBB" ����ظ���ĸ, ��Ϊ 4��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-repeating-character-replacement
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
