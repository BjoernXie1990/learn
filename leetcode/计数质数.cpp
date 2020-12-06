class Solution {
public:
    const int N = 5 * 1e6 + 10;
    int countPrimes(int n) {
        int f[N];
        memset(f,0x00,sizeof f);
        int cnt = 0;

        for(int i = 2; i < n; i++) {
            if(f[i]) continue;
            for(int j = 2 * i; j < n; j += i)   f[j] = 1; 
            cnt++;
        }
        return cnt;
    }
};

ͳ������С�ڷǸ�����?n?��������������

?

ʾ�� 1��

���룺n = 10
�����4
���ͣ�С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��
ʾ�� 2��

���룺n = 0
�����0
ʾ�� 3��

���룺n = 1
�����0
?

��ʾ��

0 <= n <= 5 * 106

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-primes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
