#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
struct goods {
    int l,r;
    bool operator<(const goods& t) const {
        return l < t.l;
    }
}e[N];
int n;
int st,ed;

int main() {
    scanf("%d%d",&st,&ed);
    scanf("%d",&n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d%d",&e[i].l,&e[i].r);
    }
    sort(e,e+n);
    
    int res = 0, sucess = 0;
    for(int i = 0; i < n && st < ed; i++) {
        int j = i, ri = -2e9;
        while(j < n && e[j].l <= st) {
            ri = max(ri, e[j].r);
            j ++;
        }
        
        if(ri < st) {
            sucess = 1;
            break;
        }
        
        res ++;
        st = ri;
        i = j - 1;
    }
    
    if(sucess || (st < ed)) printf("-1\n");
    else printf("%d\n",res);
    
    return 0;
}

����N��������[ai,bi]�Լ�һ���߶�����[s,t]������ѡ�����ٵ����䣬��ָ���߶�������ȫ���ǡ�

�������������������޷���ȫ���������-1��

�����ʽ
��һ�а�����������s��t����ʾ�����߶�����������˵㡣

�ڶ��а�������N����ʾ������������

������N�У�ÿ�а�����������ai,bi����ʾһ������������˵㡣

�����ʽ
���һ����������ʾ����������������

����޽⣬�����-1��

���ݷ�Χ
1��N��105,
?109��ai��bi��109,
?109��s��t��109
����������
1 5
3
-1 3
2 4
3 5
���������
2
