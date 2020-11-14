class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n],cnt[n];
        memset(dp,0x00,sizeof dp);
        memset(cnt,0x00,sizeof cnt);

        int maxLen = 1;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            cnt[i] = 1;
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if(dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            maxLen = max(dp[i],maxLen);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) if(dp[i] == maxLen) ans += cnt[i];
        return ans;
    }
};


����һ��δ������������飬�ҵ�����������еĸ�����

ʾ�� 1:

����: [1,3,5,4,7]
���: 2
����: ����������������У��ֱ��� [1, 3, 4, 7] ��[1, 3, 5, 7]��
ʾ�� 2:

����: [2,2,2,2,2]
���: 5
����: ����������еĳ�����1�����Ҵ���5�������еĳ���Ϊ1��������5��
ע��:?���������鳤�Ȳ����� 2000 ���ҽ��һ����32λ�з���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
