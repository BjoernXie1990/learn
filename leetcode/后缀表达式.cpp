#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
ll f[2 * N];
int n,m,k;
ll ans;

int main() {
    cin >> n >> m;
    k = n + m + 1;
    for(int i = 0; i < k; i++) scanf("%lld",&f[i]);
    sort(f,f+k);

    if(!m) {
        int ri = k - 1;
        while(n >= 0) {
            ans += f[ri--];
            n--;
        }
    } else {
        ans = f[k - 1] - f[0];
        for(int i = 1; i < k - 1; i++) ans += abs(f[i]);
    }
    
    cout << ans;
    return 0;
}


���� N ���Ӻš�M �������Լ� N+M+1 ������ A1,A2,???,AN+M+1��С����֪������������ N ���Ӻš�M �������Լ� N+M+1 �������ճ��ĺϷ��ĺ�׺���ʽ�У������������һ����

�������������Ľ����

����ʹ�� 123+?���� ��23+1?�� �����׺���ʽ����� 4�������ġ�

�����ʽ
��һ�а����������� N �� M��

�ڶ��а��� N+M+1 ������ A1,A2,???,AN+M+1��

�����ʽ
���һ������������𰸡�

���ݷ�Χ
0��N,M��105,
?109��Ai��109
����������
1 1
1 2 3
���������
4
