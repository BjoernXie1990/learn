#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

 
vector<int> ans;//��Ҫ�����ٵ��ɿ����� 
int eat[105] = {0};//��Ҫ�Ե���������� 
int n,m;//�����������Ҫ�Ե������� 

int dfs(map<pair<int, int>, int>&visit,int l,int r)
{
	if(l >= r)
	{
		return 0;
	}
	pair<int, int> p = make_pair(l, r);
    if(visit.find(p) != visit.end()) 
		return visit[p];
		
	int ans = INT_MAX;
	for(int i = 0; i < m && eat[i] <= r; i++)
	{
		//ȷ���Ե�����[l,r)������ 
		if(eat[i] < l)
			continue;
		
		ans =  min(ans,dfs(visit,l,eat[i] - 1) + dfs(visit,eat[i]+1,r));
	}
	
	if(ans == INT_MAX)
		ans = 0;
	else
		ans += r-l;
		
	return visit[p] = ans;
}

int main()
{
	//����cin cout �ڱ�׼��������������ĵ����� 
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int t;
	cin>>t;
	int num = t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 0; i < m; i++)
		{
			cin>>eat[i];
		}
		map<pair<int, int>, int> visit;
		ans.push_back(dfs(visit,1,n));
	}
	
	for(int i = 0; i < num; i++)
		cout<<ans[i]<<endl;
	
	return 0;
}
