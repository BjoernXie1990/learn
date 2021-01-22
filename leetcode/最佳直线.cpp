class Solution {
public:
    typedef long long LL;
    vector<int> bestLine(vector<vector<int>>& points) {
        vector<int> res;
        int pre = -1;
        int n = points.size();
        for(int i = 0;  i < n - 1; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int cnt = 0;
                int x2 = points[j][0], y2 = points[j][1];

                for(int m = j + 1; m < n; m++) {
                    int x3 = points[m][0], y3 = points[m][1];
                    if((LL)(y2 - y1) * (x3 - x1) == (LL)(y3 - y1) * (x2 - x1)) cnt++;
                }

                if(cnt > pre) {
                    res = {i,j};
                    pre = cnt;
                }
            }
        }

        return res;
    }
};

����һ����άƽ�漰ƽ���ϵ� N �����б�Points�����е�i���������ΪPoints[i]=[Xi,Yi]�����ҳ�һ��ֱ�ߣ���ͨ���ĵ����Ŀ��ࡣ

�贩�������ֱ����������ȫ�����Ŵ�С����������б�ΪS������践��[S[0],S[1]]��Ϊ�𰸣����ж���ֱ�ߴ�������ͬ�����ĵ㣬��ѡ��S[0]ֵ��С��ֱ�߷��أ�S[0]��ͬ��ѡ��S[1]ֵ��С��ֱ�߷��ء�

ʾ����

���룺 [[0,0],[1,1],[1,0],[2,0]]
����� [0,2]
���ͣ� ����ֱ�ߴ�����3����ı��Ϊ[0,2,3]
��ʾ��

2 <= len(Points) <= 300
len(Points[i]) = 2

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/best-line-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
