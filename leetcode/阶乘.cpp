#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp;
typedef long long LL;

int kui(int a,int b,int p) {
    int res = 1;
    while(b) {
        if(b&1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int t = 2;
        int m = i;
        for(int j = 2; j <= m / j; j++) {
            while(m % j == 0) {
                mp[j] ++;
                m /= j;
            }
        }
        if(m > 1) mp[m] ++;
    }
    
    int res = 1;
    mp[2] -= mp[5];
    for(auto& e : mp) {
        if(e.first == 5) continue;
        res = (res * kui(e.first,e.second,10)) % 10;
    }
    cout << res << endl;
    return 0;
}

N  �Ľ׳ˣ����� N!����ָ�� 1 �� N������ 1 �� N�������������ĳ˻���

�׳�����Ľ���������ǳ��Ĵ�

���ڣ��������� N��������� N! �����ұߵķ��������Ƕ��١�

���� 5!=1��2��3��4��5=120������ 5! �����ұߵķ��������� 2��

�����ʽ
��һ�У�����һ������ N��

�����ʽ
���һ����������ʾ N! �����ұߵķ������֡�

���ݷ�Χ
1��N��1000
����������
7
���������
4
