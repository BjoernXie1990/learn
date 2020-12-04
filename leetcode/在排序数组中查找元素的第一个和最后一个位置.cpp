class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2,-1);

        int le = 0, ri = n - 1;
        while(le < ri) {
            int mid = (le + ri) / 2;
            if(nums[mid] >= target) ri = mid;
            else if(nums[mid] < target) le = mid + 1;
        }
        if(n == 0 || nums[le] != target) return ans;
        ans[0] = le;

        le = 0, ri = n - 1;
        while(le < ri) {
            int mid = (le + ri + 1) / 2;
            if(nums[mid] <= target) le = mid;
            else if(nums[mid] > target) ri = mid - 1;
        }
        ans[1] = le;
        return ans;
    }
};

����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������?[-1, -1]��

���ף�

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ?O(log n)?���㷨�����������
?

ʾ�� 1��

���룺nums = [5,7,7,8,8,10], target = 8
�����[3,4]
ʾ��?2��

���룺nums = [5,7,7,8,8,10], target = 6
�����[-1,-1]
ʾ�� 3��

���룺nums = [], target = 0
�����[-1,-1]
?

��ʾ��

0 <= nums.length <= 105
-109?<= nums[i]?<= 109
nums?��һ���ǵݼ�����
-109?<= target?<= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
