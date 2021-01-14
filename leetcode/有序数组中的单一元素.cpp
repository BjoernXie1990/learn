class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ri = nums.size() - 1, le = 0;
        while(le < ri) {
            int mid = (le + ri) / 2;
            int cnt = mid - le;

            if(nums[mid - 1] == nums[mid]) {
                if(cnt - 1 & 1)  ri = mid - 2;
                else le = mid + 1;
            } else if(nums[mid + 1] == nums[mid]) {
                if(cnt & 1) ri = mid - 1;
                else le = mid + 2;
            } else {
                return nums[mid];
            }
        }

        return nums[le];
    }
};


����һ��ֻ�����������������飬ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Σ��ҳ��������

ʾ�� 1:

����: [1,1,2,3,3,4,4,8,8]
���: 2
ʾ�� 2:

����: [3,3,7,7,10,11,11]
���: 10
ע��: ���ķ���Ӧ���� O(log n)ʱ�临�ӶȺ� O(1)�ռ临�Ӷ������С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-element-in-a-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
