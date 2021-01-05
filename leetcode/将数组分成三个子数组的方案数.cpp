class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        int res = 0;

        vector<int> f(n + 1);
        for(int i = 0; i < n; i++) f[i + 1] = f[i] + nums[i];

        // [1,x) [x,i) [i,n]
        // j Ϊ x ���½磬 k Ϊ x ���Ͻ�
        for(int i = 3, j = 2, k = 2; i <= n; i++) {
            // ȷ���м䲿����߽� ���½�
            while(f[n] - f[i - 1] < f[i - 1] - f[j - 1]) j++;
            // ȷ���м䲿����߽� ���Ͻ�
            while(k < i - 1 && f[i - 1] - f[k] >= f[k]) k++;

            if(j <= k && f[n] - f[i - 1] >= f[i - 1] - f[k - 1] && f[i - 1] - f[j - 1] >= f[j - 1])
                res = (res + k - j + 1) % mod;
        } 

        return res;
    }
};

���ǳ�һ���ָ���������ķ����� �õ�?���������㣺

���鱻�ֳ����� �ǿ�?���������飬�������ҷֱ�����Ϊ?left?��?mid?��?right?��
left?��Ԫ�غ�С�ڵ���?mid?��Ԫ�غͣ�mid?��Ԫ�غ�С�ڵ���?right?��Ԫ�غ͡�
����һ�� �Ǹ� ��������?nums?�����㷵��?�õ� �ָ� nums?������Ŀ�����ڴ𰸿��ܻ�ܴ����㽫����� 109?+ 7?ȡ��󷵻ء�

?

ʾ�� 1��

���룺nums = [1,1,1]
�����1
���ͣ�Ψһһ�ֺõķָ���ǽ� nums �ֳ� [1] [1] [1] ��
ʾ�� 2��

���룺nums = [1,2,2,2,5,0]
�����3
���ͣ�nums �ܹ��� 3 �ֺõķָ����
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
ʾ�� 3��

���룺nums = [3,2,1]
�����0
���ͣ�û�кõķָ����
?

��ʾ��

3 <= nums.length <= 105
0 <= nums[i] <= 104

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
