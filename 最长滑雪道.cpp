#include <iostream>
using namespace std;

int dp[20][20] = {0};//��¼���±�λ�õ�ǰ���Ļ�ѩ���� 
int height[20][20] = {0}; //��¼��ǰλ�õĸ߶�
int r,c;//��  �� 
int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(int row,int col)
{
	int maxheight = 0;
	int path = 0;
	for(int i = 0; i < 4; i++)
	{
		int x = row + dic[i][0];
		int y = col + dic[i][1];
		
		//�ж��Ƿ�Խ��
		if(x < 0 || x >= r || y < 0 || y >= c)
		{
			continue;
		}
		
		//���x,y������ԭ���
		if(height[x][y] >= height[row][col])
			continue; 
		
		if(!dp[x][y])
			dp[x][y] = dfs(x,y);
		
		path = dp[x][y] + 1;
		if(path > maxheight)
			maxheight = path;
		
	}
	
	return maxheight;
}

int main()
{
	cin>>r>>c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin>>height[i][j];
	
	int maxheight = 0;
	
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			if(!dp[i][j])
				dp[i][j] = dfs(i,j);
			int path = dp[i][j] + 1;;
			if(path > maxheight)
				maxheight = path;
		}
		
	cout<<maxheight<<endl;
	return 0;
} 
