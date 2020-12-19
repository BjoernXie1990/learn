class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b)->bool{
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        
        int n = intervals.size();
        int ans = 0;
        int i = 0;
        while(i < n) {
            int ri = intervals[i][1];
            int le = intervals[i][0];
            i++;
            while(i < n && (intervals[i][0] == le || intervals[i][1] <= ri)) {
                i++;
            }

            ans++;
        }

        return ans;
    }
};

����һ�������б�����ɾ���б��б��������������ǵ����䡣

ֻ�е�?c <= a?��?b <= d?ʱ�����ǲ���Ϊ����?[a,b) ������?[c,d) ���ǡ�

���������ɾ�����������㷵���б���ʣ���������Ŀ��

?

ʾ����

���룺intervals = [[1,4],[3,6],[2,8]]
�����2
���ͣ����� [3,6] ������ [2,8] ���ǣ���������ɾ���ˡ�
?

��ʾ��??????

1 <= intervals.length <= 1000
0 <= intervals[i][0] <?intervals[i][1] <= 10^5
�������е�?i != j��intervals[i] != intervals[j]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-covered-intervals
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
