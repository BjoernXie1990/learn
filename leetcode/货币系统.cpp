#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 50, M = 1e4 + 10;

LL f[N], t[M];
int n,m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> f[i];
    t[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = f[i]; j <= m; j++)
            t[j] += t[j - f[i]];
    }
    
    cout << t[m] << endl;
    return 0;
}

���� V �ֻ��ң���λ��Ԫ����ÿ�ֻ���ʹ�õĴ������ޡ�

��ͬ����Ļ��ң���ֵ��������ͬ�ġ�

���ڣ�Ҫ������ V �ֻ��Ҵճ� N ԪǮ�����ʹ��ж����ֲ�ͬ�Ĵշ���

�����ʽ
��һ�а����������� V �� N��

�������������У���һ����� V ��������ÿ��������ʾһ�ֻ��ҵ���ֵ��

�����ʽ
���һ����������ʾ�����ܷ�������

���ݷ�Χ
1��V��25,
1��N��10000
�𰸱�֤��long long��Χ�ڡ�

����������
3 10
1 2 5
���������
10
