����һ���������ַ�����?board?��������������·����ַ�?'S'?������

���Ŀ���ǵ������������Ͻǵ��ַ�?'E' ������ʣ��Ĳ���Ϊ�����ַ�?1, 2, ..., 9?�����ϰ� 'X'����ÿһ���ƶ��У���������ϡ�����������Ϸ��ƶ��������ƶ���ǰ���ǵ���ĸ���û���ϰ���

һ��·���� ���÷֡� ����Ϊ��·�����������ֵĺ͡�

���㷵��һ���б�����������������һ�������� ���÷֡� �����ֵ���ڶ��������ǵõ����÷ֵķ���������ѽ����?10^9 + 7 ȡ�ࡣ

���û���κ�·�����Ե����յ㣬�뷵��?[0, 0] ��

?

ʾ�� 1��

���룺board = ["E23","2X2","12S"]
�����[7,1]
ʾ�� 2��

���룺board = ["E12","1X1","21S"]
�����[4,2]
ʾ�� 3��

���룺board = ["E11","XXX","11S"]
�����[0,0]


class Solution {
public:
    const int mod = 1000000007;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int> > dp(row, vector<int> (col,0));
        vector<vector<int> > dp2(row, vector<int> (col,0));
        
        dp2[row-1][col-1] = 1;
        //��ʼ�����һ��
        for(int i = col-1; i > 0; i--)
            if(board[row-1][i-1] != 'X')
            {
                dp[row-1][i-1] = (board[row-1][i-1] - '0' + dp[row-1][i]) % mod;
                dp2[row-1][i-1] = 1;

            }
            else break;

        //���һ��
        for(int i = row-1; i > 0; i--)
            if(board[i-1][col-1] != 'X')
            {
                dp[i-1][col-1] = (board[i-1][col-1] - '0' + dp[i][col-1]) % mod;
                dp2[i-1][col-1] = 1;
            }
            else break;

        for(int i = row-2; i >= 0; i--)
            for(int j = col-2; j >= 0; j--)
            {
                if(board[i][j] == 'X')  continue;
                int a = dp[i+1][j];
                int b = dp[i][j+1];
                int c = dp[i+1][j+1];
                int maxNum = max(max(a,b),c);
               
                int d = dp2[i+1][j];
                int e = dp2[i][j+1];
                int f = dp2[i+1][j+1];

                //��ֹ���ֲ�ͨ��·
                if(maxNum == 0 && d == 0 && e == 0 && f == 0)
                {
                    dp[i][j] = 0;
                    dp2[i][j] = 0;
                    continue;
                }

                //�÷֣�dp
                dp[i][j] = (maxNum % mod + ((board[i][j] == 'E') ?  0 : (board[i][j] - '0'))) % mod; 

                //������ߵ�·��
                if(a==max(max(a,b),c))
                    dp2[i][j] += dp2[i+1][j]%mod;
                if(b==max(max(a,b),c))
                    dp2[i][j] += dp2[i][j+1]%mod;
                if(c==max(max(a,b),c))
                    dp2[i][j] += dp2[i+1][j+1]%mod;
            }
        
        return {dp[0][0],dp2[0][0] % mod};
    }
};
