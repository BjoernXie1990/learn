#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string str,s;
map<string,int> mp;
int n;

int main() {
    cin >> str >> n;
    while (n --) {
        cin >> s;
        sort(s.begin(),s.end());
        mp[s] ++;
    }
    
    int m = str.size();
    int res = 0;
    for(int i = 0; i <= m - 8; i++) {
        string t = str.substr(i,8);
        sort(t.begin(),t.end());
        res += mp[t];
    }
    cout << res << endl;
    return 0;
} 

����Ħ˹�� X ���յ�һ�����ϣ�ȫ����Сд��ĸ��ɡ�

���������ṩ����һ�����ϣ���೤��Ϊ 8 �������б�

����Ħ˹���֣���Щ�����Ǳ����Һ���������ǰ�Ƿ������еġ�

�����дһ�����򣬴ӵ�һ�������������������������λ�á�

Ҫ����������������п����ԡ�

�����ʽ
��һ�У�һ���ַ��� s��ȫ����Сд��ĸ��ɡ�

������һ����һ������ n����ʾ������ n �����롣

�������� n ���ַ���������Сд��ĸ��ɣ����ȶ�Ϊ 8��

�����ʽ
һ����������ʾÿ����������������� s ��ƥ��������ܺ͡�

���ݷ�Χ
�ַ��� s �ĳ��Ȳ����� 220,
1��n��1000
����������
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc
���������
4
��������
��һ������ƥ���� 3 �Σ��ڶ�������ƥ���� 1 �Σ�һ�� 4 �Ρ�
