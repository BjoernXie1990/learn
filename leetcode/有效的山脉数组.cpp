class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;

        int p = 0;
        while(p + 1 < n && A[p] < A[p + 1]) p++;
        if(p == n - 1 || p == 0) return false;

        while(p + 1 < n && A[p] > A[p + 1]) p++;

        return p == n - 1;
    }
};
����һ����������?A�����������Ч��ɽ������ͷ���?true�����򷵻� false��

�����ǻع�һ�£���� A ����������������ô����һ��ɽ�����飺

A.length >= 3
��?0 < i?< A.length - 1?�����£�����?i?ʹ�ã�
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
?



?

ʾ�� 1��

���룺[2,1]
�����false
ʾ�� 2��

���룺[3,5,5]
�����false
ʾ�� 3��

���룺[0,3,2,1]
�����true
?

��ʾ��

0 <= A.length <= 10000
0 <= A[i] <= 10000?
?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-mountain-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
