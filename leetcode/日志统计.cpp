#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct node{
    int time,id;
    bool operator<(const node& a) {
        return time < a.time;
    }
};

const int N = 1e5 + 10;
int n,d,k;
int x,y;
node f[N];
int ans[N],cnt[N],vis[N];
int e = 0;

void slove() {
    int le = 0;     // ��ʼʱ��ε������±�
    for(int i = 0; i < n; i++) {
        while(f[le].time + d <= f[i].time) {
            cnt[f[le++].id]--;
        }
        cnt[f[i].id]++;

        if(cnt[f[i].id] >= k && vis[f[i].id] == 0) {
            ans[e++] = f[i].id;
            vis[f[i].id] = 1;
        }
    }
}

int main() {
    cin >> n >> d >> k;
    memset(cnt,0x00,sizeof cnt);
    memset(f,0x00,sizeof f);
    memset(ans,0x00,sizeof ans);
    memset(vis,0x00,sizeof vis);
    for(int i = 0; i < n; i++) scanf("%d %d",&f[i].time,&f[i].id);
    
    sort(f,f+n);        // ����ʱ���С��������
    
    //for(int i = 0; i < n; i++) printf("%d %d\n",f[i].time,f[i].id);
    slove();
    
    sort(ans,ans+e);
    for(int i = 0; i < e; i++) printf("%d\n",ans[i]);
    return 0;
}


С��ά����һ������Ա��̳���������ռ���һ�ݡ����ޡ���־����־���� N �С�

����ÿһ�еĸ�ʽ�ǣ�

ts id  
��ʾ�� ts ʱ�̱�� id �������յ�һ�����ޡ���

����С����ͳ������Щ���������ǡ���������

���һ��������������һ������Ϊ D ��ʱ������յ������� K ���ޣ�С������Ϊ����������ǡ���������

������˵���������ĳ��ʱ�� T ��������� [T,T+D) ���ʱ����(ע��������ҿ�����)�յ������� K ���ޣ����������ǡ���������

������־���������С��ͳ�Ƴ��������ǡ������������ӱ�š�

�����ʽ
��һ�а����������� N,D,K��

���� N ��ÿ��һ����־�������������� ts �� id��

�����ʽ
����С�����˳��������� id��

ÿ�� id ռһ�С�

���ݷ�Χ
1��K��N��105,
0��ts,id��105,
1��D��10000
����������
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3
���������
1
3
�Ѷȣ��е�
ʱ/�����ƣ�1s / 64MB
��ͨ������995
�ܳ�������1963
��Դ���ھŽ����ű�ʡ��C++B��
�㷨��ǩ

