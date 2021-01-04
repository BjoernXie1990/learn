class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int que[n];
        int hh = 0, tt = -1;

        vector<int> ans;
        ans.reserve(n);

        for(int i = 0; i < n; i++) {
            if(hh <= tt && i - k + 1 > que[hh]) hh++;

            while(hh <= tt && nums[i] > nums[que[tt]]) tt--;

            que[++tt] = i;

            if(i >= k - 1) ans.push_back(nums[que[hh]]);
        }

        return ans;
    }
};

����һ���������� nums����һ����СΪ?k?�Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k?�����֡���������ÿ��ֻ�����ƶ�һλ��

���ػ��������е����ֵ��

?

ʾ�� 1��

���룺nums = [1,3,-1,-3,5,3,6,7], k = 3
�����[3,3,5,5,6,7]
���ͣ�
�������ڵ�λ��                ���ֵ
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
ʾ�� 2��

���룺nums = [1], k = 1
�����[1]
ʾ�� 3��

���룺nums = [1,-1], k = 1
�����[1,-1]
ʾ�� 4��

���룺nums = [9,11], k = 2
�����[11]
ʾ�� 5��

���룺nums = [4,-2], k = 2
�����[4]
?

��ʾ��

1 <= nums.length <= 105
-104?<= nums[i] <= 104
1 <= k <= nums.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sliding-window-maximum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
