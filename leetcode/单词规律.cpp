class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> f1;
        unordered_map<string,char> f2;
        int n = pattern.size();
        int m = s.size();

        int p = 0;
        for(auto ch : pattern) {
            if(p >= m) return false;

            int ri = p;
            while(ri < m && s[ri] != ' ') 
                ri++;
            
            string t = s.substr(p,ri - p);
            if(f1.count(ch) && f1[ch] != t)
                return false;
            if(f2.count(t) && f2[t] != ch)
                return false;
            
            f1[ch] = t;
            f2[t] = ch;
            p = ri + 1;
        }

        return p >= m;
    }
};


����һ�ֹ��� pattern?��һ���ַ���?str?���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�

�����?��ѭ?ָ��ȫƥ�䣬���磬?pattern?���ÿ����ĸ���ַ���?str?�е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�

ʾ��1:

����: pattern = "abba", str = "dog cat cat dog"
���: true
ʾ�� 2:

����:pattern = "abba", str = "dog cat cat fish"
���: false
ʾ�� 3:

����: pattern = "aaaa", str = "dog cat cat dog"
���: false
ʾ��?4:

����: pattern = "abba", str = "dog dog dog dog"
���: false
˵��:
����Լ���?pattern?ֻ����Сд��ĸ��?str?�������ɵ����ո�ָ���Сд��ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-pattern
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
