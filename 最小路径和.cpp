����һ�������Ǹ������� m?x?n?�������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

˵����ÿ��ֻ�����»��������ƶ�һ����

ʾ��:

����:
[
? [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 7
����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int num = INT_MAX;
                if(i - 1 >= 0)  num = min(grid[i-1][j],num);
                if(j - 1 >= 0)  num = min(grid[i][j-1],num);

                grid[i][j] += num==INT_MAX ? 0 : num;
            }
        return grid[n-1][m-1];
    }
};
