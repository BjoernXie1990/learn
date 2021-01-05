class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n - 1] > nums[0]) return nums[0];

        int le = 0, ri = n - 1;
        while (le < ri) {
            // �ų���ͬԪ�ص�Ӱ��
            while(le < ri && nums[le] == nums[ri]) le++;
            
            int mid = le + ri >> 1;
           
            // ����������ȣ�[3,1,3,3]
            // ���Ľ������������Ȳ��е�����
            if(nums[mid] > nums[n - 1])
                le = mid + 1;
            else
                ri = mid;
        }

        return nums[le];
    }
};

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬����?[0,1,2,4,5,6,7] ���ܱ�Ϊ?[4,5,6,7,0,1,2]?)��

���ҳ�������С��Ԫ�ء�

ע�������п��ܴ����ظ���Ԫ�ء�

ʾ�� 1��

����: [1,3,5]
���: 1
ʾ��?2��

����: [2,2,2,0,1]
���: 0
˵����

�������?Ѱ����ת���������е���Сֵ?��������Ŀ��
�����ظ���Ӱ���㷨��ʱ�临�Ӷ��𣿻����Ӱ�죬Ϊʲô��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
