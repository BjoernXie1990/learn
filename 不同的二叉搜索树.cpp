����һ������ n������?1 ...?n?Ϊ�ڵ���ɵĶ����������ж����֣�

ʾ��:

����: 3
���: 5
����:
���� n = 3, һ���� 5 �ֲ�ͬ�ṹ�Ķ���������:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


class Solution {
public:
    unordered_map<int,int> map;
    int numTrees1(int n) {
        if(n == 1 || n == 0)   return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int le = 0;
            if(map.count(i-1))
                le = map[i-1];
            else
            {
                le = numTrees(i-1);
                map[i-1] = le;
            }

            int ri = 0;
            if(map.count(n-i))
                ri = map[n-i];
            else
            {
                ri = numTrees(n-i);
                map[n-i] = ri;
            }
            ans += le * ri;
        }
            
        return ans;
    }

    //��̬�滮
    int numTrees(int n)
    {
        if(n < 2) return n;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};
