��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�

?

����Ҫ��һ�����������鷵�ش𰸣����е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�

?

ʾ�� 1:

����: 1
���: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
ʾ��?2:

����: 2
���: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
?

���ƣ�

1 <= n <= 11��

class Solution {
public:
    vector<double> twoSum1(int n) {
        int dp[n+1][6*n+1];
        memset(dp,0x00,sizeof(dp));

        for(int i = 1; i <= 6; i++)
            dp[1][i] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= 6*n; j++)
                for(int k = 1; k <= 6; k++)
                    dp[i][j] += (j >= k) ? dp[i-1][j-k] : 0;
        
        int size = pow(6,n);
        vector<double> ans;
        for(int i = n; i <= 6*n; i++)
            ans.push_back((double)dp[n][i]/size);
        
        return ans;
    }


    vector<double> twoSum(int n) {
        int dp[6*n+1];
        memset(dp,0x00,sizeof(dp));

        for(int i = 1; i <= 6; i++)
            dp[i] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 6 * n; j > 0; j--){
                int tmp = 0;
                for(int k = 1; k <= 6; k++)
                    tmp += (j >= k) ? dp[j-k] : 0;
                dp[j] = tmp;
            }
                
        int size = pow(6,n);
        vector<double> ans;
        for(int i = n; i <= 6*n; i++)
            ans.push_back((double)dp[i]/size);
        
        return ans;
    }    
};
