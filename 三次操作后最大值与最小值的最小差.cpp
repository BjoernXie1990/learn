����һ������?nums?��ÿ�β��������ѡ��?nums?�е�����һ�����ֲ������ĳ�����ֵ��

���㷵�����β����� nums?�����ֵ����Сֵ�Ĳ����Сֵ��

?

ʾ�� 1��

���룺nums = [5,3,2,4]
�����0
���ͣ������� [5,3,2,4] ��� [2,2,2,2].
���ֵ����Сֵ�Ĳ�Ϊ 2-2 = 0 ��
ʾ�� 2��

���룺nums = [1,5,0,10,14]
�����1
���ͣ������� [1,5,0,10,14] ��� [1,1,0,1,1] ��
���ֵ����Сֵ�Ĳ�Ϊ 1-0 = 1 ��
ʾ�� 3��

���룺nums = [6,6,0,1,1,4,6]
�����2
ʾ�� 4��

���룺nums = [1,5,6,14,15]
�����1
?

��ʾ��

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9


class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int len = nums.size();
        if(len <= 4)    return 0;
        
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++)
            ans = min(ans,nums[len-(4-i)] - nums[i]);
        return ans;
    }
};
