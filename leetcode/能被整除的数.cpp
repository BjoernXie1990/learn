#include <iostream>
using namespace std;

typedef long long LL;
const int N = 20;
int p[N],n,m;

int main() {
    cin >> n >> m;
    int res = 0;
    for(int i = 0; i < m; i++) cin >> p[i];
    
    for(int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;
        for(int j = 0;  j < m; j++)
            if(i >> j & 1) {
                cnt ++;
                if((LL) t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        
        if(t != -1) {
            if(cnt & 1) res += n / t;
            else res -= n / t;
        }
    }
    cout << res << endl;
}


����һ������n��m����ͬ������p1,p2,��,pm��

�������1~n���ܱ�p1,p2,��,pm�е�����һ���������������ж��ٸ���

�����ʽ
��һ�а�������n��m��

�ڶ��а���m��������

�����ʽ
���һ����������ʾ���������������ĸ�����

���ݷ�Χ
1��m��16,
1��n,pi��109
����������
10 2
2 3
���������
7
