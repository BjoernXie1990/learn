class Solution {
public:
    int minElements(vector<int>& nums, int l, int g) {
        int n = nums.size();
        long long sum = 0;
        for(auto& e : nums)
            sum += e;
        
        long long len = abs(sum - g);
        long long res = len / (abs(l));
        
        return res + (res * abs(l) != len);
    }
};

����һ���������� nums ������������ limit �� goal ������ nums ��һ����Ҫ���ԣ�abs(nums[i]) <= limit ��

����ʹ����Ԫ���ܺ͵��� goal ����Ҫ����������ӵ� ����Ԫ������ �����Ԫ�� ��Ӧ�ı� ������ abs(nums[i]) <= limit ��һ���ԡ�

ע�⣬��� x >= 0 ����ô abs(x) ���� x �����򣬵��� -x ��

?

ʾ�� 1��

���룺nums = [1,-1,1], limit = 3, goal = -4
�����2
���ͣ����Խ� -2 �� -3 ��ӵ������У������Ԫ���ܺͱ�Ϊ 1 - 1 + 1 - 2 - 3 = -4 ��
ʾ�� 2��

���룺nums = [1,-10,9,1], limit = 100, goal = 0
�����1
?

��ʾ��

1 <= nums.length <= 105
1 <= limit <= 106
-limit <= nums[i] <= limit
-109 <= goal <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
