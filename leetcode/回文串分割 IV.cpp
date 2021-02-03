const int N = 2010;
int f[N][N];

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        memset(f,0x00,sizeof f);

        for(int i = n - 1; i >= 0; i--)
            for(int j = i; j < n; j++) {
                if(j == i) f[i][j] = 1;
                else if(j - i == 1 && s[i] == s[j]) f[i][j] = 1;
                else if(f[i+1][j-1] && s[i] == s[j]) f[i][j] = 1;
            }
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n - 1; j++)
                if(f[0][i] && f[i+1][j] && f[j+1][n-1]) return true;
        return false;
    }
};

����һ���ַ���?s?��������Խ����ָ������?�ǿ�?�������ַ�������ô����?true?�����򷵻�?false?��

��һ���ַ������Ŷ��ͷ��Ŷ���һģһ���ģ��ͳ���Ϊ �����ַ��� ��

?

ʾ�� 1��

���룺s = "abcbdd"
�����true
���ͣ�"abcbdd" = "a" + "bcb" + "dd"���������ַ������ǻ��ĵġ�
ʾ�� 2��

���룺s = "bcbddxy"
�����false
���ͣ�s û�취���ָ�� 3 ���������ַ�����
?

��ʾ��

3 <= s.length <= 2000
s?????? ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-partitioning-iv
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
