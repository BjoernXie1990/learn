#include <iostream>
#include <cstring>
using namespace std;

char target[700][700] = {'\0'};
char show[700][700] = {'\0'};
int n,m,l,r;//���ӵĴ�С   �Լ��ӵ��Ĵ�С  

void ruin(int row,int col)
{
	//�Ȼ�������λ�� 
	show[row][col] = '1';
	//cout<<row<<"  "<<col<<endl;
	for(int i = 0; i < (2*l+1); i++)
	{
		int x = row - l + i;//cout<<"x = "<<x<<endl;
		//�ж�x�Ƿ񳬷�Χ
		if(x < 0 || x >= n)
			continue;
		
		for(int j = 0; j < (2*r+1); j++)
		{
			int y = col - r	+ j;
			//�ж�y�Ƿ񳬷�Χ
			if( y < 0 || y >= m)
				continue;
			
			show[x][y] = '1';
			//cout<<x<<' '<<y<<endl;
		}
		
	}
		
}

void slove()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(target[i][j] == '1')
				ruin(i,j);
			else if(!show[i][j])
				show[i][j] = '0';
		}
	}
}

int main()
{
	
	cin>>n>>m>>l>>r;
	
	for(int i = 0; i < n; i++)
		cin>>target[i];
	 
	slove(); 
	
	//��ӡ���� 
	for(int i = 0; i < n; i++)
		cout<<show[i]<<endl;

		
	
	return 0;
}
