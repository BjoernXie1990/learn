����һ��?n x n?��������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е� k С��Ԫ�ء�
��ע�⣬���������ĵ� k СԪ�أ������ǵ� k ����ͬ��Ԫ�ء�

?

ʾ����

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

���� 13��
?

��ʾ��
����Լ��� k ��ֵ��Զ����Ч�ģ�1 �� k �� n2?��


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int le = matrix[0][0];
        int ri = matrix[n-1][n-1];

        while(le < ri)
        {
            int mid = le + (ri - le) / 2;
            int num = BinaryFind(matrix,mid,n);

            if(num < k)
                le = mid + 1;
            else if(num >= k)
                ri = mid;
        }

        return le;
    }

    int BinaryFind(vector<vector<int> >& matrix,int mid,int n)
    {
        //�����ұ�midС��Ԫ�ظ���
        int x = 0;
        int y = n - 1;
        int ans = 0;
        while(x < n && y >= 0)
        {
            if(matrix[x][y] <= mid)
            {
                ans += y + 1;
                x++; 
            }
            else
                y--;
        }
        return ans;
    }
};
