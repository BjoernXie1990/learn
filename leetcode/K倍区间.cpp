#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef long long LL;
const int N = 1e5 + 10;
LL hash[N],n,k;
LL res,sum;

int main() {
    cin >> n >> k;
    hash[0] = 1;
    
    // [i,j] (sum[j] - sum[i - 1]) % k = 0
    //        sum[j] % k - sum[i - 1] % k = 0
    //          sum[j] % k = sum[i-1] % k
    for(int i = 0; i < n; i++) {
        int w;
        cin >> w;
        sum = (sum + w) % k;
        res += hash[sum];
        hash[sum] ++;
    }
    cout << res << endl;
    return 0;
}

����һ������Ϊ N �����У�A1,A2,��AN���������һ�������������� Ai,Ai+1,��Aj ֮���� K �ı��������Ǿͳ�������� [i,j] �� K �����䡣

��������������ܹ��ж��ٸ� K ��������

�����ʽ
��һ�а����������� N �� K��

���� N ��ÿ�а���һ������ Ai��

�����ʽ
���һ������������ K ���������Ŀ��

���ݷ�Χ
1��N,K��100000,
1��Ai��100000
����������
5 2
1
2
3
4
5
���������
6
