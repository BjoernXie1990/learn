class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int first = INT_MAX;
        int second = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= first) first = nums[i];
            else if(nums[i] <= second) second = nums[i];
            else  return true;
        }

        return false;
    }
};


����һ��δ��������飬�ж�����������Ƿ���ڳ���Ϊ 3 �ĵ��������С�

��ѧ���ʽ����:

�������������?i, j, k,??������?0 �� i < j < k �� n-1��
ʹ��?arr[i] < arr[j] < arr[k] ������ true ;?���򷵻� false ��
˵��: Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1) ��

ʾ�� 1:

����: [1,2,3,4,5]
���: true
ʾ�� 2:

����: [5,4,3,2,1]
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/increasing-triplet-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
