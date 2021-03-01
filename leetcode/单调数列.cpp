class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool a = true, b = true;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1]) a = false;
            if(A[i] < A[i - 1]) b = false;
        }
        return a || b;
    }
};



��������ǵ��������򵥵��ݼ��ģ���ô���ǵ����ġ�

����������� i <= j��A[i] <= A[j]����ô���� A �ǵ��������ġ� ����������� i <= j��A[i]> = A[j]����ô���� A �ǵ����ݼ��ġ�

������������ A?�ǵ�������ʱ���� true�����򷵻� false��

?

ʾ�� 1��

���룺[1,2,2,3]
�����true
ʾ�� 2��

���룺[6,5,4,4]
�����true
ʾ�� 3��

���룺[1,3,2]
�����false
ʾ�� 4��

���룺[1,2,4,5]
�����true
ʾ��?5��

���룺[1,1,1]
�����true
?

��ʾ��

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/monotonic-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
