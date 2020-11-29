class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());

        for(int i = A.size() - 1; i >= 2; i--) {
            int a = A[i];
            int b = A[i - 1];
            int c = A[i - 2];
            if(b + c > a) return a + b + c;
        }

        return 0;
    }
};


������һЩ�����������ȣ���ɵ����� A����������������������ɵġ������Ϊ��������ε�����ܳ���

��������γ��κ������Ϊ��������Σ�����?0��

?

ʾ�� 1��

���룺[2,1,2]
�����5
ʾ�� 2��

���룺[1,2,1]
�����0
ʾ�� 3��

���룺[3,2,3,4]
�����10
ʾ�� 4��

���룺[3,6,2,3]
�����8
?

��ʾ��

3 <= A.length <= 10000
1 <= A[i] <= 10^6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-perimeter-triangle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
