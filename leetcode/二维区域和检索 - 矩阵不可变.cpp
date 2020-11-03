class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        f = vector<vector<int> > (n+1,vector<int> (m+1,0));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                f[i+1][j+1] = matrix[i][j] + f[i][j+1] + f[i+1][j] - f[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return f[row2 + 1][col2 + 1] + f[row1][col1] - f[row1][col2 + 1] - f[row2 + 1][col1];
    }
private:
    vector<vector<int> > f;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 
 
 ����һ����ά���󣬼������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ�������Ͻ�Ϊ (row1,?col1) �����½�Ϊ (row2,?col2)��


��ͼ�Ӿ������Ͻ�?(row1, col1) = (2, 1)?�����½�(row2, col2) = (4, 3)�����Ӿ�����Ԫ�ص��ܺ�Ϊ 8��

ʾ��:

���� matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
˵��:

����Լ�����󲻿ɱ䡣
���ε���?sumRegion?������
����Լ���?row1 �� row2 ��?col1 �� col2��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/range-sum-query-2d-immutable
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
