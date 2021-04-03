class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> f(n);
        for(int i = 0; i < n; i++)
            f[i] = i;
        
        int res = 0;
        vector<int> t(n);
        bool flag = true;
        do {
            res ++;
            flag = true;
            for(int i = 0; i < n; i++) {
                if(i & 1) {
                    t[i] = f[n / 2 + (i - 1) / 2];
                } else {
                    t[i] = f[i / 2];
                }
                
                if(t[i] != i)
                    flag = false;
            }
            
            f = t;
        }while(!flag);
        
        
        return res;
    }

};


����һ��ż�� n?????? ����֪����һ������Ϊ n ������ perm ������ perm[i] == i?���±� �� 0 ��ʼ ��������

һ�������У��㽫����һ�������� arr ������ÿ�� i ��

��� i % 2 == 0 ����ô arr[i] = perm[i / 2]
��� i % 2 == 1 ����ô arr[i] = perm[n / 2 + (i - 1) / 2]
Ȼ�� arr?? ��ֵ??�� perm ��

Ҫ��ʹ perm �ص����г�ʼֵ��������Ҫִ�ж��ٲ�������������С�� ���� ����������

?

ʾ�� 1��

���룺n = 2
�����1
���ͣ������perm = [0,1]
�� 1?��������perm = [0,1]
���ԣ�����ִ�� 1 ������
ʾ�� 2��

���룺n = 4
�����2
���ͣ������perm = [0,1,2,3]
�� 1?��������perm = [0,2,1,3]
�� 2?��������perm = [0,1,2,3]
���ԣ�����ִ�� 2 ������
ʾ�� 3��

���룺n = 6
�����4
?

��ʾ��

2 <= n <= 1000
n?????? ��һ��ż��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� ��ԭ���е����ٲ�������
