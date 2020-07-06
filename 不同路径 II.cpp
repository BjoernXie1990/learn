һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������

���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����



�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��

˵����m?�� n ��ֵ�������� 100��

ʾ��?1:

����:
[
? [0,0,0],
? [0,1,0],
? [0,0,0]
]
���: 2
����:
3x3 ��������м���һ���ϰ��
�����Ͻǵ����½�һ���� 2 ����ͬ��·����
1. ���� -> ���� -> ���� -> ����
2. ���� -> ���� -> ���� -> ����


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if(r == 0 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int> > dp(r,vector<int> (c,0));
        dp[0][0] = 1;
        for(int j = 1; j < c; j++)
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = 1;
            else
                break;
        
        for(int i = 1; i < r; i++)
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
                break;
            
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[r-1][c-1];
    }
};
