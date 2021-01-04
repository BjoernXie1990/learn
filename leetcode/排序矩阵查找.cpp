class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();

        int le = 0, ri = m - 1;
        while(le < n && ~ri) {
            int cur = matrix[le][ri];
            
            if(cur < target) le++;
            else if(cur > target) ri--;
            else if(cur == target) return true;
        }

        return false;
    }
};


����M��N����ÿһ�С�ÿһ�ж����������У����д�����ҳ�ĳԪ�ء�

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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sorted-matrix-search-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
