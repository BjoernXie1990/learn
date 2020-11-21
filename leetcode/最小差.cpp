class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long ans = INT_MAX;
        int le = 0, ri = 0;
        int n = a.size(), m = b.size();
        while(le < n && ri < m) {
            long num = abs(abs(a[le]) - abs(b[ri]));
            ans = min(num,ans);

            if(le == n - 1) ri++;
            else if(ri == m - 1) le++;
            else if(a[le] > b[ri]) ri++;
            else le++;
        }

        return ans;
    }
};

����������������a��b�����������С�����ֵ��һ����ֵ��ÿ��������ȡһ��ֵ���������ظö���ֵ�Ĳ�

ʾ����

���룺{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
����� 3������ֵ��(11, 8)
��ʾ��

1 <= a.length, b.length <= 100000
-2147483648 <= a[i], b[i] <= 2147483647
��ȷ���������[-2147483648, 2147483647]��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/smallest-difference-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
