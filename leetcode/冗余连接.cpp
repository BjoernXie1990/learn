�ڱ�������, ��ָ����һ����ͨ���޻�������ͼ��

����һ��ͼ����ͼ��һ������N���ڵ� (�ڵ�ֵ���ظ�1, 2, ..., N) ������һ�����ӵı߹��ɡ����ӵıߵ��������������1��N�м䣬�������ӵı߲����������Ѵ��ڵıߡ�

���ͼ��һ���Ա���ɵĶ�ά���顣ÿһ���ߵ�Ԫ����һ��[u, v]?������?u < v����ʾ���Ӷ���u?��v������ͼ�ıߡ�

����һ������ɾȥ�ıߣ�ʹ�ý��ͼ��һ������N���ڵ����������ж���𰸣��򷵻ض�ά�����������ֵıߡ��𰸱�?[u, v] Ӧ������ͬ�ĸ�ʽ?u < v��

ʾ�� 1��

����: [[1,2], [1,3], [2,3]]
���: [2,3]
����: ����������ͼΪ:
  1
 / \
2 - 3
ʾ�� 2��

����: [[1,2], [2,3], [3,4], [1,4], [1,5]]
���: [1,4]
����: ����������ͼΪ:
5 - 1 - 2
    |   |
    4 - 3
ע��:

����Ķ�ά�����С�� 3 �� 1000��
��ά�����е�������1��N֮�䣬����N����������Ĵ�С��


class Solution {
public:
    class Union {
    public:
        Union(int size = 1) {
            _arr.reserve(size+1);
            for(int i = 0; i <= size; i++)
                _arr[i] = i;
        }

        int find(int p) {
            if(_arr[p] != p) _arr[p] = find(_arr[p]);
            return _arr[p];
        }

        void merge(int le,int ri) {
            int fLe = find(le);
            int fRi = find(ri);
            if(le != ri)    _arr[fRi] = fLe;
        }
    private:
        vector<int> _arr;
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Union un(n);

        for(int i = 0; i < n; i++) {
            if(un.find(edges[i][0]) == un.find(edges[i][1])) return edges[i];
            un.merge(edges[i][0],edges[i][1]);
        }
        return {};
    }
};
