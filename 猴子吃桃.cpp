#include <iostream>
using namespace std;

//�ݹ� 
int fun(int n,int num)
{
	if(n == 1)
		return num;
	
	return fun(n-1,(num+1) * 2);
}

//����
int GetNumber(int n)
{
	int num = 1;
	for(int i = n; i > 1; i--)
	{
		num = (num + 1) * 2;
	}
	return num;
}



 
int main()
{
	int n;//����n��ֻʣ��һ������
	cin>>n;
	
	cout<<GetNumber(n)<<endl;
	
	return 0; 
} 
