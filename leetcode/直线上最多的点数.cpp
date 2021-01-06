class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long LL;
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2) return n;
        map<PII,int> mp;  // ͳ��ÿ������ֵĴ���
        for(auto& e : points) mp[{e[0],e[1]}] ++;

        vector<pair<PII,int> > vec; // ��¼ÿ������ֵĴ���
        for(auto& e : mp) vec.push_back(e);
        n = vec.size();
        if(n == 1) return vec[0].second;    // �ų�ֻ����һ��������

        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                // ��¼ i j ��б��
                LL x = vec[j].first.first - vec[i].first.first;
                LL y = vec[j].first.second - vec[i].first.second;
                int cur = vec[i].second + vec[j].second;    // ��ǰֱ���е������

                // ͳ�ƺ���ĵ�
                for(int k = j + 1; k < n; k++) {
                    LL tx = vec[k].first.first - vec[i].first.first;
                    LL ty = vec[k].first.second - vec[i].first.second;
                    if(tx * y == ty * x) cur += vec[k].second;
                }

                res = max(res,cur);
            }
        return res;
    }
};

����һ����άƽ�棬ƽ������?n?���㣬������ж��ٸ�����ͬһ��ֱ���ϡ�

ʾ�� 1:

����: [[1,1],[2,2],[3,3]]
���: 3
����:
^
|
| ? ? ? ?o
| ? ? o
| ?o ?
+------------->
0 ?1 ?2 ?3  4
ʾ��?2:

����: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
���: 4
����:
^
|
|  o
| ????o??      o
| ????   o
| ?o ?      o
+------------------->
0 ?1 ?2 ?3 ?4 ?5 ?6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-points-on-a-line
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
