#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    
    int res = 0, cnt = -1;
    for(auto [k,v] : mp) {
        if(cnt == -1 || v > cnt) {
            res = k;
            cnt = v;
        } else if(v == cnt && k < res) {
            res = k;
        }
    }
    
    cout << res << endl;
    return 0;
}


���� n �����������ҳ������г��ִ�����������

������������ж���������������С��һ����

�����ʽ
����ĵ�һ��ֻ��һ�������� n����ʾ���ֵĸ�����

����ĵڶ����� n ������ s1,s2,��,sn��

���ڵ����ÿո�ָ���

�����ʽ
����� n �������г��ִ�����������

������������ж�������������С��һ����

���ݷ�Χ
1��n��1000,
1��si��10000
����������
6
10 1 10 20 30 20
���������
10
