#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 110, M = 1010;
int t,r,c,n;
int res[M],vis[N][N];
string f[N];

void dfs(int x,int y) {
    static int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};
    if(vis[x][y]) return ;
    vis[x][y]  = 1;
    
    for(int i = 0; i< 4; i++) {
        int a = x+dx[i], b = y + dy[i];
        if(a < 0 || b < 0 || a >= r || b >= c || vis[a][b] || f[a][b] == '0') continue;
        dfs(a,b);
    }
}

int slove() {
    memset(vis,0x00,sizeof vis);
    int ret = 0;
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            if(vis[i][j] || f[i][j] == '0') continue;
            dfs(i,j);
            ret ++;
        }
    return ret;
}



int main () {
    cin >> t;
    int cnt = 0;
    while(t--) {
        cnt ++;
        cin >> r >> c;
        for(int i = 0; i < r ;i ++)
           cin >> f[i];
        
        cin >> n;
        int end = 0;
        while(n --) {
            char ch;
            cin >> ch;
            if(ch == 'Q') res[end++] = slove();
            else {
                int a,b,c;
                cin >> a >> b >> c;
                f[a][b] = c + '0';
            }
        }
        
        printf("Case #%d:\n",cnt);
        for(int i = 0; i < end; i++)
            cout << res[i] << endl;
    }
    
    return 0;
}


������һ��R��C�еľ�����������ÿ�������ڵ����ֶ���0��1��

���ǽ���������ִ��N��������ÿ��������������֮һ��

����M���������һ����Ԫ���е����ָ���Ϊ0��1��
����Q��ȷ��1�Ĳ�ͬ��ͨ����������� 1����ͨ������ָ������ȫ��Ϊ1����ͨ�ĵ�Ԫ����Ӽ������Ӽ�������ͨ�����Ź����Ե�ڵ�Ԫ��֮���н������ԴӸ������е��κε�Ԫ�񵽴�������е��κ�������Ԫ��
�����ʽ
��һ�а�������T����ʾ����T��������ݡ�

ÿ�����ݵ�һ�а�����������R��C����ʾ���������������������

������R�У�ÿ�а���һ������ΪC����1��0���ɵ��ַ�������ʾ��������ĳ�ʼ״̬��

������һ�У���������N����ʾ����������

������N�У�ÿ�а���һ������ָ�����ָ����֣�������ʾ��

��M x y z������ʾMָ����庬��Ϊ����x�е�y�еķ����ڵ�ֵ��Ϊz��
��Q������ʾQָ���ʾ����һ��ѯ�ʡ�
�����ʽ
����ÿ��������ݣ���һ�������Case #x:��������xΪ����ţ���1��ʼ����

������Q�У�ÿ�����һ��ѯ�ʵĽ����

���ݷ�Χ
1��T��10,
1��R,C��100,
0��x<R,
0��y<C,
0��z��1,
1��N��1000
����������
1
4 4
0101
0010
0100
1111
7
Q
M 0 2 1
Q
M 2 2 0
Q
M 2 1 0
Q
���������
Case #1:
4
2
2
2
