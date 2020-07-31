������һ����ƽ���ϵĵ���ɵ��б� points����Ҫ�����ҳ� K ������ԭ�� (0, 0) ����ĵ㡣

�����ƽ��������֮��ľ�����ŷ����¾��롣��

����԰��κ�˳�򷵻ش𰸡����˵������˳��֮�⣬��ȷ����Ψһ�ġ�

?

ʾ�� 1��

���룺points = [[1,3],[-2,2]], K = 1
�����[[-2,2]]
���ͣ� 
(1, 3) ��ԭ��֮��ľ���Ϊ sqrt(10)��
(-2, 2) ��ԭ��֮��ľ���Ϊ sqrt(8)��
���� sqrt(8) < sqrt(10)��(-2, 2) ��ԭ�������
����ֻ��Ҫ����ԭ������� K = 1 ���㣬���Դ𰸾��� [[-2,2]]��
ʾ�� 2��

���룺points = [[3,3],[5,-1],[-2,4]], K = 2
�����[[3,3],[-2,4]]
���� [[-2,4],[3,3]] Ҳ�ᱻ���ܡ���
?

��ʾ��

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000


class Solution {
public:
    struct comper
    {
        bool operator()(const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.second < b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();  
        using key = pair<int,int>;
        priority_queue<key,vector<key>,comper> s_heap;

        for(int i = 0; i < n; i++)
        {
            int path = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            s_heap.push({i,path});

            if(s_heap.size() > k)   s_heap.pop();
        }

        vector<vector<int> > ans(k,vector<int> (2,0));
        for(int i = 0; i < k; i++)
        {
            auto t = s_heap.top();
            s_heap.pop();
            int p = t.first;

            ans[i][0] = points[p][0];
            ans[i][1] = points[p][1];
        }

        return ans;
    }
};
