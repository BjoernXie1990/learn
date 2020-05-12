//����һ��?rows x cols?��С�ľ���������һ������ k?�����ΰ��������ַ���?'A' ����ʾƻ������?'.'?����ʾ�հ׸��ӣ�������Ҫ������ k-1 �Σ��õ�?k?���������͸����ˡ�

//��������ÿһ������Ҫѡ������ֱ����ˮƽ�����У����ھ��εı߽���ѡһ���е�λ�ã�������һ��Ϊ���������ֱ������������ô��Ҫ����ߵĲ����͸�һ���ˣ����ˮƽ���У���ô��Ҫ������Ĳ����͸�һ���ˡ����������һ������Ҫ��ʣ������һ���͸����һ���ˡ�

//���㷵��ȷ��ÿһ����������?����?һ��ƻ���������������������ڴ𰸿����Ǹ��ܴ�����֣����㷵������ 10^9 + 7 ȡ��Ľ����

//?


class Solution {
public:
    const int mod = 1000000007;
    int dp[15][55][55];//dp[k][i][j], ��ʾ��k�����꣬���Ͻ���i,j���з�
    int n,m;
    int num[55][55];//ǰ׺��
    int ways(vector<string>& pizza, int K) {
        int n = pizza.size();
        int m = pizza[0].size();

        //����ǰ׺��
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                num[i][j] = num[i-1][j] + num[i][j-1] - num[i-1][j-1] + (pizza[i-1][j-1] == 'A');
        
        dp[0][1][1] = 1;
        for(int k = 1; k < K; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                {
                    //�жϵ�ǰλ�õ���������½��Ƿ���ƻ��
                    if(GetRight(i,j,n,m) <= 0) break;

                    //ȷ����������ƻ����
                    for(int x = 1; x < i; x++)//���и�
                    {
                        dp[k][i][j] += dp[k-1][x][j] * (GetRight(x,j,i-1,m)>=1);
                        dp[k][i][j] %= mod;
                    }

                    for(int y = 1; y < j; y++)//������
                    {
                        dp[k][i][j] += dp[k-1][i][y] * (GetRight(i,y,n,j-1)>=1);
                        dp[k][i][j] %= mod;
                    }
                }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans = (ans + dp[K-1][i][j]) % mod;
        return ans;
    }

    int GetRight(int x1,int y1,int x2,int y2)
    {
        return num[x2][y2] - num[x1-1][y2] - num[x2][y1-1] + num[x1-1][y1-1];
    }

};
