#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;

int get_unique_count(int f[], int n) {
    int res = 1;
    for(int i = 1; i < n; i ++) {
        if(f[i] != f[i - 1])
            res ++;
    }
    return res;
}

int main() {
    cin >> n;
    int f[n] = {0};
    
    for(int i = 0; i < n; i++)
        cin >> f[i];
    sort(f,f + n);
    cout << get_unique_count(f,n) << endl;
    return 0;
}

����һ������Ϊ n ������ a�������дһ��������

int get_unique_count(int a[], int n);  // ��������ǰn�����еĲ�ͬ���ĸ���
�����ʽ
��һ�а���һ������ n��

�ڶ��а��� n ����������ʾ���� a��

�����ʽ
��һ�У�����һ��������ʾ�����в�ͬ���ĸ�����

���ݷ�Χ
1��n��1000
����������
5
1 1 2 4 5
���������
4
