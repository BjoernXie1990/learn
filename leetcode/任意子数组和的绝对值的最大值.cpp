class Solution {
public:
    int maxAbsoluteSum(vector<int>& num) {
        int n = num.size();
        vector<int> f(n+1,0);
        for(int i = 0; i < n; i++) f[i + 1] = f[i] + num[i];

        int res = 0;
        int minN = 0, maxN = 0;
        for(int i = 2; i <= n; i++) {
            res = max(res,abs(f[i] - minN));
            res = max(res,abs(f[i] - maxN));
            minN = min(minN,f[i]);
            maxN = max(maxN,f[i]);
            cout << res << " " << minN << " " << maxN << endl;
        }
        return res;
    }
};


����һ����������?nums?��һ��������?[numsl, numsl+1, ..., numsr-1, numsr]?�� �͵ľ���ֵ?Ϊ?abs(numsl + numsl+1 + ... + numsr-1 + numsr)?��

�����ҳ� nums?�� �͵ľ���ֵ �������������飨����Ϊ�գ��������ظ� ���ֵ?��

abs(x)?�������£�

���?x?�Ǹ���������ô?abs(x) = -x?��
���?x?�ǷǸ���������ô?abs(x) = x?��
?

ʾ�� 1��

���룺nums = [1,-3,2,3,-4]
�����5
���ͣ������� [2,3] �͵ľ���ֵ���Ϊ abs(2+3) = abs(5) = 5 ��
ʾ�� 2��

���룺nums = [2,-5,1,-4,3,-2]
�����8
���ͣ������� [-5,1,-4] �͵ľ���ֵ���Ϊ abs(-5+1-4) = abs(-8) = 8 ��
?

��ʾ��

1 <= nums.length <= 105
-104 <= nums[i] <= 104

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
