ά��һ�����ϣ���ʼʱ����Ϊ�գ�֧�����¼��ֲ�����

��I x��������һ����x��
��PM���������ǰ�����е���Сֵ��
��DM����ɾ����ǰ�����е���Сֵ�����ݱ�֤��ʱ����СֵΨһ����
��D k����ɾ����k�����������
��C k x�����޸ĵ�k����������������Ϊx��
����Ҫ����N�β������������е�2�������������ǰ���ϵ���Сֵ��

�����ʽ
��һ�а�������N��

������N�У�ÿ�а���һ������ָ�����ָ��Ϊ��I x������PM������DM������D k����C k x���е�һ�֡�

�����ʽ
����ÿ�����ָ�PM�������һ���������ʾ��ǰ�����е���Сֵ��

ÿ�����ռһ�С�

���ݷ�Χ
1��N��105
?109��x��109
���ݱ�֤�Ϸ���

����������
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
���������
-10
6

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int f[N],idx;
int hp[N],ph[N];    // hp[i] ���еĵ�i�����Ӧ�ĵ�hp[i]�β���  ph[i] ��i�β�������ڶ��е��±�
int n,a,b;

// ���ںţ���С��
bool comper(const int le,const int ri) {
    return f[le] > f[ri];
}

void heap_swap(const int le,const int ri) {
    swap(ph[hp[le]],ph[hp[ri]]);
    swap(hp[le],hp[ri]);
    swap(f[le],f[ri]);
}

// ���ϵ���
void push(const int x) {
    int ch = x;
    int fa = x / 2;
    while(fa) {
        if(comper(fa,ch)) {
            heap_swap(fa,ch);
        } else {
            break;
        }
        ch = fa;
        fa = ch / 2;
    }
}

// ���µ���
void pop(const int x) {
    int fa = x;
    int ch = fa * 2;
    while(ch <= idx) {
        if(ch < idx && comper(ch,ch + 1)) ch ++;
        if(comper(fa,ch)) {
            heap_swap(fa,ch);
        } else {
            break;
        }
        fa = ch;
        ch = fa * 2;
    }
}

int main() {
    cin >> n;
    int k = 0;
    
    while(n -- ){
        string oper;
        cin >> oper;
        if(oper == "I") {
            cin >> a;
            ++idx;
            ++k;
            f[idx] = a;
            ph[k] = idx;
            hp[idx] = k;
            push(idx);
        } else if(oper == "PM") {
            cout << f[1] << endl;
        } else if(oper == "DM") {
            heap_swap(1,idx);
            idx--;
            pop(1);
        } else if(oper == "D") {
            cin >> a;
            a = ph[a];
            heap_swap(a,idx);
            idx--;
            pop(a),push(a);
        } else if(oper == "C") {
            cin >> a >> b;
            a = ph[a];
            f[a] = b;
            push(a),pop(a);
        }
    }
    return 0;
}
