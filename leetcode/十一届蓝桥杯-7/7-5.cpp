#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio> 
using namespace std;

const int N  = 1010 + 10;
int dp[N][N];		// dp[i][j] ��һ���� i �������ڶ����� j �����ķ���Ϊ dp[i][j]
const int mod = 2020;

int main() {
	
	memset(dp,0x00,sizeof(dp));

	dp[0][0] = 1;
	for(int i = 0; i <= 1010; i++)
		for(int j = 0; j <= 1010; j++) {
			if(i - 1 >= j) dp[i][j] += dp[i-1][j];	// ����һ�У���ô��ǰ����еĵڶ��в����������� 
				
			if(j > 0) dp[i][j] += dp[i][j-1];		// ���ڶ��� 
			
			dp[i][j] %= mod;
		}

	cout << dp[1010][1010] << endl;
	return 0;
} 
