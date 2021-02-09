#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M =20;
char s[N][M], f[M];
int t[M][M];
int n,m,k;

bool check(int id) {
    memset(t,0x00,sizeof t);
    
    for(int i = 1; s[id][i]; i++) t[i][0] = i;
    for(int i = 1; f[i]; i++) t[0][i] = i;
    int len1 = 0, len2 = 0;
    
    for(int i = 1; s[id][i] ; i ++) {
        len1 ++;
        len2 = 0;
        for(int j = 1; f[j]; j ++) {
            if(s[id][i] == f[j]) t[i][j] = t[i-1][j-1];
            else t[i][j] = min(t[i-1][j-1],min(t[i-1][j], t[i][j-1])) + 1;
            len2 ++;
        }
    }

    return (t[len1][len2] <= k) ? true : false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i] + 1;
    
    for(int i = 0; i < m; i++) {
        cin >> f + 1 >> k;
        
        int res = 0;
        for(int j = 0; j < n; j++) 
            if(check(j)) res ++;
        
        cout << res << endl;
    }
    
    return 0;
}

����n�����Ȳ�����10���ַ����Լ�m��ѯ�ʣ�ÿ��ѯ�ʸ���һ���ַ�����һ�������������ޡ�

����ÿ��ѯ�ʣ��������������n���ַ������ж��ٸ��ַ������������޲��������ھ����������ѯ�ʸ������ַ�����

ÿ�����ַ������еĵ����ַ��Ĳ��롢ɾ�����滻����һ�β�����

�����ʽ
��һ�а�����������n��m��

������n�У�ÿ�а���һ���ַ�������ʾ�������ַ�����

�ٽ�����m�У�ÿ�а���һ���ַ�����һ����������ʾһ��ѯ�ʡ�

�ַ�����ֻ����Сд��ĸ���ҳ��Ⱦ�������10��

�����ʽ
�����m�У�ÿ�����һ��������Ϊ�������ʾһ��ѯ���������������ַ���������

���ݷ�Χ
1��n,m��1000,

����������
3 2
abc
acd
bcd
ab 1
acbd 2
���������
1
3
