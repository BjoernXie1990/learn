class Solution {
public:
    int getSum(int a, int b) {
        // a ^ b  
        // a & b 
        while(b != 0) {
            int XOR = a ^ b;
            int AND = a & b;
            a = XOR;
            b = (unsigned int)AND<<1;
        }

        return a;
    }
};


��ʹ�������?+ ��?-????????������������????????a?��b????????֮�͡�

ʾ�� 1:

����: a = 1, b = 2
���: 3
ʾ�� 2:

����: a = -2, b = 3
���: 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-two-integers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
