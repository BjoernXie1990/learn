class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1 >> 1) - (low >> 1);
    }
};

���������Ǹ�����?low ��?high?�����㷵��?low ��?high?֮�䣨�������ߣ���������Ŀ��

?

ʾ�� 1��

���룺low = 3, high = 7
�����3
���ͣ�3 �� 7 ֮����������Ϊ [3,5,7] ��
ʾ�� 2��

���룺low = 8, high = 10
�����1
���ͣ�8 �� 10 ֮����������Ϊ [9] ��
?

��ʾ��

0 <= low <= high?<= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-odd-numbers-in-an-interval-range
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
