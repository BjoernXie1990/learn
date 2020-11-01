class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                for(int k = 0; i + k < n && j + k < m; k++) {
                    cnt += (s[i+k] != t[j+k]);
                    if(cnt > 1) break;
                    if(cnt == 1) ans++;
                }
            } 

        // for(int len = 1; len <= n; len++) {
        //     for(int i = 0; i <= n - len; i++) {
        //         string s1 = s.substr(i,len);
                
        //         for(int j = 0; j <= m - len; j++) {
        //             string s2 = t.substr(j,len);
                    
        //             sort(s1.begin(),s1.begin());
        //             sort(s2.begin(),s2.begin());
        //             int is = 0;
        //             for(int k = 0;  k < len; k++) if(s1[k] != s2[k]) is++; else if(is == 2) break;
                    
        //             if(is == 1) ans++;
        //         }
        //     }
        // }
        
        return ans;
    }
};


���������ַ���?s ��?t?�������ҳ� s?�еķǿ��Ӵ�����Ŀ����Щ�Ӵ������滻 һ����ͬ�ַ�?�Ժ��� t?�����Ӵ�������֮�������ҵ� s?�� t?���� ǡ��?ֻ��һ���ַ���ͬ�����ַ����Ե���Ŀ��

�ȷ�˵��?"computer" ��?"computation" �Ӵֲ���ֻ��һ���ַ���ͬ��?'e'/'a'?��������һ�����ַ�������𰸼� 1 ��

���㷵���������������Ĳ�ͬ���ַ�������Ŀ��

һ�� ���ַ���?��һ���ַ������������ַ���

?

ʾ�� 1��

���룺s = "aba", t = "baba"
�����6
���ͣ�����Ϊֻ��� 1 ���ַ��� s �� t �������ַ����ԣ�
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
�Ӵֲ��ֱַ��ʾ s �� t ��ѡ���������ַ�����
ʾ�� 2��
���룺s = "ab", t = "bb"
�����3
���ͣ�����Ϊֻ��� 1 ���ַ��� s �� t �������ַ����ԣ�
("ab", "bb")
("ab", "bb")
("ab", "bb")
�Ӵֲ��ֱַ��ʾ s �� t ��ѡ���������ַ�����
ʾ�� 3��
���룺s = "a", t = "a"
�����0
ʾ�� 4��

���룺s = "abe", t = "bbc"
�����10
?

��ʾ��

1 <= s.length, t.length <= 100
s ��?t?��ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
