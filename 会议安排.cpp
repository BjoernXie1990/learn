#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define MAX 100010

//����ʱ��Ľṹ�� 
struct node
{
	int start;
	int end;
	int id;//������� 
}t[MAX];

int pos[MAX] = {0}; 

bool node_cmp(node a,node b)
{
	//���ս���λ�ô�С�������� 
	return a.end < b.end;
}

int slove(int n)
{
	int ans = 0;
	int j = 1;
	pos[ans++] = t[j].id;
	for(int i = 2; i <= n; i++)
	{
		//�����һ�����鿪ʼʱ�����һ���������ʱ��󣬷������ 
		if(t[i].start > t[j].end)
		{
			j = i;
			pos[ans++] = t[i].id;
		}
	}
	
	return ans;
}

int main()
{
	int n;//�������
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>t[i].start>>t[i].end;
		t[i].id = i;
	} 
	
	//���� 
	sort(t+1,t+n+1,node_cmp);
	
//	for(int i = 1; i <= n; i++)
//		cout<<t[i].start<<" "<<t[i].end<<endl;

	int num = slove(n);
	cout<<num<<endl;
		
	for(int i = 0; i < num; i++)
		cout<<pos[i]<<" ";
	return 0;
} 

