#include <iostream>
using namespace std;

const int N = 35;
int w[N], f[N][N], g[N][N];
int n;

void dfs(int l,int r) {
    if(l > r) return ;
    cout << g[l][r] << " ";
    dfs(l,g[l][r]-1);
    dfs(g[l][r] + 1,r);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    for(int len = 1; len <= n; len++)
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            
            if(l == r) {
                f[l][r] = w[l];
                g[l][r] = l;
            } else {
                for(int k = l; k <= r; k++) {
                    int left = (k == l) ? 1 : f[l][k - 1];
                    int right = (k == r) ? 1 : f[k + 1][r];
                    int score = left * right + w[k];
                    if(score > f[l][r]) {
                        f[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;
    dfs(1,n);
    cout << endl;
    return 0;
}

��һ��n���ڵ�Ķ�����tree���������Ϊ��1,2,3,��,n������������1,2,3,��,nΪ�ڵ��š�

ÿ���ڵ㶼��һ����������Ϊ�����������ǵ�i���ڵ�ķ���Ϊdi��tree������ÿ����������һ���ӷ֣���һ������subtree��Ҳ����tree�����ļӷּ��㷽�����£�?????

subtree���������ļӷ� �� subtree���������ļӷ� �� subtree�ĸ��ķ���?

��ĳ������Ϊ�գ��涨��ӷ�Ϊ1��Ҷ�ӵļӷ־���Ҷ�ڵ㱾��ķ��������������Ŀ�������

����һ�÷����������Ϊ��1,2,3,��,n���Ҽӷ���ߵĶ�����tree��

Ҫ�������?

��1��tree����߼ӷ�?

��2��tree��ǰ�����

�����ʽ
��1�У�һ������n��Ϊ�ڵ������?

��2�У�n���ÿո������������Ϊÿ���ڵ�ķ�����0<����<100����

�����ʽ
��1�У�һ��������Ϊ��߼ӷ֣�������ᳬ��int��Χ����?????

��2�У�n���ÿո������������Ϊ������ǰ�������������ڶ��ַ�����������ֵ�����С�ķ�����

���ݷ�Χ
n<30
����������
5
5 7 1 2 10
���������
145
3 1 2 4 5
