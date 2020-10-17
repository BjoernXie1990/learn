class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int f1 = (a>>i) & 1;
            int f2 = (b>>i) & 1;
            int f3 = (c>>i) & 1;

            if(f3 == 1)
            {
                if(!f1 && !f2)   ans++;
            }
            else if(f3 == 0)
            {
                ans += f1 + f2;
            }
        }

        return ans;
    }
};


��������������?a��b �� c��

����Զ� a �� b?�Ķ����Ʊ�ʾ����λ��ת�����������ܹ�ʹ��λ������? ?a OR b == c??��������С��ת������

��λ��ת��������ָ��һ�����Ķ����Ʊ�ʾ�κε���λ�ϵ� 1 ��� 0 ���� 0 ��� 1 ��

?

ʾ�� 1��



���룺a = 2, b = 6, c = 5
�����3
���ͣ���ת�� a = 1 , b = 4 , c = 5 ʹ�� a OR b == c
ʾ�� 2��

���룺a = 4, b = 2, c = 7
�����1
ʾ�� 3��

���룺a = 1, b = 2, c = 3
�����0
?

��ʾ��

1 <= a <= 10^9
1 <= b?<= 10^9
1 <= c?<= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
