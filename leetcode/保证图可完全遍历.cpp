class Solution {
public:
    class chSet {
        public:
            chSet(int size) {
                _arr = vector<int> (size,0);
                for(int i = 1; i < size; i++)  _arr[i] = i;
            }
            int find(int p) {
                while(_arr[p] != p) {
                    _arr[p] = _arr[_arr[p]];
                    p = _arr[p];
                }
                return p;
            }
            bool merge(int le,int ri) {
                int l = find(le);
                int r = find(ri);
                if(l == r) return false;

                _arr[l] = r;
                return true;
            }
        private:
            vector<int> _arr;
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        chSet Alice(n+1);
        chSet Bob(n+1);
        sort(edges.begin(),edges.end(),[](const auto& a,const auto& b)->bool{
            return a[0] > b[0];
        });

        int common = 0;
        int a_cnt  = 0;
        int b_cnt  = 0;

        for(auto& e : edges) {
            bool ret = false;
            if(e[0] == 3) {
                ret = Alice.merge(e[1],e[2]);
                if(ret == true) {
                    common++;
                    a_cnt++;
                }
                ret = Bob.merge(e[1],e[2]);
                if(ret == true) b_cnt++;
            } else if (e[0] == 2) {
                ret = Bob.merge(e[1],e[2]);
                if(ret == true) b_cnt++;
            } else if (e[0] == 1) {
                ret = Alice.merge(e[1],e[2]);
                if(ret == true) a_cnt++;
            }
        }

        if(a_cnt != n-1 || b_cnt != n-1) return -1;
        int sum = edges.size();
        return sum - (n-1) * 2 + common;
    }
};


Alice �� Bob ����һ������ͼ�����а��� n ���ڵ�� 3? �����͵ıߣ�

���� 1��ֻ���� Alice ������
���� 2��ֻ���� Bob ������
���� 3��Alice �� Bob �����Ա�����
����һ������ edges ������ edges[i] = [typei, ui, vi]?��ʾ�ڵ� ui �� vi ֮���������Ϊ typei ��˫��ߡ������ڱ�֤ͼ���ܹ��� Alice�� Bob ��ȫ������ǰ���£��ҳ�����ɾ������������������κνڵ㿪ʼ��Alice �� Bob �����Ե������������ڵ㣬����Ϊͼ�ǿ�����ȫ�����ġ�

���ؿ���ɾ��������������� Alice �� Bob �޷���ȫ����ͼ���򷵻� -1 ��

?

ʾ�� 1��



���룺n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
�����2
���ͣ����ɾ�� [1,1,2] �� [1,1,3] �������ߣ�Alice �� Bob ��Ȼ������ȫ�������ͼ����ɾ���κ������ı߶��޷���֤ͼ������ȫ���������Կ���ɾ������������ 2 ��
ʾ�� 2��



���룺n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
�����0
���ͣ�ע�⣬ɾ���κ�һ���߶���ʹ Alice �� Bob �޷���ȫ�������ͼ��
ʾ�� 3��



���룺n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
�����-1
���ͣ��ڵ�ǰͼ�У�Alice �޷��������ڵ㵽��ڵ� 4 �����Ƶأ�Bob Ҳ���ܴﵽ�ڵ� 1 ����ˣ�ͼ�޷���ȫ������
?

��ʾ��

1 <= n <= 10^5
1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
edges[i].length == 3
1 <= edges[i][0] <= 3
1 <= edges[i][1] < edges[i][2] <= n
����Ԫ�� (typei, ui, vi) ������ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
