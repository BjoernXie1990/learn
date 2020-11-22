#include <iostream>

using namespace std;

const int N = 1e5 + 10;
// f[0 - N] A,B,C ͬ��֮��Ĺ�ϵ
// f[N - N * 2] A��B B��C C��A ��ʳ��ϵ
// f[N * 2 - N * 3] ���ܳԵļ���
int f[N * 3];
int n,k;

int find(const int x) {
    if(f[x] != x) return f[x] = find(f[x]);
    return f[x];
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n * 3; i++) f[i] = i;
    
    int ans = 0;
    while(k --) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b > n || c > n) {
            ans++;
            continue;
        }
        
        if(a == 1) {        // b and c
            if(find(b) == find(c + n) || find(b) == find(c + n * 2)) {        // b eat c     c eat b
                ans++;
                continue;
            }
            
            f[find(b)] = find(c);             // b and c
            f[find(b + n)] = find(c + n);
            f[find(b + n * 2)] = find(c + n * 2);
            
        } else if(a == 2) { // b eat c
            if(find(b) == find(c) || find(b) == find(c + n)) {            // b and c     c eat b
                ans++;
                continue;
            }     

            f[find(b)] = find(c + n * 2);       // b ��ͬ���� c �����
            f[find(b + n)] = find(c);           // b ���ԳԵ� c
            f[find(b + n * 2)] = find(c + n);   // c ���ԳԵ� b �����
        }
    }
    
    cout << ans ;
    return 0;
}

���������������ද��A,B,C�������ද���ʳ������������Ȥ�Ļ��Ρ�

A��B�� B��C��C��A��

����N�������1��N��š�

ÿ�����ﶼ��A,B,C�е�һ�֣��������ǲ���֪������������һ�֡�

����������˵������N�����������ɵ�ʳ������ϵ����������

��һ��˵���ǡ�1 X Y������ʾX��Y��ͬ�ࡣ

�ڶ���˵���ǡ�2 X Y������ʾX��Y��

���˶�N���������������˵����һ���һ���˵��K�仰����K�仰�е�����ģ��е��Ǽٵġ�

��һ�仰������������֮һʱ����仰���Ǽٻ�����������滰��

1�� ��ǰ�Ļ���ǰ���ĳЩ��Ļ���ͻ�����Ǽٻ���
2�� ��ǰ�Ļ���X��Y��N�󣬾��Ǽٻ���
3�� ��ǰ�Ļ���ʾX��X�����Ǽٻ���

��������Ǹ��ݸ�����N��K�仰������ٻ���������

�����ʽ
��һ������������N��K����һ���ո�ָ���

����K��ÿ�������������� D��X��Y������֮����һ���ո����������D��ʾ˵�������ࡣ

��D=1�����ʾX��Y��ͬ�ࡣ

��D=2�����ʾX��Y��

�����ʽ
ֻ��һ����������ʾ�ٻ�����Ŀ��

���ݷ�Χ
1��N��50000,
0��K��100000
����������
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
���������
3
