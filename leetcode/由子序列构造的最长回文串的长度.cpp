class Solution {
public:
    int longestPalindrome(string s, string t) {
        reverse(t.begin(),t.end());
        int n = s.size(), m = t.size();
        vector<vector<int> > f1(n + 1, vector<int> (m + 1, 0));
        vector<vector<int> > f2(n + 2, vector<int> (n + 2, 0));
        vector<vector<int> > f3(m + 2, vector<int> (m + 2, 0));
        
        // ��������������еĳ���
        work(s,f2);
        work(t,f3);
        
        // ����������еĳ���
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]);
                if(s[i - 1] == t[j - 1])
                    f1[i][j] = max(f1[i][j], f1[i - 1][j - 1] + 1);
            } 
        
        // ������
        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(f1[i][j])
                    res = max(res, f1[i][j] * 2 + max(f2[i + 1][n], f3[j + 1][m]));
        
        return res;
    }
    
    void work(string& s,vector<vector<int> >& f) {
        int n = s.size();
        for(int len = 1; len <= n; len ++) 
            for(int i = 1; i + len - 1 <= n; i ++) {
                int j = i + len - 1;
                if(len == 1) {
                    f[i][j] = 1;
                } else {
                     f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                    if(s[i - 1] == s[j - 1])
                        f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
                }
               
            }
        
    }
};

���������ַ��� word1 �� word2 �����㰴������������һ���ַ�����

�� word1 ��ѡ��ĳ�� �ǿ� ������ subsequence1 ��
�� word2 ��ѡ��ĳ�� �ǿ� ������ subsequence2 ��
�������������� subsequence1 + subsequence2 ���õ��ַ�����
���ؿɰ��������������� ���Ĵ� �� ���� ������޷�������Ĵ������� 0 ��

�ַ��� s ��һ�� ������ ��ͨ���� s ��ɾ��һЩ��Ҳ���ܲ�ɾ�����ַ��������������ַ���˳�����ɵ��ַ�����

���Ĵ� �����Ŷ��ͷ��Ŷ����һ�µ��ַ�����

 

ʾ�� 1��

���룺word1 = "cacb", word2 = "cbba"
�����5
���ͣ��� word1 ��ѡ�� "ab" ���� word2 ��ѡ�� "cba" ���õ����Ĵ� "abcba" ��
ʾ�� 2��

���룺word1 = "ab", word2 = "ab"
�����3
���ͣ��� word1 ��ѡ�� "ab" ���� word2 ��ѡ�� "a" ���õ����Ĵ� "aba" ��
ʾ�� 3��

���룺word1 = "aa", word2 = "bb"
�����0
���ͣ��޷���������������������Ĵ������Է��� 0 ��
 

��ʾ��

1 <= word1.length, word2.length <= 1000
word1 �� word2 ��СдӢ����ĸ���
