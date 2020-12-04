class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> idx(3,0);
        vector<int> f(n,1);

        for(int i = 1; i < n; i++) {
            int a = f[idx[0]] * 2, b = f[idx[1]] * 3, c = f[idx[2]] * 5;
            int next = min(a,min(c,b));

            if(next == a)    idx[0]++;
            if(next == b)    idx[1]++;
            if(next == c)    idx[2]++;
            f[i] = next;
        }
        return f[n - 1];
    }
};

���ǰ�ֻ���������� 2��3 �� 5 ��������������Ugly Number�����󰴴�С�����˳��ĵ� n ��������

?

ʾ��:

����: n = 10
���: 12
����: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 ��ǰ 10 ��������
˵��:??

1?�ǳ�����
n?������1690��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/chou-shu-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
