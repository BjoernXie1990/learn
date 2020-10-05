class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int minN = A[0];
        int curMin = minN;
        int maxN = A[0];
        int curMax = maxN;
        int sum = A[0];

        for(int i = 1; i < A.size(); i++) {
            sum += A[i];
            // max
            curMax = (curMax > 0) ? curMax + A[i] : A[i];
            maxN = max(curMax,maxN);

            // min
            curMin = (curMin < 0) ? curMin + A[i] : A[i];
            minN = min(curMin,minN);
        }

        return (maxN < 0) ? maxN : max(maxN,sum - minN);
    }
};


����һ������������ A?��ʾ�Ļ������� C���� C?�ķǿ�������������ܺ͡�

�ڴ˴�������������ζ�������ĩ�˽����뿪ͷ�����ʻ�״������ʽ�ϣ���0 <= i < A.length?ʱ?C[i] = A[i]���ҵ�?i >= 0?ʱ?C[i+A.length] = C[i]��

���⣬���������ֻ�ܰ����̶������� A?�е�ÿ��Ԫ��һ�Ρ�����ʽ�ϣ�����������?C[i], C[i+1], ..., C[j]��������?i <= k1, k2 <= j?����?k1 % A.length?= k2 % A.length��

?

ʾ�� 1��

���룺[1,-2,3,-2]
�����3
���ͣ��������� [3] �õ����� 3
ʾ�� 2��

���룺[5,-3,5]
�����10
���ͣ��������� [5,5] �õ����� 5 + 5 = 10
ʾ�� 3��

���룺[3,-1,2,-1]
�����4
���ͣ��������� [2,-1,3] �õ����� 2 + (-1) + 3 = 4
ʾ�� 4��

���룺[3,-2,2,-3]
�����3
���ͣ��������� [3] �� [3,-2,2] �����Եõ����� 3
ʾ�� 5��

���룺[-2,-3,-1]
�����-1
���ͣ��������� [-1] �õ����� -1
?

��ʾ��

-30000 <= A[i] <= 30000
1 <= A.length <= 30000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-sum-circular-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
