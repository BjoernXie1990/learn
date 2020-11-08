class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        int f[n+1],last[26];
        memset(f,0x00,sizeof f);
        memset(last,0x00,sizeof last);
        
        f[0] = 0;
        f[1] = 1; last[s[0] - 'a'] = 1;
        for(int i = 2; i <= n; i++) {
            char idx = s[i - 1] - 'a';
            f[i] = (f[i - 1] * 2 + 1) % mod;

            if(last[idx] != 0) {        // last[idx]Ϊ������һ����ͬ�ַ����ֵ�λ�ã�-1 Ϊǰһ��λ��
                f[i] = (f[i] - f[last[idx] - 1] - 1 + mod) % mod;
            }
            last[idx] = i; 
        }

        return f[n];
    }
};


����һ���ַ���?S������?S?�Ĳ�ͬ�ǿ������еĸ�����

��Ϊ������ܴܺ����Է��ش�ģ 10^9 + 7.

?

ʾ�� 1��

���룺"abc"
�����7
���ͣ�7 ����ͬ�������зֱ��� "a", "b", "c", "ab", "ac", "bc", �Լ� "abc"��
ʾ�� 2��

���룺"aba"
�����6
���ͣ�6 ����ͬ�������зֱ��� "a", "b", "ab", "ba", "aa" �Լ� "aba"��
ʾ�� 3��

���룺"aaa"
�����3
���ͣ�3 ����ͬ�������зֱ��� "a", "aa" �Լ� "aaa"��
?

?

��ʾ��

S?ֻ����Сд��ĸ��
1 <= S.length <= 2000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/distinct-subsequences-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
