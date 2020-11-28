class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            int p = 1 << i;
            for(auto& e : nums) if(e & p) cnt++;
            if(cnt % 3 != 0) ans |= p;
        }
        return ans;
    }
};

��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�

?

ʾ�� 1��

���룺nums = [3,4,3,3]
�����4
ʾ�� 2��

���룺nums = [9,1,7,9,7,9,7]
�����1
?

���ƣ�

1 <= nums.length <= 10000
1 <= nums[i] < 2^31

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
