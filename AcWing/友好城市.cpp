#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5010;
vector<vector<int> > f;
int g[N];
int n;

int check(int k) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        g[i] = 1;
        for(int j = 1; j < i; j++)
            if(f[i][k] > f[j][k]) g[i] = max(g[i],g[j] + 1);
        res = max(g[i],res);
    }
    
    return res;
}

int main() {
    cin >> n;
    f = vector<vector<int> > (n + 1, vector<int> (2,0));
    for(int i = 1; i <= n; i++)
        cin >> f[i][0] >> f[i][1];
    
    int res = 1;
    sort(f.begin() + 1,f.end(),[](vector<int> a,vector<int> b)->bool{
        return a[0] < b[0];
    });
    res = max(res,check(1));
    
    cout << res << endl;
    return 0;
}


Palmia����һ����ᶫ���Ĵ�ӣ����б�ֱ���ϱ����������ϸ���λ�ø�����ͬ��N�����С�

������ÿ���������ҽ���һ���Ѻó������ϰ������Ҳ�ͬ���е��Ѻó��в���ͬ��

ÿ���Ѻó��ж������������ں��Ͽ���һ��ֱ�ߺ��������������У��������ں�����̫�����������������������������棬�Ա����¹ʡ�

��̰�����������һЩ��׼�;ܾ�����ľ�����ʹ���ڱ�֤�����������߲��ཻ������£�����׼�����뾡���ࡣ

�����ʽ
��1�У�һ������N����ʾ��������

��2�е���n+1�У�ÿ�������������м���1���ո�������ֱ��ʾ�ϰ��ͱ�����һ���Ѻó��е����ꡣ

�����ʽ
��һ�У����һ����������ʾ����������׼�������������

���ݷ�Χ
1��N��5000,
0��xi��10000
����������
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
���������
4
