class Solution {
public:
    
    typedef long long LL;
    
    vector<int> countPoints(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), m = b.size();
        
        vector<int> res(m,0);
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            int tx = b[i][0], ty = b[i][1], tr = b[i][2];
                
            for(int j = 0; j < n; j ++) {
                int x = a[j][0], y = a[j][1];
                
                int ta = abs(x - tx),tb = abs(y - ty);
                
                LL len = ta * ta + tb * tb;
                
                if(len <= tr * tr)
                    cnt ++;
            }
            
            res[i] = cnt;
        }
        
        return res;
    }
};

����һ������?points?������?points[i] = [xi, yi]?����ʾ��?i?�����ڶ�άƽ���ϵ����ꡣ�������ܻ��� ��ͬ?�����ꡣ

ͬʱ����һ������?queries?������?queries[j] = [xj, yj, rj]?����ʾһ��Բ����?(xj, yj)?�Ұ뾶Ϊ?rj?��Բ��

����ÿһ����ѯ?queries[j]?�������ڵ� j?��Բ ��?�����Ŀ�����һ������Բ�� �߽���?������ͬ����Ϊ����Բ?��?��

���㷵��һ������?answer?������?answer[j]�ǵ�?j?����ѯ�Ĵ𰸡�

?

ʾ�� 1��


���룺points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
�����[3,2,2]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��
ʾ�� 2��


���룺points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
�����[2,3,2,4]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��queries[3] ����ɫ��Բ��
?

��ʾ��

1 <= points.length <= 500
points[i].length == 2
0 <= x??????i, y??????i <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
���е����궼��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/queries-on-number-of-points-inside-a-circle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
