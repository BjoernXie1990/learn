class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);

        for(auto& eoch : bookings) {
            ans[eoch[0] - 1] += eoch[2];
            if(eoch[1] < n) ans[eoch[1]] -= eoch[2];
        }

        for(int i = 1; i < n; i++)  ans[i] += ans[i-1];
        return ans;
    }
};

������?n?�����࣬���Ƿֱ�� 1 �� n ���б�š�

���������һ�ݺ���Ԥ�������е�?i?��Ԥ����¼?bookings[i] = [i, j, k]?��ζ�������ڴ�?i?��?j?��ÿ��������Ԥ���� k ����λ��

���㷵��һ������Ϊ n ������?answer����������˳�򷵻�ÿ��������Ԥ������λ����

?

ʾ����

���룺bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
�����[10,55,45,25,25]
?

��ʾ��

1 <= bookings.length <= 20000
1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
1 <= bookings[i][2] <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/corporate-flight-bookings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
