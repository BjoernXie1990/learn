#include <iostream>
using namespace std;

int main()
{
	//���Ʒ�
	int dis = 500;//��������·��
	int capacity = 500;//����վ������ 
	int num = 1;//����վ�ı�� 
	
	do
	{
		cout<<"�� "<<num<<" ������վ��������� "<<1000 - dis<<" km";
		cout<<",����վ���� "<<capacity<<" L"<<endl;
		num++;
		capacity = num * 500; //ÿһ������վ���;�����������������
		dis += 500 / (2 * num - 1);
		
	}while(dis < 1000); 
	
	//��ʼλ�õĴ洢����Ӧ�ü�ȥ����һ������վ�����ǣ����һ�ε������Ͷ����ĵ��� 
	cout<<"��ʼλ�õ����� "<<500 * (num - 1) + (1000 - dis) * (2 * num -1)<<" L"<<endl; 
	
	return 0;
} 
