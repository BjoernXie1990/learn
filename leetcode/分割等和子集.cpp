class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxN = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxN = max(nums[i],maxN);
        }

        int ans = sum / 2;
        if((sum & 1) == 1 || maxN > ans) return false;
        
        
        vector<bool> dp(ans+1,false);
        // ��ʼ��
        dp[0] = true;
        for(int i = 0; i < n; i++) 
            for(int j = ans; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
                
        return dp[ans];
    }
};

����һ��ֻ�����������ķǿ����顣�Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�

ע��:

ÿ�������е�Ԫ�ز��ᳬ�� 100
����Ĵ�С���ᳬ�� 200
ʾ�� 1:

����: [1, 5, 11, 5]

���: true

����: ������Էָ�� [1, 5, 5] �� [11].
?

ʾ��?2:

����: [1, 2, 3, 5]

���: false

����: ���鲻�ָܷ������Ԫ�غ���ȵ��Ӽ�.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-equal-subset-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
