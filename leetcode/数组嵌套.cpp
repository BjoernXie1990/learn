class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] != -1) continue;

            dp[i] = dfs(nums,dp,i);
            ans = max(ans,dp[i]);
        }

        return ans;
    }

    int dfs(vector<int>& nums, vector<int>& dp,int idx) {
        if(nums[idx] == -2) return 0;
        if(dp[nums[idx]] != -1) return dp[nums[idx]];
        
        int num = nums[idx];
        nums[idx] = -2;
        dp[num] = dfs(nums,dp,num) + 1;
        nums[idx] = num;
        return dp[num];
    }
};


������0��ʼ����ΪN������A������0��N - 1�������������ҵ����ļ���S���������С������ S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }���������µĹ���

����ѡ������Ϊi��Ԫ��A[i]ΪS�ĵ�һ��Ԫ�أ�S����һ��Ԫ��Ӧ����A[A[i]]��֮����A[A[A[i]]]... �Դ����ƣ��������ֱ��S�����ظ���Ԫ�ء�

?

ʾ��?1:

����: A = [5,4,0,3,1,6,2]
���: 4
����: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

����һ����� S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
?

��ʾ��

N��[1, 20,000]֮���������
A�в������ظ���Ԫ�ء�
A�е�Ԫ�ش�С��[0, N-1]֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/array-nesting
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
