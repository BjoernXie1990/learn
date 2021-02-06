class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1e9;
        int le = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(i - le + 1 > k) sum -= nums[le++];
            if(i - le + 1 == k) res = max((double)sum / k,res);
        }
        return res;
    }
};


���� n ���������ҳ�ƽ��������ҳ���Ϊ k �����������飬����������ƽ������

?

ʾ����

���룺[1,12,-5,-6,50,3], k = 4
�����12.75
���ͣ����ƽ���� (12-5-6+50)/4 = 51/4 = 12.75
?

��ʾ��

1 <= k <= n <= 30,000��
�������ݷ�Χ [-10,000��10,000]��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-average-subarray-i
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
