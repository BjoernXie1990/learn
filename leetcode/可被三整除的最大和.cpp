class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1][3];
        memset(dp,0x00,sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = dp[0][2] = INT_MIN;

        for(int i = 1; i <= n; i++)
            if(nums[i - 1] % 3 == 0) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + nums[i-1]);
            } else if(nums[i - 1] % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i-1]);
            } else if(nums[i - 1] % 3 == 2) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i-1]);
            }
        
        return dp[n][0];
    }
};

����һ����������?nums�������ҳ��������ܱ���������Ԫ�����͡�

?

ʾ�� 1��

���룺nums = [3,6,5,1,8]
�����18
���ͣ�ѡ������ 3, 6, 1 �� 8�����ǵĺ��� 18���ɱ� 3 ���������ͣ���
ʾ�� 2��

���룺nums = [4]
�����0
���ͣ�4 ���ܱ� 3 �����������޷�ѡ�����֣����� 0��
ʾ�� 3��

���룺nums = [1,2,3,4,4]
�����12
���ͣ�ѡ������ 1, 3, 4 �Լ� 4�����ǵĺ��� 12���ɱ� 3 ���������ͣ���
?

��ʾ��

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/greatest-sum-divisible-by-three
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
