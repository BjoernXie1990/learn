class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unsigned long long f[target+1];
        memset(f,0x00,sizeof f);

        f[0] = 1;
        for(int i = 1; i <= target; i++)
            for(int num : nums)
                if(i >= num) f[i] += f[i - num];
        
        return f[target];
    }
};


����һ��������������Ҳ������ظ����ֵ����飬�ҳ���Ϊ����Ŀ������������ϵĸ�����

ʾ��:

nums = [1, 2, 3]
target = 4

���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

��ע�⣬˳��ͬ�����б�������ͬ����ϡ�

������Ϊ 7��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/combination-sum-iv
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
