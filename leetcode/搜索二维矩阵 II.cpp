��дһ����Ч���㷨������?m?x?n?���� matrix �е�һ��Ŀ��ֵ target���þ�������������ԣ�

ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
ʾ��:

���о��� matrix ���£�

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target?=?5������?true��

����?target?=?20������?false��

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)  return false;   //[]
        int m = matrix[0].size();

        int x = 0;
        int y = m-1;
        while(x < n && y >= 0)
        {
            if(matrix[x][y] > target)
                y--;
            else if(matrix[x][y] < target)
                x++;
            else if(matrix[x][y] == target)
                return true;
        }

        return false;
    }
};
