�ڱ������У��и���ָ������������������ͼ������ֻ��һ�����ڵ㣬���������ڵ㶼�Ǹø��ڵ�ĺ�̡�ÿһ���ڵ�ֻ��һ�����ڵ㣬���˸��ڵ�û�и��ڵ㡣

����һ������ͼ����ͼ��һ������N���ڵ� (�ڵ�ֵ���ظ�1, 2, ..., N) ������һ�����ӵı߹��ɡ����ӵıߵ��������������1��N�м䣬�������ӵı߲����������Ѵ��ڵıߡ�

���ͼ��һ���Ա���ɵĶ�ά���顣 ÿһ���� ��Ԫ����һ�� [u, v]�����Ա�ʾ����ͼ�����Ӷ��� u �Ͷ��� v �ıߣ����� u �� v ��һ�����ڵ㡣

����һ����ɾ���ıߣ�ʹ��ʣ�µ�ͼ����N���ڵ���и��������ж���𰸣������������ڸ�����ά����Ĵ𰸡�

ʾ��?1:

����: [[1,2], [1,3], [2,3]]
���: [2,3]
����: ����������ͼ����:
  1
 / \
v   v
2-->3
ʾ�� 2:

����: [[1,2], [2,3], [3,4], [4,1], [1,5]]
���: [4,1]
����: ����������ͼ����:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
ע��:

��ά�����С����3��1000��Χ�ڡ�
��ά�����е�ÿ��������1��N֮�䣬���� N �Ƕ�ά����Ĵ�С��
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
            while(p != _arr[p]) {
                _arr[p] = _arr[_arr[p]];
                p = _arr[p];
            }
            return p;
        }

        bool merge(int le,int ri) {
            int fLe = find(le);
            int fRi = find(ri);
            
            if(fLe == fRi)  return false;
            _arr[fLe] = fRi;
            return true;
        }
    private:
        vector<int> _arr;
    };

    bool check(vector<vector<int> >& edges,int n,int del) {
        Union un(n);
        for(int i = 0; i < n; i++) {
            if(i == del) continue;

            if(un.merge(edges[i][0],edges[i][1]) == false)  return false;
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> sum(n+1,0);
        for(auto& eoch : edges) sum[eoch[1]]++;

        for(int i = n - 1; i >= 0; i--) {
            if(sum[edges[i][1]] != 2) continue;

            // ���Ϊ2
            if(check(edges,n,i) == true) return edges[i];
        }

        for(int i = n - 1; i >= 0; i--) {
            if(sum[edges[i][1]] != 1) continue;
            
            //���Ϊ1
            if (check(edges,n,i) == true) return edges[i];
        }

        return {};
    }
};
