#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 21, M = 1 << 21;

int n;
int w[N][N];
int f[M][N];    // f[i][j] ��0->j, �����ĵ�Ϊi�����·������

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    memset(f,0x3f,sizeof f);
    f[1][0] = 0;
    
    for(int i = 1; i < 1 << n; i++)
        if(i & 1)
        for(int j = 1; j < n; j++) 
            if(i >> j &  1)
                for(int k = 0; k < n; k++)
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j],f[i - (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}


����һ�� n ����Ĵ�Ȩ����ͼ����� 0~n-1 ��ţ������ 0 ���յ� n-1 �����Hamilton·���� Hamilton·���Ķ����Ǵ� 0 �� n-1 ���ز�©�ؾ���ÿ����ǡ��һ�Ρ�

�����ʽ
��һ����������n��

������n��ÿ��n�����������е�i�е�j��������ʾ��i��j�ľ��루��Ϊa[i,j]����

���������x,y,z�����ݱ�֤ a[x,x]=0��a[x,y]=a[y,x] ���� a[x,y]+a[y,z]>=a[x,z]��

�����ʽ
���һ����������ʾ���Hamilton·���ĳ��ȡ�

���ݷ�Χ
1��n��20
0��a[i,j]��107
����������
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
���������
18
