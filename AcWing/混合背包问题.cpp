#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;
int f[N];
int n,m;

struct goods{
    int v,w,s;
};

int main() {
    cin >> n >> m;
    vector<goods> vec;
    for(int i = 0; i < n; i++) {
        int v,w,s;
        cin >> v >> w >> s;
        
        if(s <= 0) vec.push_back({v,w,s});
        else  {
            int t = 1;
            while(t <= s) {
                vec.push_back({v * t,w * t, -1});
                s -= t;
                t <<= 1;
            }
            if(s) vec.push_back({v * t,w * t, -1});
        }
    }
    
    for(auto& e : vec) {
        int v = e.v, w = e.w, s = e.s;
        if(s == -1) {
            for(int i = m; i >= v; i--)
                f[i] = max(f[i],f[i - v] + w);
        } else {
            for(int i = v; i <= m; i++)
                f[i] = max(f[i],f[i - v] + w);
        }
    }
    
    cout << f[m] << endl;
    return 0;
}


�� N ����Ʒ��һ�������� V �ı�����

��Ʒһ�������ࣺ

��һ����Ʒֻ����1�Σ�01��������
�ڶ�����Ʒ���������޴Σ���ȫ��������
��������Ʒ���ֻ���� si �Σ����ر�������
ÿ������� vi����ֵ�� wi��

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ����
�������ֵ��

�����ʽ
��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� N �У�ÿ���������� vi,wi,si���ÿո�������ֱ��ʾ�� i ����Ʒ���������ֵ��������

si=?1 ��ʾ�� i ����Ʒֻ����1�Σ�
si=0 ��ʾ�� i ����Ʒ���������޴Σ�
si>0 ��ʾ�� i ����Ʒ����ʹ�� si �Σ�
�����ʽ
���һ����������ʾ����ֵ��

���ݷ�Χ
0<N,V��1000
0<vi,wi��1000
?1��si��1000
��������
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
���������
8
