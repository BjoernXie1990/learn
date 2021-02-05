#include <iostream>
using namespace std;

const int N = 10;
char f[N][N];
int r[N][N],c[N][N],d[N][N];

bool check(int x,int y) {
    while(x < 9 && f[x][y] != '.') {
        y++;
        if(y == 9) {
            y = 0;
            x ++;
        }
    }
    if(x == 9) return true;
    int id = x / 3 * 3 + y / 3;
    
    for(int i = 1; i <= 9; i++) {
        if(r[x][i] || c[y][i] || d[id][i]) continue;
        r[x][i] = c[y][i] = d[id][i] = 1;
        f[x][y] = i + '0';
        if(check(x,y)) return true;
        f[x][y] = '.';
        r[x][i] = c[y][i] = d[id][i] = 0;
    }
    return false;
}

int main() {
    for(int i = 0; i < 9; i++)
        cin >> f[i];
    
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            if(f[i][j] == '.') continue; 
            int id = i / 3 * 3 + j / 3;
            int num = f[i][j] - '0';
            r[i][num] = c[j][num] = d[id][num] = 1;
        }
    check(0,0);
    
    for(int i = 0; i < 9; i++)
        cout << f[i] << endl;
    return 0;
}


������һ�ִ�ͳ������Ϸ������Ҫ��һ�� 9��9 ����������������ʹ��ͼ��ÿ�С�ÿ�С�ÿ�� 3��3 �ľŹ��������� 1��9 ��ǡ�ó���һ�Ρ�

���дһ��������д������

�����ʽ
���빲 9 �У�ÿ�а���һ������Ϊ 9 ���ַ�����������ʾ��������

���е�ÿ���ַ����� 1��9 �� .����ʾ��δ��䣩��

�����ʽ
�����ȫ�����������

���ݱ�֤��Ψһ�⡣

����������
.2738..1.
.1...6735
.......29
3.5692.8.
.........
.6.1745.3
64.......
9518...7.
.8..6534.
���������
527389416
819426735
436751829
375692184
194538267
268174593
643217958
951843672
782965341
