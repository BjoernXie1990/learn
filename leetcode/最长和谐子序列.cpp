class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int le = 0;
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            while(le < i && nums[i] - nums[le] > 1)
                le++;
            if(nums[i] - nums[le] == 1)
                ans = max(ans,i - le + 1);
        }
        return ans;
    }
};

��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ��������1��

���ڣ�����һ���������飬����Ҫ�����п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�

ʾ�� 1:

����: [1,3,2,2,5,2,3,7]
���: 5
ԭ��: ��ĺ�г�����ǣ�[3,2,2,2,3].
˵��: ��������鳤����󲻳���20,000.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-harmonious-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
