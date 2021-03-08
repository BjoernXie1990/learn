class Solution {
public:

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > f(n + 1, vector<bool> (n + 1, false));
        for(int len = 1; len <= n; len ++)
            for(int i = 1; i + len - 1 <= n; i ++) {
                int j = i + len - 1;
                if(len == 1) 
                    f[i][j] = true;
                else if(s[i - 1] == s[j - 1]) {
                    if(i + 1 == j)
                        f[i][j] = true;
                    else f[i][j] = f[i + 1][j - 1];
                }
            }
        
        vector<int> res(n + 1,0);
        for(int i = 1; i <= n; i++) {
            if(f[1][i])
                res[i] = 0;
            else {
                res[i] = i;
                for(int j = 1; j < i; j++)
                    if(f[j + 1][i]) res[i] = min(res[i],res[j] + 1);
            }
        }
        
        return res[n];
    }
};


����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��ġ�

���ط���Ҫ��� ���ٷָ���� ��

?

ʾ�� 1��

���룺s = "aab"
�����1
���ͣ�ֻ��һ�ηָ�Ϳɽ�?s �ָ�� ["aa","b"] �������������Ӵ���
ʾ�� 2��

���룺s = "a"
�����0
ʾ�� 3��

���룺s = "ab"
�����1
?

��ʾ��

1 <= s.length <= 2000
s ����СдӢ����ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-partitioning-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
