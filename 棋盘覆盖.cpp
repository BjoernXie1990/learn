#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;

int board[100][100] = {0};//���� 
int count = 1;//���δ������˳�� 
int dis[4][2] = {{0,0},{0,1},{1,0},{1,1}};//�����ң��£����½�����λ�� 

void show(int size)
{
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
			printf("%3d ",board[i][j]);
		cout<<endl;
	}
}

void Cover(int tx,int ty,int x,int y,int size)
{
	//����ֻ��һ�����ӵ���� 
	if(size < 2)
		return ;
	
	size /= 2; 
	int num = count++;
	
	for(int i = 0; i < 4; i++)
	{
		//�ֳ��ĸ����飬row,col�ֱ�Ϊ�ĸ���������Ͻ�λ�� 
		int row = dis[i][0] * size + tx;
		int col = dis[i][1] * size + ty;
		//cout<<size<<' '<<row<<' '<<col<<endl;
		
		//���ȱ�ٵĸ��Ӳ��ڵ�ǰ��Χ���Ͱ��¼ӵĲ�ȱ���� 
		if(!(x >= row && x < (row + size) &&\
			 y >= col && y < (col + size)) )
			 {
			 	//r,c Ϊ�¼ӵĲ�ȱ��λ�� 
			 	int r = dis[3 - i][0] * (size-1) + row;
			 	int c = dis[3 - i][1] * (size-1) + col;
				board[r][c] = num; 
				Cover(row,col,r,c,size); 
			 	//cout<<"---"<<r<<' '<<c<<endl;
			 }
		else
			Cover(row,col,x,y,size);
	} 
}

int main()
{
	int k;
	cin>>k;//2^k  2^k������
	
	int size = pow(2,k);//���̵����� 
	//cout<<size; 
	
	int x,y;//��ȱ���λ��
	cin>>x>>y;
	board[x][y] = -1;
	
	Cover(1,1,x,y,size);
	
	show(size);
	return 0;
}
