// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7


// a	1	2	3	4	5	6	7
// b								
// 1	2	3	4	5	6	7	8
// 2	3	4	5	6	7	8	9
// 3	4	5	6	7	8	9	0
// 4	5	6	7	8	9	0	1
// 5	6	7	8	9	0	1	2
// 6	7	8	9	0	1	2	3
// 7	8	9	0	1	2	3	4
// ȥ�����Ͻǵ�  
// 6	7	8
// 7	8	9
// 8	9	0      ��

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();

        while(a >= 5 && b <= 3) {
            a = rand7();
            b = rand7();
        }

        int ans = (a+b) % 10;
        return  ans == 0 ? 10 : ans;
    }
};
���з���?rand7?������ 1 �� 7 ��Χ�ڵľ��������������дһ������?rand10?���� 1 �� 10 ��Χ�ڵľ������������

��Ҫʹ��ϵͳ��?Math.random()?������

?

ʾ�� 1:

����: 1
���: [7]
ʾ�� 2:

����: 2
���: [8,4]
ʾ�� 3:

����: 3
���: [8,1,10]
?

��ʾ:

rand7?�Ѷ��塣
�������:?n?��ʾ?rand10?�ĵ��ô�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-rand10-using-rand7
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
