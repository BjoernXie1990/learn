#include <iostream>
#include <cstring>
using namespace std;

int arr[200] = {0};
char str[200] = {0};
 
int slove(int i,int len)
{
	int flag = 1;
	//1
	if(arr[str[i]])
		return 0;
	//����һ��Ԫ���ַ�
	while(!arr[str[i]] && i < len)
		i++;
	
	//����һ�������ַ�
	while(arr[str[i]] && i < len)
	{
		flag = 2;
		i++;
	}
	
	//����һ��Ԫ���ַ�
	while(!arr[str[i]] && i < len)
	{
		i++;
		flag = 3;
	}
		
	
	//����һ�������ַ�
	while(arr[str[i]] && i < len)
	{
		flag = 4;
		i++;
	}
	
	if(i == len && flag == 4)
		return 1;
	else
		return 0;
}

int main()
{
	cin>>str;
	arr['a'] = 1;
	arr['o'] = 1;
	arr['e'] = 1;
	arr['i'] = 1;
	arr['u'] = 1;
	if(slove(0,strlen(str)))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
		
	return 0;
}
