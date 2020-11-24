class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;

        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int cnt = 1;
        vector<int> t = points[0];

        for(auto& e : points){
            if(e[0] > t[1]) {
                cnt ++;
                t = e;
            }
            t[1] = min(t[1],e[1]);
        }

        return cnt;
    }
};


�ڶ�ά�ռ�����������ε����򡣶���ÿ�������ṩ��������ˮƽ�����ϣ�����ֱ���Ŀ�ʼ�ͽ������ꡣ��������ˮƽ�ģ����������겢����Ҫ�����ֻҪ֪����ʼ�ͽ����ĺ�������㹻�ˡ���ʼ��������С�ڽ������ꡣ

һ֧������������ x ��Ӳ�ͬ����ȫ��ֱ������������� x �����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ������ ?xstart?�� x �� xend���������ᱻ��������������Ĺ���������û�����ơ� ����һ�������֮�󣬿������޵�ǰ�����������ҵ�ʹ����������ȫ��������������Ĺ�������С������

����һ������ points ������ points [i] = [xstart,xend] �������������������������������С��������

?
ʾ�� 1��

���룺points = [[10,16],[2,8],[1,6],[7,12]]
�����2
���ͣ����ڸ�������x = 6 �����䱬 [2,8],[1,6] ���������Լ� x = 11 �䱬������������
ʾ�� 2��

���룺points = [[1,2],[3,4],[5,6],[7,8]]
�����4
ʾ�� 3��

���룺points = [[1,2],[2,3],[3,4],[4,5]]
�����2
ʾ�� 4��

���룺points = [[1,2]]
�����1
ʾ�� 5��

���룺points = [[2,3],[2,3]]
�����1
?

��ʾ��

0 <= points.length <= 104
points[i].length == 2
-231 <= xstart <?xend <= 231 - 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
