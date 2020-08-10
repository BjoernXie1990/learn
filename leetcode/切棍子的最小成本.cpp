
��һ������Ϊ n ����λ��ľ�������ϴ� 0 �� n ���������λ�á����磬����Ϊ 6 �Ĺ��ӿ��Ա�����£�



����һ���������� cuts ������ cuts[i] ��ʾ����Ҫ�������п���λ�á�

����԰�˳������иҲ���Ը�����Ҫ�����и��˳��

ÿ���и�ĳɱ����ǵ�ǰҪ�и�Ĺ��ӵĳ��ȣ��й��ӵ��ܳɱ��������и�ɱ����ܺ͡��Թ��ӽ����и���һ��ľ���ֳ�������С��ľ����������ľ���ĳ��Ⱥ;����и�ǰľ���ĳ��ȣ�������ĵ�һ��ʾ���Ի�ø�ֱ�۵Ľ��͡�

�����й��ӵ� ��С�ܳɱ� ��

?

ʾ�� 1��



���룺n = 7, cuts = [1,3,4,5]
�����16
���ͣ��� [1, 3, 4, 5] ��˳���и�����������ʾ��

��һ���и��Ϊ 7 �Ĺ��ӣ��ɱ�Ϊ 7 ���ڶ����и��Ϊ 6 �Ĺ��ӣ�����һ���и�õ��ĵڶ������ӣ����������и�Ϊ���� 4 �Ĺ��ӣ�����и��Ϊ 3 �Ĺ��ӡ��ܳɱ�Ϊ 7 + 6 + 4 + 3 = 20 ��
�����и�˳����������Ϊ [3, 5, 1, 4] ���ܳɱ� = 16����ʾ��ͼ�� 7 + 4 + 3 + 2 = 16����
ʾ�� 2��

���룺n = 9, cuts = [5,6,1,4,2]
�����22
���ͣ������������˳���и���ܳɱ�Ϊ 25 ���ܳɱ� <= 25 ���и�˳��ܶ࣬���磬[4��6��5��2��1] ���ܳɱ� = 22�������п��ܷ����гɱ���С�ġ�
?

��ʾ��

2 <= n <= 10^6
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
cuts �����е����������� ������ͬ

class Solution {
public:
    int minCost1(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m = cuts.size() + 2;

        int sum[m];
        memset(sum,0x00,sizeof(sum));
        for(int i = 0; i < cuts.size(); i++)
            sum[i+1] = cuts[i];
        sum[m-1] = n;
        
        int dp[m][m];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i = 1; i < m; i++)
        {
            dp[i-1][i]=0;
            dp[i][i] = 0;
        }
            
        
        for(int i = m-2; i >= 0; i--)
            for(int j = i+1; j < m; j++)
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + sum[j] - sum[i]);
      
        return dp[0][m-1];
    }

    const int INF = 1e8+10;
    int minCost(int n, vector<int>& cuts)
    {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        vector<vector<int> > dp(cuts.size(),vector<int> (cuts.size(),INF));
        for(int i = 0; i < cuts.size()-1; i++)
            dp[i][i+1] = 0;

        return dfs(0,cuts.size()-1,dp,cuts);
    }

    int dfs(int le,int ri,vector<vector<int> >& dp,vector<int>& cuts)
    {
        if(dp[le][ri] < INF)    return dp[le][ri];

        for(int i = le + 1; i < ri; i++)
            dp[le][ri] = min(dp[le][ri],dfs(le,i,dp,cuts) + dfs(i,ri,dp,cuts) + cuts[ri] - cuts[le]);

        return dp[le][ri];
    }
};
