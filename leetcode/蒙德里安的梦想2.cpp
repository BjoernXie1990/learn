#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 12, M = 1 << 12;
long long f[N][M];
bool vis[M];
vector<int> st[M];
int n,m;

int main() {
    while(cin >> n >> m , n && m) {
        memset(f,0x00,sizeof f);
        
        for(int i = 0; i <= 1 << n; i++) {
            int cnt = 0;    // ������0������
            
            vis[i] = true;
            for(int j = 0; j < n; j ++) 
                if(i >> j & 1) {
                    if(cnt & 1) break;
                    
                    cnt = 0;
                } else {
                    cnt ++;
                }
            if(cnt & 1) vis[i] = false;
        }
        
        // Ԥ����ÿһ��״̬������ת�Ƶ�״̬
        for(int j = 0; j <= 1 << n; j++) {
            st[j].clear();
            for(int k = 0; k <= 1 << n; k ++)
                if(vis[j | k] && (j & k) == 0) st[j].push_back(k);
        }
        
        f[0][0] = 1;
        for(int i = 1; i <= m; i++) 
            for(int j = 0; j < 1 << n; j++)
                for(auto& k : st[j])
                    f[i][j] += f[i-1][k];
        
        cout << f[m][0] << endl;
    }
}


���N*M�����̷ָ�����ɸ�1*2�ĵĳ����Σ��ж����ַ�����

���統N=2��M=4ʱ������5�ַ�������N=2��M=3ʱ������3�ַ�����

����ͼ��ʾ��

2411_1.jpg

�����ʽ
��������������������

ÿ���������ռһ�У�������������N��M��

����������N=0��M=0ʱ����ʾ������ֹ���Ҹ��������账��

�����ʽ
ÿ�������������һ�������ÿ�����ռһ�С�

���ݷ�Χ
1��N,M��11
����������
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
���������
1
0
1
2
3
5
144
51205
