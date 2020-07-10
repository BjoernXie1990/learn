��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣

?

ʾ�� 1��

���룺
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
�����
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
ʾ�� 2��

���룺
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
�����
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        vector<bool> row(n,false);
        vector<bool> col(m,false);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0)
                    row[i] = col[j] = true;
        
        for(int i = 0; i < n; i++)
            if(row[i] == true)
                for(int j = 0; j < m; j++)
                    matrix[i][j] = 0;

        for(int j = 0; j < m; j++)
            if(col[j] == true)
                for(int i = 0; i < n; i++)
                    matrix[i][j] = 0;
    }
};
