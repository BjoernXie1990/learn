
�����޵���������?1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...���ҵ���?n?�����֡�

ע��:
n?����������32λ������Χ��?(?n < 231)��

ʾ�� 1:

����:
3

���:
3
ʾ�� 2:

����:
11

���:
0

˵��:
��11������������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... ����0������10��һ���֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/nth-digit
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long le = 1;
        long ri = 9;
        int len = 0;
        //le                    ri
        //1 - [1,9]             9
        //2 - [10,99]          90
        //3 - [100,999]       900
        //4 - [1000,9999]    9000
        while(len + le * ri < n) {
            len += le * ri;
            ri *= 10;
            le++;
        }

        long num = pow(10,le-1) + (n-len-1)/le;
        long index = (n-len-1) % le;
        return to_string(num)[index] - '0';
    }
};
