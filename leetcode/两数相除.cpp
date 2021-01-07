class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend != INT_MIN) return -dividend;
            return INT_MAX;     // ��Ϊ int �����ݵ����ֵ
        }
        if(dividend == divisor) return 1;
        if(divisor == INT_MIN) return 0;
        int res = 0;
        // ������ķ���
        bool flag = (dividend > 0) ^ (divisor > 0);
        // �ų� INT_MIN תΪ INT_MAX �󣬽�����תΪ����
        divisor = abs(divisor);
        if(dividend == INT_MIN) {
            res++;
            dividend += divisor;
        }
        dividend = abs(dividend);   

        while(dividend >= divisor) {
            int tmp = divisor;
            int cnt = 1;

            // INT_MAX = 2147483647 ��ֹ����Խ��
            while(tmp < (INT_MAX >> 2) && (tmp << 1) <= dividend) {
                tmp <<= 1;
                cnt <<= 1;
            }

            res += cnt;
            dividend -= tmp;
        }

        return flag ? -res : res;
    }
};

��������������������?dividend?�ͳ���?divisor�������������Ҫ��ʹ�ó˷��������� mod �������

���ر�����?dividend?���Գ���?divisor?�õ����̡�

���������Ľ��Ӧ����ȥ��truncate����С�����֣����磺truncate(8.345) = 8 �Լ� truncate(-2.7335) = -2

?

ʾ��?1:

����: dividend = 10, divisor = 3
���: 3
����: 10/3 = truncate(3.33333..) = truncate(3) = 3
ʾ��?2:

����: dividend = 7, divisor = -3
���: -2
����: 7/-3 = truncate(-2.33333..) = -2
?

��ʾ��

�������ͳ�����Ϊ 32 λ�з���������
������Ϊ?0��
�������ǵĻ���ֻ�ܴ洢 32 λ�з�������������ֵ��Χ�� [?231,? 231?? 1]�������У�����������������򷵻� 231?? 1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/divide-two-integers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
