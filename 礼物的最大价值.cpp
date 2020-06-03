//��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����

//?

//ʾ�� 1:

//����: 
//[
//? [1,3,1],
//? [1,5,1],
//? [4,2,1]
//]
//���: 12
//����: ·�� 1��3��5��2��1 �����õ�����ֵ������


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > dp(row,vector<int> (col,0));
        dp[0][0] = grid[0][0];

        for(int i = 1; i < row; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        
        for(int j = 1; j < col; j++)
            dp[0][j] = grid[0][j] + dp[0][j-1];

        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j]; 
            }
        
        return dp[row-1][col-1];
    }
};
