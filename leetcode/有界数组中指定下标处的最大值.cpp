class Solution {
public:
    typedef long long LL;
    int maxValue(int n, int index, int maxSum) {
        int le = 1, ri = maxSum;
        while(le < ri) {
            int mid = le + ri + 1 >> 1;
            if(check(mid,n,index,maxSum)) le = mid;
            else ri = mid - 1;
        }
        
        return le;
    }
    
    bool check(LL num,int n, int index, LL maxSum) {
        LL le = index, ri = n - index - 1;
        LL cnt = num - 1;
        LL sum = num;
        
        if(le >= cnt) {
            sum += cnt * (num - 1) - (cnt * (cnt - 1) / 2);
            sum += le - cnt;
        } else {
            sum += le * (num - 1) - (le * (le - 1) / 2);
        }
        
        if(ri >= cnt) {
            sum += cnt * (num - 1) - (cnt * (cnt - 1) / 2);
            sum += ri - cnt;
        } else {
            sum += ri * (num - 1) - (ri * (ri - 1) / 2);
        }
        
        return sum <= maxSum;
    }
};


�������������� n��index �� maxSum ������Ҫ����һ��ͬʱ���������������������� nums���±� �� 0 ��ʼ ��������

nums.length == n
nums[i] �� ������ ������ 0 <= i < n
abs(nums[i] - nums[i+1]) <= 1 ������ 0 <= i < n-1
nums ������Ԫ��֮�Ͳ����� maxSum
nums[index] ��ֵ�� ���
������������������е� nums[index] ��

ע�⣺abs(x) ���� x ��ǰ���� x >= 0 ������abs(x) ���� -x ��

?

ʾ�� 1��

���룺n = 4, index = 2,  maxSum = 6
�����2
���ͣ����� [1,1,2,1] �� [1,2,2,1] ��������������������������ָ���±괦���и���ֵ����Ч���顣
ʾ�� 2��

���룺n = 6, index = 1,  maxSum = 10
�����3
?

��ʾ��

1 <= n <= maxSum <= 109
0 <= index < n

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
