class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int le = 0;
        int ri = nums.size() - 1;
        int ans = 0;
        while(le < ri) {
            int n = nums[le] + nums[ri];
            if(n == k) {
                ans++;
                le++;
                ri--;
            } else if(n > k){
                ri--;
            } else if(n < k) {
                le++;
            }
        }

        return ans;
    }
};


����һ���������� nums ��һ������ k ��

ÿһ�������У�����Ҫ��������ѡ����Ϊ k ���������������������Ƴ����顣

��������Զ�����ִ�е�����������

?

ʾ�� 1��

���룺nums = [1,2,3,4], k = 5
�����2
���ͣ���ʼʱ nums = [1,2,3,4]��
- �Ƴ� 1 �� 4 ��֮�� nums = [2,3]
- �Ƴ� 2 �� 3 ��֮�� nums = []
�����к�Ϊ 5 �����ԣ�������ִ�� 2 �β�����
ʾ�� 2��

���룺nums = [3,1,3,4,3], k = 6
�����1
���ͣ���ʼʱ nums = [3,1,3,4,3]��
- �Ƴ�ǰ���� 3 ��֮��nums = [1,4,3]
�����к�Ϊ 6 �����ԣ�������ִ�� 1 �β�����
?

��ʾ��

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-number-of-k-sum-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
