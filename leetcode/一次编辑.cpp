class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size();
        int m = second.size();
        int t = n - m;
        if(abs(t) > 1) return false;

        // ��������
        int cnt = 1;
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(first[i] == second[j]) i++,j++;
            else {
                if(t == 1) i++;     // second ���һ���ַ�
                else if(t == -1) j++;   // second ɾ��һ���ַ�
                else if(t == 0) i++,j++;    // second �滻һ���ַ�
                cnt--;
                if(cnt < 0) return false;
            }
        }
        return true;

        // int f[n+1][m+1];
        // memset(f,0x00,sizeof f);
        // for(int i = 0; i <= n; i++) f[i][0] = i;
        // for(int j = 0; j <= m; j++) f[0][j] = j;

        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= m; j++) {
        //         if(first[i - 1] == second[j - 1]) f[i][j] = f[i-1][j-1];
        //         else f[i][j] = min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1]) + 1;
        //     }
        // return f[n][m] <= 1;
    }
};


�ַ��������ֱ༭����:����һ���ַ���ɾ��һ���ַ������滻һ���ַ��� ���������ַ�������дһ�������ж������Ƿ�ֻ��Ҫһ��(�������)�༭��

?

ʾ��?1:

����: 
first = "pale"
second = "ple"
���: True
?

ʾ��?2:

����: 
first = "pales"
second = "pal"
���: False

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/one-away-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
