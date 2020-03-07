#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

#define MAX 100000
#define MAX_VAL 0x00ffffff

//��������ͼ��ÿ������Ե���ĵ� 
struct node
{
	int to;//�����һ���յ� 
	int val;//�ߵ�Ȩֵ 
	int next;//ͬһ�������һ���յ� 
}dir[MAX];

vector<int> path;//����������С���Ľڵ��˳�� 
int head[MAX] = {0};//ͷ���� 

//��ʽ�洢����ͼ 
void add(int from,int to,int val,int len)
{
	dir[len].to = to;
	dir[len].val = val;
	dir[len].next = head[from];
	head[from] = len;
} 

//ѡ����1�ŵ�Ϊ���ĸ��ڵ� 
void Prim(int n,int m)
{
	int visit[MAX] = {0};//�ж��ҵ����ڵ�
	
	path.push_back(1); 
	visit[1] = 1;
	
	//�����ҵ���������С�ڵ� 
	for(int i = 1; i < m; i++)
	{
		 int min_val = MAX_VAL;
		 int min_to = 0;//����ѭ�������ҵ�����С�� 
		 //�������Ѿ�ѡ��ĵ㿪ʼ���� 
		 for(int j = 0; j < path.size(); j++)
		 {
		 	int from = path[j];
		 	//���Ҹõ���Ե���ĵ㣬�ҵ�һ����С�ı� 
		 	for(int k = head[from]; k != 0; k = dir[k].next)
		 	{
		 		int to = dir[k].to;
		 		//����õ�û�б����ʣ����ұߵ�ȨֵС�ڵ�ǰ�ҵ��ģ����и��� 
		 		if(!visit[to] && min_val > dir[k].val)
		 		{
		 			min_val = dir[k].val;
		 			min_to = to; 
				}
			}
		 }
		 
		 if(min_val == MAX_VAL)
		 {
		 	cout<<"�޷�������С��"<<endl;
			return ; 
		 } 
		 
		 visit[min_to] = 1; 
		 path.push_back(min_to);
	}
} 

int main()
{
	int m;//��ķ�Χ
	cin>>m;
	 
	int n;//�ߵ���Ŀ
	cin>>n;
	
	int len = 1;
	for(int i = 1; i <= n; i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val,len);//u -> v 
		len++;
		add(v,u,val,len);//v -> u
		len++;
	}
	
	Prim(n,m);
//	cout<<endl;
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = head[i]; j != 0; j = dir[j].next)
//			cout<<dir[j].to<<' '<<dir[j].val<<' '<<i<<endl;
//	}
	
	//���δ�ӡ�������ڵ��˳�� 
	for(int i = 0; i < path.size(); i++)
		cout<<path[i]<<endl;
	
	return 0;
}
 
