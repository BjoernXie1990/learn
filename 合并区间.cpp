//����һ������ļ��ϣ���ϲ������ص������䡣

//ʾ�� 1:

//����: [[1,3],[2,6],[8,10],[15,18]]
//���: [[1,6],[8,10],[15,18]]
//����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
//ʾ��?2:

//����: [[1,4],[4,5]]
//���: [[1,5]]
//����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        if(intervals.size() < 2)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);

        int start = -1;
        int end = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(start == -1)
            {
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }

            if(intervals[i][0] > end) //�����ǰ����Ҫ�ϲ���start end �����飬�Ѿ����
            {
                ans.push_back(GetVector(start,end));
                start = intervals[i][0];
                end = intervals[i][1];
            }     
            else if(intervals[i][1] > end) // �����ǰ��Ҫ�ϲ������ҽ���ʱ�����end���͸���end (1,4)(2,3)
                end = intervals[i][1];
        }
        if(start != -1)
            ans.push_back(GetVector(start,end));
        return ans;
    }

    vector<int> GetVector(int start,int end)
    {
        vector<int> ret(2);
        ret[0] = start;
        ret[1] = end;
        return ret;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};
