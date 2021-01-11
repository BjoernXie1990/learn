class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int le = 0, ri = n -1;
        while(le < ri) {
            int mid = le + ri >> 1;
            if(nums[mid] >= target) ri = mid;
            else le = mid + 1;
        }

        if(!n || nums[le] != target) return 0;
        int a = le;
        le = 0, ri = n - 1;
        while(le < ri) {
            int mid = le + ri + 1 >> 1;
            if(nums[mid] <= target) le = mid;
            else ri = mid - 1;
        }
        return le - a + 1;
    }
};


ͳ��һ�����������������г��ֵĴ�����

?

ʾ�� 1:

����: nums = [5,7,7,8,8,10], target = 8
���: 2
ʾ��?2:

����: nums = [5,7,7,8,8,10], target = 6
���: 0
?

���ƣ�

0 <= ���鳤�� <= 50000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
