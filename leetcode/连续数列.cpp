class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int le = -1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while(le < i && sum < nums[i]) sum -= nums[++le];
            ans = max(ans,sum);
        }

        return ans;
    }
};

����һ���������飬�ҳ��ܺ������������У��������ܺ͡�

ʾ����

���룺 [-2,1,-3,4,-1,2,1,-5,4]
����� 6
���ͣ� ���������� [4,-1,2,1] �ĺ����Ϊ 6��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/contiguous-sequence-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
