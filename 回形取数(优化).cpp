#include <iostream>
using namespace std;

int main()
{
	int arr[100][100] = {0};
	int b[2] = {0,1};//b[1]��ʾ������  b[0]��ʾ������
	
	int n;//���ξ�����к���
	cin>>n; 
	
	int num = 1;//��Ҫ��д���� 
	int k = n;//2 * k - 1 ��ʾ��Ȧ��Ҫ������ֵĳ��� 
	int t = 1;//��������ת�� 
	while(num <= n*n)
	{
		for(int i = 1; i <= 2 * k - 1; i++)
		{
			//�� i > n ʱ  �����������  
			//�� i <= n ʱ �����������
			b[i / (k + 1)] += t;
			arr[b[0]][b[1]] = num;
			num++;
		}
		
		t *= -1;//ǰ��Ȧ �� ���Ȧ����ı仯 
		k--;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	return 0;
} 
