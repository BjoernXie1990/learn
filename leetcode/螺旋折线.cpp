����ͼ��ʾ���������߾���ƽ������������ǡ��һ�Ρ�

p1.png

�������� (X,Y)�����Ƕ�������ԭ��ľ��� dis(X,Y) �Ǵ�ԭ�㵽 (X,Y) ���������߶εĳ��ȡ�

���� dis(0,1)=3,dis(?2,?1)=9

������������ (X,Y)�����ܼ���� dis(X,Y) ��

�����ʽ
������������ X,Y��

�����ʽ
���һ����������ʾ dis(X,Y)��

���ݷ�Χ
?109��X,Y��109
����������
0 1
���������
3
�Ѷȣ��е�
ʱ/�����ƣ�1s / 64MB
��ͨ������436
�ܳ�������1293
��Դ���ھŽ����ű�ʡ��C++B��
�㷨��ǩ


#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll x,y;
ll ans;

ll Sn(ll n) {
    if(n == 0) return 0;
    return 2 * n + (n * (n - 1));
}

int main() {
    cin >> x >> y;
    ll n = max(abs(x),abs(y));
    ans = 4 * Sn(n-1);
    ll len = 2  + (n - 1) * 2;
    //cout << ans << " " << len << " " << n << endl; 

    if(y > 0 && abs(x) <= y) {                  // ��
        ans += len + len/2 + x;
    } else if(x > 0 && x >= abs(y)) {           // ��
        ans += len * 2 + len/2 - y;
    } else if(y <= 0 && abs(y) + 1 >= abs(x)) { // ��
        ans += len * 3 + -x-y;
    } else {
        ans += y - x;                           // ��
    }
    
    cout << ans;
    return 0;
}
