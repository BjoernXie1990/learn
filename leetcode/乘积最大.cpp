���� N ������ A1,A2,��AN��

�������ѡ�� K ������ʹ��˻����

����������ĳ˻������ڳ˻����ܳ������ͷ�Χ����ֻ������˻����� 1000000009 ��������

ע�⣬��� X<0�� ���Ƕ��� X ���� 1000000009 �������Ǹ�(?X)���� 1000000009 ������������0?((0?x)%1000000009)
�����ʽ
��һ�а����������� N �� K��

���� N ��ÿ��һ������ Ai��

�����ʽ
���һ����������ʾ�𰸡�

���ݷ�Χ
1��K��N��105,
?105��Ai��105
��������1��
5 3
-100000
-10000
2
100000
10000
�������1��
999100009
��������2��
5 3
-100000
-100000
-2
-100000
-100000
�������2��
-999999829

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int mod = 1e9 + 9;
const int N = 1e5 + 10;
ll f[N];
int n,k;

ll ans = 1;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%lld",&f[i]);
    sort(f,f+n);
    
    if(f[n-1] < 0) {    // ȫΪ����
        if(k & 1) {     // ѡ��������n : n - k ���и����Ӵ�С���
            int cnt = k;
            int i = n - 1;
            while(cnt --) {
                ans = (ans * f[i]) % mod;
                i--;
            }
        } else {        // ѡż������0 : k  ��С�������
            for(int i = 0; i < k; i++) ans = (ans * f[i]) % mod;
        }
    } else {                // ȫΪ���� ���� �����и�
        int le = 0, ri = n - 1;
        int cnt = k;
        if(cnt & 1) {       // ��������ɸѡ����һ����
            ans = f[ri--];
            cnt --;
        }
        
        // ȡ���������������ĳ˻�
        while(cnt > 1) {
            ll numle = f[le] * f[le + 1];
            ll numri = f[ri] * f[ri - 1];
            if(numle > numri) {
                ans = (ans * (numle % mod)) % mod;
                le += 2;
            } else {
                ans = (ans * (numri % mod)) % mod;
                ri -= 2;
            }
            cnt -= 2;
        } 
    }
    
    cout << ans;
    return 0;
}

