class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int le = 0, ri = nums.size() - 1;
        while( le < ri) {
            int mid = le + ri >> 1;
            if(nums[mid] == target) return true;
            if(nums[le] == nums[ri] && nums[le] != target) {
                le++;
                ri--;
            } else if(nums[mid] >= nums[le]) {
                if(nums[mid] > target && target >= nums[le]) ri = mid - 1;
                else le = mid + 1; 
            } else {
                if(nums[mid] < target && target <= nums[ri]) le = mid + 1;
                else ri = mid - 1;
            }
        }

        return nums[le] == target;
    }
};

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬����?[0,0,1,2,2,5,6]?���ܱ�Ϊ?[2,5,6,0,0,1,2]?)��

��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ���?true�����򷵻�?false��

ʾ��?1:

����: nums = [2,5,6,0,0,1,2], target = 0
���: true
ʾ��?2:

����: nums = [2,5,6,0,0,1,2], target = 3
���: false
����:

���� ������ת��������?��������Ŀ�������е�?nums? ���ܰ����ظ�Ԫ�ء�
���Ӱ�쵽�����ʱ�临�Ӷ��𣿻���������Ӱ�죬Ϊʲô��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
