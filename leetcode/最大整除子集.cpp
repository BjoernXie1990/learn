����һ�������ظ�����������ɵļ��ϣ��ҳ��������������Ӽ����Ӽ�������һ�� (Si��Sj) ��Ҫ���㣺Si % Sj = 0 �� Sj % Si = 0��

����ж��Ŀ���Ӽ������������κ�һ�����ɡ�

?

ʾ�� 1:

����: [1,2,3]
���: [1,2] (��Ȼ, [1,3] Ҳ��ȷ)
ʾ�� 2:

����: [1,2,4,8]
���: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return nums;
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i],dp[j]+1);
        
        int idx = 0;
        for(int i = 1; i < n; i++)
            if(dp[i] > dp[idx]) idx = i;
        
        int len = dp[idx];
        vector<int> ans(len,0);
        for(int i = idx; i >= 0; i--)
            if(nums[idx] % nums[i] == 0 && dp[i] == len)
            {
                len--;
                ans[len] = nums[i];
                idx = i;
            }
        return ans;
    }
};
