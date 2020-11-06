class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            return a[0] < b[0];
        });

        
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // �ϲ�
        int le = i;
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        while(i < n ) ans.push_back(intervals[i++]);
        return ans;
    }
};


����һ�����ص��� ������������ʼ�˵�����������б�

���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��

?

ʾ��?1��

���룺intervals = [[1,3],[6,9]], newInterval = [2,5]
�����[[1,5],[6,9]]
ʾ��?2��

���룺intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
�����[[1,2],[3,10],[12,16]]
���ͣ�������Ϊ�µ����� [4,8] �� [3,5],[6,7],[8,10]?�ص���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/insert-interval
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
