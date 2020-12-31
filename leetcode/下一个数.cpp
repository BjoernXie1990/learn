class Solution {
public:
    typedef long long LL;
    vector<int> findClosedNumbers(int num) {
        if(num == 1) return {2,-1};
        if(num == 2147483647) return {-1,-1};

        int MAX = nextMax(num);
        if(MAX < 0) MAX = -1;
        int MIN = ~nextMax(~num);
        return {MAX,MIN};
    }

    int nextMax(LL num) {
        LL x = num & -num;      // �ҵ����һ��1��λ��
        LL y = x + num;         // ������������1

        // num & ~y ���������1��ɵ���
        // /x  ��������0
        // >> 1 
        return y | ((num & ~y) / x) >> 1;
    }
};


��һ����������һ�����������ҳ���������Ʊ��ʽ��1�ĸ�����ͬ�Ҵ�С��ӽ�������������һ���Դ�һ����С����

ʾ��1:

 ���룺num = 2������0b10��
 �����[4, 1] ���ߣ�[0b100, 0b1]��
ʾ��2:

 ���룺num = 1
 �����[2, -1]
��ʾ:

num�ķ�Χ��[1, 2147483647]֮�䣻
����Ҳ���ǰһ�����ߺ�һ��������������������ô��� -1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/closed-number-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
