����һ���ɲ�ͬ�ַ���ɵ��ַ���?allowed?��һ���ַ�������?words?�����һ���ַ�����ÿһ���ַ����� allowed?�У��ͳ�����ַ����� һ��?�ַ�����

���㷵��?words?������?һ��?�ַ�������Ŀ��

?

ʾ�� 1��

���룺allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
�����2
���ͣ��ַ��� "aaab" �� "baa" ����һ���ַ�������Ϊ����ֻ�����ַ� 'a' �� 'b' ��
ʾ�� 2��

���룺allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
�����7
���ͣ������ַ�������һ�µġ�
ʾ�� 3��

���룺allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
�����4
���ͣ��ַ��� "cc"��"acd"��"ac" �� "d" ��һ���ַ�����
?

��ʾ��

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
allowed?�е��ַ� ������ͬ?��
words[i] ��?allowed?ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-the-number-of-consistent-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> cnt(26,0);
        for(auto& e : allowed) cnt[e - 'a']++;
        
        int ans = 0;
        for(auto& e : words) {
            vector<int> t = cnt;
            bool falg = true;
            for(auto& ch : e) {
                if(t[ch - 'a'] == 0) {
                    falg = false;
                    break;
                }
            }
            if(falg) ans++;
        }
        return ans;
    }
};
