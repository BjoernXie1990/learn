#include <iostream>
using namespace std;

int arr[8][8] = {0};//���ԭʼ����

int fun(int src[8][8],int n)
{
	if(n == 1)
		return src[1][1];
		
	if(n == 2)
		return src[1][1] * src[2][2] - src[1][2] * src[2][1];
	
	int ans = 0; 
	int tmp[8][8] = {0};
	//ѡȡ��һ�е�i�е�Ԫ��Ϊ���� 
	for(int i = 1; i <= n; i++)
	{
		for(int row = 1; row < n; row++)
		{
			//�ѳ��˵�1�е�i�е�Ԫ�أ�����Ԫ��ѹ����tmp��������Ͻǲ��� 
			for(int col = 1; col < i; col++)
				tmp[row][col] = src[row+1][col];
			
			for(int col = i; col < n; col++)
				tmp[row][col] = src[row+1][col+1];	
		}
		//�� 1 ���� -1  ��Ϊ������˹չ����ѡ�����������ǵ�һ�е�Ԫ��
		// ����˵���� (1+i)  ��ʾ��һ�е�i�� 
		ans += src[1][i] * fun(tmp,n-1) * (i%2==0?-1:1);
	} 
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>arr[i][j];
	
	cout<<fun(arr,n);
	
	return 0;
} 
