//�����и�����������һ����������Ͻǣ����� r �� c �С�������ֻ�����»������ƶ����������ߵ�һЩ����ֹ���������ϰ�������һ���㷨��Ѱ�һ����˴����Ͻ��ƶ������½ǵ�·����



//�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��

//����һ�����е�·����·���ɾ�����������кź��к���ɡ����Ͻ�Ϊ 0 �� 0 �С�

//ʾ��?1:

//����:
//[
//? [0,0,0],
//? [0,1,0],
//? [0,0,0]
//]
//���: [[0,0],[0,1],[0,2],[1,2],[2,2]]
//����: 
//�����б�ֵ�λ�ü�Ϊ�����ʾ��·������
//0��0�У����Ͻǣ� -> 0��1�� -> 0��2�� -> 1��2�� -> 2��2�У����½ǣ�


class Solution {
public:
	//��̬�滮 
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ans;

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(!row || !col) return ans;
        //�����յ㲻�����ϰ�
        if(obstacleGrid[0][0] || obstacleGrid[row-1][col-1]) return ans;

        int dp[row + 1][col + 1];
        dp[0][0] = 1;
        //��ʼ����
        for(int i = 1; i < col; i++)
            if(obstacleGrid[0][i]) dp[0][i] = 0;//�����ǰλ�����ϰ���0��ʾ��ͨ
            else dp[0][i] = dp[0][i-1];//�����ϰ��Ļ���Ҫ˳����1��
        //��ʼ����һ��
        for(int i = 1; i < row; i++)
            if(obstacleGrid[i][0]) dp[i][0] = 0; //�����ǰλ�����ϰ���0��ʾ��ͨ
            else dp[i][0] = dp[i-1][0];//�����ϰ��Ļ���Ҫ˳����1��
        
        //��̬�滮
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if(obstacleGrid[i][j]) dp[i][j] = 0;//��ǰλ�����ϰ�
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        if(dp[row-1][col-1] == 0) return ans;//�޷��������һ��λ��

        //�Ӻ���ǰ����·��
        int r = row - 1;
        int c = col - 1;
        
        while(r!=0 || c!=0){
            ans.push_back({r,c});
            int left = 0;
            if(c > 0) left = dp[r][c-1];//�ҵ���ǰλ����ߵ�״̬
            int up = 0;
            if(r > 0) up = dp[r-1][c];//�ҵ���ǰλ���ұߵ�״̬
            //left,up   1,0  0,1 1,1
            if(left >= up) c--;
            else r--;
        }
        ans.push_back({0,0});
        reverse(ans.begin(),ans.end());
        return ans;
    }


    //dfs  ��ʱ������������
    int row, col;
    int flag = false;
    int dir[2][2] = {0,1,1,0};
    vector<vector<int>> ans;
    vector<vector<int>> pathWithObstacles1(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        vector<vector<int>> visit(row, vector<int> (col,0));
        dfs(obstacleGrid,visit,0,0,1);
        return ans;
    }

    void dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& visit,int x, int y, int index){
         if(obstacleGrid[x][y])
            return;
        if(x == row-1 && y == col-1)
        {
            ans.push_back({x,y});
            flag = true;
            return ;
        }

        for(int i = 0; i < 2; i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];

            if(tx >= row || ty >= col)
                continue;
            if(visit[tx][ty] || obstacleGrid[tx][ty])
                continue;
            
            ans.push_back({x,y});
            dfs(obstacleGrid,visit,tx,ty,index+1);
            if(flag) return;
            ans.pop_back();
        }
    }
};
