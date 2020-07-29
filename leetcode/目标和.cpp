����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S������������������?+?��?-�����������е�����һ���������㶼���Դ�?+?��?-��ѡ��һ�����������ǰ�档

���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�������

?

ʾ����

���룺nums: [1, 1, 1, 1, 1], S: 3
�����5
���ͣ�

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

һ����5�ַ���������Ŀ���Ϊ3��
?

��ʾ��

����ǿգ��ҳ��Ȳ��ᳬ�� 20 ��
��ʼ������ĺͲ��ᳬ�� 1000 ��
��֤���ص����ս���ܱ� 32 λ�������¡�

class Solution {
public:
    //dfs
    int findTargetSumWays1(vector<int>& nums, int s) {
        int n = nums.size();
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum < s) return 0;

        int ans = 0;
        dfs(nums,s,0,n,ans);

        return ans;
    }

    void dfs(vector<int>& nums,int cur,int idx,int n,int& ans)
    {
        if(idx == n)
        {
            if(cur == 0)    ans++;
            return;
        }

        dfs(nums,cur+nums[idx],idx+1,n,ans);
        dfs(nums,cur-nums[idx],idx+1,n,ans);
    }

    //dp
    //sum(+) - sum(-) = target
    //sum(+) = target + sum(-)
    //sum(+) + sum(+) = target + sum(-) + sum(+)
    //2 * sum(+) = target + sum(num)
    int findTargetSumWays(vector<int>& nums, int s)
    {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        //target + sum(num)����Ϊż��  
        if(sum < s || (sum + s) % 2 == 1)
            return 0;
        
        int n = (sum + s) / 2;
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        
        for(auto& num : nums)
            for(int i = n; i >= num; i--)
                dp[i] += dp[i - num];
        return dp[n];
    }
};
