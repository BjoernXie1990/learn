#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;
int f[N];
int n,m;

int main() {
    cin >> n >> m;
    f[0] = 1;
    for(int j = 0; j < n; j++) {
        int x;
        cin >> x;
        for(int i = m; i >= x; i--) 
            f[i] += f[i - x];
    }
    
    cout << f[m] << endl;
    return 0;
}


����N��������A1,A2,��,AN������ѡ�����ɸ�����ʹ���ǵĺ�ΪM�����ж�����ѡ�񷽰���

�����ʽ
��һ�а�����������N��M��

�ڶ��а���N����������ʾA1,A2,��,AN��

�����ʽ
����һ����������ʾ��ѡ��������

���ݷ�Χ
1��N��100,
1��M��10000,
1��Ai��1000
����������
4 4
1 1 2 2
���������
3
