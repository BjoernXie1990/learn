#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 12, M = 1 << N; // 1-11 �У�2^11 ��״̬
ll f[N][M];             // f[i][j] �ӵ�i-1���������i�У�״̬Ϊj,  j �Ķ�����λΪ1��ʾ��ǰ�з��÷���Ϊ0��ʾ������
vector<int> state[M];   // ÿһ��״̬����Ӧ���Է��õ�״̬
bool st[M];             // �Ƿ���Գɹ�ת�ƣ�j ״̬���� k״̬�� �Ƿ�Ϸ�

int n, m;

int main() {
    while(cin >> n >> m, n || m) {
        
        // ��ʼ��
        for(int i = 0; i < (1 << n); i ++) {
            int cnt = 0;    // ǰ������0������
            bool is_valid = true;
            
            for(int j = 0; j < n; j ++) {
                if((i >> j) & 1) {      // 1 ����
                    if(cnt & 1) {       // ǰ������0λ���������Ϸ�
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                } else {    // 0 �����ã�����0 + 1
                    cnt++;
                }
            }
            
            if(cnt & 1) is_valid = false;   // ����0λ�����������Ϸ�
            st[i] = is_valid;
        }
        
        for(int i = 0; i < (1 << n); i ++) {
            state[i].clear();
            for(int j = 0; j < (1 << n); j ++) 
                if((i & j) == 0 && st[i | j])   state[i].push_back(j);  // ����״̬i��˵�����Բ����״̬Ϊj
        }
        
        memset(f,0x00,sizeof(f));
        f[0][0] = 1;
        for(int i = 1; i <= m; i ++)
            for(int j = 0; j < (1 << n); j++)
                for(auto& k : state[j]) f[i][j] += f[i - 1][k];
        
        cout << f[m][0] << endl;
    }
    return 0;
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
