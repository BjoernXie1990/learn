#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int n,k;//n ָ������ճ������Ʊ��  k ָ��Ʊ�������� 
int p[100] = {0};//ÿһ���ж�ʹ�õĺ�����ֵ���� 
int tag[100] = {0};//�洢���ʵ���ֵ 
int ans = 0; 

//kind ��ǰ��ʹ����Ʊ��������  val  
void dfs(int kind,int val)
{
	if(kind == k)
		return ;
	p[kind] = val;
	int dp[10000] = {0};//dp[i]  ��ʾi����Ʊ������Ҫ�������� 
	memset(dp,MAX,sizeof(dp));
	dp[0] = 0;
	int sum = 1;
	
	//i ʹ�õ���Ʊ����ֵ 
	for(int i = 1; ; i++)
	{
		//j ��ʾ��Ʊ����ֵ 
		for(int j = 0; j <= kind && i >= p[j]; j++)
			dp[i] = min(dp[i],dp[i - p[j]] + 1);
		
		if(dp[i] > n)
			break;
		
		sum = max(sum,i);
		//cout<<i<<endl; 
	}
	
	//���������õ�������ִ������Ʊ����ֵ������tag[]���� 
	if(sum > ans)
	{
		for(int i = 0; i <= kind; i++)
			tag[i] = p[i];
		
		ans = sum;
	}
	
	for(int i = val+1; i <= sum + 1; i++)
		dfs(kind+1,i); 
}

int main()
{
	cin>>n>>k;
	
	dfs(0,1);
	
	for(int i = 0; i < k; i++)
		cout<<tag[i]<<' ';
	cout<<endl;
	
	cout<<"MAX="<<ans<<endl;
	return 0;
}
