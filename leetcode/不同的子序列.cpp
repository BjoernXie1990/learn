class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        long long f[n+1][m+1];
        memset(f,0x00,sizeof f);

        for(int i = 0; i <= n; i++)
            f[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(s[i-1] == t[j-1])
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                else
                    f[i][j] = f[i- 1][j];
        
        return f[n][m];
    }
};


����һ���ַ��� s ��һ���ַ��� t �������� s ���������� t ���ֵĸ�����

�ַ�����һ�� ������ ��ָ��ͨ��ɾ��һЩ��Ҳ���Բ�ɾ�����ַ��Ҳ�����ʣ���ַ����λ������ɵ����ַ����������磬"ACE"?��?"ABCDE"?��һ�������У���?"AEC"?���ǣ�

��Ŀ���ݱ�֤�𰸷��� 32 λ������������Χ��

?

ʾ��?1��

���룺s = "rabbbit", t = "rabbit"
�����3
���ͣ�
����ͼ��ʾ, �� 3 �ֿ��Դ� s �еõ� "rabbit" �ķ�����
(�ϼ�ͷ���� ^ ��ʾѡȡ����ĸ)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
ʾ��?2��

���룺s = "babgbag", t = "bag"
�����5
���ͣ�
����ͼ��ʾ, �� 5 �ֿ��Դ� s �еõ� "bag" �ķ����� 
(�ϼ�ͷ���� ^ ��ʾѡȡ����ĸ)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
?

��ʾ��

0 <= s.length, t.length <= 1000
s �� t ��Ӣ����ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/distinct-subsequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
