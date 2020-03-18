
/*������ a[1], a[2], ..., a[n] �У���������±� i, j, k ���� 0<i<j<k<n+1 �� a[i]<a[j]<a[k]����� a[i], a[j], a[k] Ϊһ�������Ԫ�飬a[j]Ϊ������Ԫ������ġ�
��������һ�����У������������ж��ٸ�Ԫ�ؿ����ǵ�����Ԫ������ġ�
�����ʽ
��������ĵ�һ�а���һ������ n��
�����ڶ��а��� n ������ a[1], a[2], ..., a[n]�����ڵ��������ÿո�ָ�����ʾ���������С�
�����ʽ
�������һ�а���һ����������ʾ�𰸡�
��������
5
1 2 5 3 5
�������
2
*/

#include <iostream>
using namespace std;

int dp[1005][2] = {0};
int arr[1005] = {0};

void slove(int n)
{
	//���ұ߱������ 
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] < arr[j])
				dp[i][1]++;
		}
	}
	
	//����߱���С�� 
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[i] > arr[j])
				dp[i][0]++;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	slove(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(dp[i][0] && dp[i][1])
			ans++;
			
	cout<<ans<<endl;
	return 0;
}
