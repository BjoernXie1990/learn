class Solution {
public:
    int calc(int x,int y,char op) {
        if(op == '|') return x | y;
        if(op == '&') return x & y;
        return x ^ y;
    }

    int countEval(string s, int result) {
        int n = s.size() / 2 + 1;
        vector<int> num(n), op(n-1);    // n�����֣�n-1��������
        for(int i = 0; i < n; i++) {
            num[i] = s[i * 2] - '0';
            if(i != n - 1)
                op[i] = s[i * 2 + 1];
        }
        // iλ�õĲ���������������������Ϊ  [ , i] [i + 1, ]

        int dp[n+1][n+1][3];
        memset(dp,0x00,sizeof dp);
        for(int i = 0; i < n; i++)
            dp[i][i][num[i]] = 1;      // ��ʼ��ÿ��λ���� 0,1�ķ�����
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                for(int j = i; j < i + len - 1; j++) {

                    // ���ֻ���Ϊ�������� [i, j] [j + 1, i + len -1]
                    // ���������м�Ĳ�����λ�� op[j]
                    for(int x = 0; x <= 1; x++)
                        for(int y = 0; y <= 1; y++)
                            dp[i][i + len - 1][calc(x,y,op[j])] += dp[i][j][x] * dp[j + 1][i + len - 1][y];
                }
            }
        }

        return dp[0][n-1][result];
    }


};

����һ���������ʽ��һ�������Ĳ������ result���������ʽ�� 0 (false)��1 (true)��& (AND)�� | (OR) �� ^ (XOR) ������ɡ�ʵ��һ������������м��ֿ�ʹ�ñ��ʽ�ó� result ֵ�����ŷ�����

ʾ�� 1:

����: s = "1^0|0|1", result = 0

���: 2
����:?���ֿ��ܵ����ŷ�����
1^(0|(0|1))
1^((0|0)|1)
ʾ�� 2:

����: s = "0&0&0&1^1|0", result = 1

���: 10
��ʾ��

����������������� 19 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/boolean-evaluation-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
