�ܹ��� n?���˺� 40 �ֲ�ͬ��ñ�ӣ�ñ�ӱ�Ŵ� 1 �� 40 ��

����һ�������б���б�?hats?������?hats[i]?�ǵ� i?��������ϲ��ñ�ӵ��б�

�����ÿ���˰���һ����ϲ����ñ�ӣ�ȷ��ÿ���˴���ñ�Ӹ����˶���һ���������ط�������

���ڴ𰸿��ܴܺ��뷵������?10^9 + 7?ȡ���Ľ����

?

ʾ�� 1��

���룺hats = [[3,4],[4,5],[5]]
�����1
���ͣ�����������ֻ��һ�ַ���ѡ��ñ�ӡ�
��һ����ѡ��ñ�� 3���ڶ�����ѡ��ñ�� 4�����һ����ѡ��ñ�� 5��
ʾ�� 2��

���룺hats = [[3,5,1],[3,5]]
�����4
���ͣ��ܹ��� 4 �ְ���ñ�ӵķ�����
(3,5)��(5,3)��(1,3) �� (1,5)
ʾ�� 3��

���룺hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
�����24
���ͣ�ÿ���˶����Դӱ��Ϊ 1 �� 4 ��ñ����ѡ��
(1,2,3,4) 4 ��ñ�ӵ����з�����Ϊ 24 ��
ʾ�� 4��

���룺hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
�����111


class Solution {
public:
    const int mod = 1000000007;
    int numberWays1(vector<vector<int>>& hats) {
        int len = hats.size();//һ����len����
        int maxhats = 0;
        //��һ��ñ�ӵ������
        for(auto& row : hats)
            for(auto& col : row)
                maxhats = max(maxhats,col);
        
        vector<vector<int> > tmp(maxhats + 1);
        //���˶�Ӧñ�ӱ��ñ�Ӷ�Ӧ��
        for(int i = 0; i < len; i++)
            for(auto& col : hats[i])
                tmp[col].push_back(i);
        
        //dp[i][j] ǰi��ñ�ӣ������˵�״̬Ϊj �ķ�����
        //һ����10���ˣ�ÿ���˵�״̬�Ϳ����� һ��ֻ��һ��1��ʮλ�Ķ���������ʾ  2��ʮ�η�  = 1024
        //ȫ1 1111111111  ��ʾ������ñ��
        //ȫ0 0000000000  ��ʾû���˴�ñ��
        vector<vector<int> > dp(maxhats + 1, vector<int>(1<<len));
        dp[0][0] = 1;

        for(int i = 1; i <= maxhats; i++)
            for(int j = 0; j < (1<<len); j++)//0 -->  1<<len  ��ʾ�˴�û��һ������ñ�ӵ�ȫ���˶�����ñ�ӵ�״̬
            {
                dp[i][j] = dp[i-1][j];//��û��ʹ�����ñ�ӣ�˳����һ�ε�״̬

                for(auto& k : tmp[i])//������i��ñ�ӿ��Դ�����
                    if(j & (1<<k)) //��������ô������ñ��
                        dp[i][j] = (dp[i-1][j ^ (1<<k)] + dp[i][j]) % mod;
                        //�ۼ���ǰһ��ñ��ʱ����˲���ñ�ӵķ��ϵ������ʹ�������һ����λ
            }
        
        return dp[maxhats][(1<<len) - 1];
    }

    int numberWays(vector<vector<int>>& hats) {
        int len = hats.size();//һ����len����
        int maxhats = 0;
        //��һ��ñ�ӵ������
        for(auto& row : hats)
            for(auto& col : row)
                maxhats = max(maxhats,col);
        
        vector<vector<int> > tmp(maxhats + 1);
        //���˶�Ӧñ�ӱ��ñ�Ӷ�Ӧ��
        for(int i = 0; i < len; i++)
            for(auto& col : hats[i])
                tmp[col].push_back(i);
        
        //dp[i] ��ʾ��ǰ״̬Ϊi�����з�����
        vector<int> dp(1<<len);
        dp[0] = 1;

        for(int i = 1; i <= maxhats; i++)
            for(int j = (1<<len)-1; ~j; j--)//ѹ��Ϊһά��Ҫ�Ӻ���ǰ��������ȷ��ÿһ��ʹ�õ����ݶ�����һ�ε�����
            {
                for(auto& k : tmp[i])//������i��ñ�ӿ��Դ�����
                    if(j & (1<<k)) 
                        dp[j] = (dp[j - (1<<k)] + dp[j]) % mod;
            }
        
        return dp[(1<<len) - 1];
    }
};
