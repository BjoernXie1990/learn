#include <iostream>
using namespace std;

int main()
{
	int n,m;//ƻ�����������������ֿ��������ĸ߶�
	cin>>n>>m; 
	m += 30;//���������������ĸ߶� 
	
	int ans = n;
	for(int i = 0; i < n; i++)
	{
		int height;//ƻ���ĸ߶�
		cin>>height;
		//����߶�С�����߶ȣ����Կ���ժ����ժ������ƻ����-1 
		if(height <= m)
			ans--; 
	}
	
	cout<<ans<<endl; 
	return 0;
} 
