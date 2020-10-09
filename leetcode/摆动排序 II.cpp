class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin() + n / 2,nums.end());
        int mid = nums[n/2];        // ����λ�� 
        
        // +++ === ---
        int le = 0, ri = n - 1;
        int pos = 0;
        while(pos <= ri) {
            if(nums[pos] > mid) swap(nums[pos++],nums[le++]);
            else if(nums[pos] < mid) swap(nums[pos],nums[ri--]);
            else if(nums[pos] == mid) pos++;
        }

        // 0 - 1  1 - 3 2 - 5
        vector<int> copy = nums;
        for(int i = 0; i < n; i++) nums[(i * 2 + 1) % (n | 1)] = copy[i];
    }
};


����һ�����������?nums�������������г�?nums[0] < nums[1] > nums[2] < nums[3]...?��˳��

ʾ��?1:

����: nums = [1, 5, 1, 1, 6, 4]
���: һ�����ܵĴ��� [1, 4, 1, 5, 1, 6]
ʾ�� 2:

����: nums = [1, 3, 2, 2, 3, 1]
���: һ�����ܵĴ��� [2, 3, 1, 3, 1, 2]
˵��:
����Լ����������붼��õ���Ч�Ľ����

����:
������?O(n) ʱ�临�ӶȺ� / ��ԭ�� O(1) ����ռ���ʵ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/wiggle-sort-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� 
