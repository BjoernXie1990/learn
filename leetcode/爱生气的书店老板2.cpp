class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        vector<int> f1(n + 1,0), f2(n + 1,0);
        
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(grumpy[i - 1] == 0) sum += customers[i - 1];
            f1[i] = sum;
            f2[i] = f2[i - 1] + customers[i - 1];
        }

        int res = 0;
        for(int i = 0; i + X - 1 < n; i++) {
            int ri = i + X - 1;
            int cnt = f1[i] + f2[ri + 1] - f2[i] + f1[n] - f1[ri + 1];
            res = max(res,cnt);
        }

        return res;
    }
};


���죬����ϰ���һ�ҵ������Ӫҵ?customers.length?���ӡ�ÿ���Ӷ���һЩ�˿ͣ�customers[i]���������꣬������Щ�˿Ͷ�������һ���ӽ������뿪��

��ĳЩʱ������ϰ�������� �������ϰ��ڵ� i ������������ô grumpy[i] = 1������ grumpy[i] = 0�� ������ϰ�����ʱ����һ���ӵĹ˿;ͻ᲻���⣬������������������ġ�

����ϰ�֪��һ�����ܼ��ɣ��������Լ����������������Լ�����?X ���Ӳ���������ȴֻ��ʹ��һ�Ρ�

���㷵����һ��Ӫҵ����������ж��ٿͻ��ܹ��е������������
?

ʾ����

���룺customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
�����16
���ͣ�
����ϰ������ 3 ���ӱ����侲��
�е���������ͻ����� = 1 + 1 + 1 + 1 + 7 + 5 = 16.
?

��ʾ��

1 <= X <=?customers.length ==?grumpy.length <= 20000
0 <=?customers[i] <= 1000
0 <=?grumpy[i] <= 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/grumpy-bookstore-owner
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
