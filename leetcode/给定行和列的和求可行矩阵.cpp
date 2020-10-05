class Solution {
public:
    int n,m;
    vector<vector<int> > ans;
    
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        n = rowSum.size();
        m = colSum.size();
        ans = vector<vector<int> > (n, vector<int> (m,0));
        
        dfs(rowSum,colSum,0,0);
        
        return ans;
    }
    
    void dfs(vector<int>& r, vector<int>& c,int x,int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return ;
        
        if(r[x] <= c[y]) {
            ans[x][y] = r[x];
            c[y] -= r[x];
            //r[x] = INT_MAX;
            
             // ���� ��
            
             dfs(r,c,x+1,y);
        }
        else {
            ans[x][y] = c[y];
            r[x] -= c[y];
           // c[y] = INT_MAX;
            // ���� ��
            dfs(r,c,x,y+1);
        }
    }
};


���������Ǹ���������?rowSum ��?colSum?������?rowSum[i]?�Ƕ�ά�����е� i?��Ԫ�صĺͣ� colSum[j]?�ǵ� j?��Ԫ�صĺ͡�����֮�㲻֪���������ÿ��Ԫ�أ�������֪��ÿһ�к�ÿһ�еĺ͡�

���ҵ���СΪ?rowSum.length x colSum.length?������ �Ǹ�����?�����Ҹþ�������?rowSum ��?colSum?��Ҫ��

���㷵������һ��������ĿҪ��Ķ�ά������Ŀ��֤���� ����һ��?���о���

?

ʾ�� 1��

���룺rowSum = [3,8], colSum = [4,7]
�����[[3,0],
      [1,7]]
���ͣ�
�� 0 �У�3 + 0 = 0 == rowSum[0]
�� 1 �У�1 + 7 = 8 == rowSum[1]
�� 0 �У�3 + 1 = 4 == colSum[0]
�� 1 �У�0 + 7 = 7 == colSum[1]
�к��еĺͶ�������ĿҪ�������о���Ԫ�ض��ǷǸ��ġ�
��һ�����еľ���Ϊ��[[1,2],
                  [3,5]]
ʾ�� 2��

���룺rowSum = [5,7,10], colSum = [8,6,8]
�����[[0,5,0],
      [6,1,0],
      [2,0,8]]
ʾ�� 3��

���룺rowSum = [14,9], colSum = [6,9,8]
�����[[0,9,5],
      [6,0,3]]
ʾ�� 4��

���룺rowSum = [1,0], colSum = [1]
�����[[1],
      [0]]
ʾ�� 5��

���룺rowSum = [0], colSum = [0]
�����[[0]]
?

��ʾ��

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rows) == sum(columns)

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-valid-matrix-given-row-and-column-sums
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
