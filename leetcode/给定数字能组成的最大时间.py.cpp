����һ���� 4 λ������ɵ����飬���ؿ������õķ��� 24 Сʱ�Ƶ����ʱ�䡣

��С�� 24 Сʱ��ʱ����?00:00����������?23:59���� 00:00 ����ҹ����ʼ���𣬹���Խ�ã�ʱ��Խ��

�Գ���Ϊ 5 ���ַ������ش𰸡��������ȷ����Чʱ�䣬�򷵻ؿ��ַ�����

?

ʾ�� 1��

���룺[1,2,3,4]
�����"23:41"
ʾ�� 2��

���룺[5,5,5,5]
�����""
?

��ʾ��

A.length == 4
0 <= A[i] <= 9


class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        arr.sort(reverse=True)
        p = itertools.permutations(arr) #ȫ���е�����

        for h1,h2,m1,m2 in p:
            if h1 * 10 + h2 <= 23 and m1 * 10 + m2 <= 59:
                return str(h1) + str(h2) + ":" + str(m1) + str(m2)
        return ""
