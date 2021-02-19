#include <iostream>
#include <string>
#include <vector>
using namespace std;

string id[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    string s;
    cin >> s;
    int num = 0;
    for(auto& e : s) 
        num += e - '0';
    
    if(num == 0) {
        cout << id[0];
        return 0;
    }
    
    vector<string> res;
    while(num) {
        res.push_back(id[num % 10]);
        num /= 10;
    }
    for(int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] << " ";
    return 0;
}


����һ���Ǹ����� N����������Ǽ��� N ���������ֵ��ܺͣ�����Ӣ������ܺ͵�ÿ�����֡�

�����ʽ
��һ�У�����һ������ N��

�����ʽ
��һ�У���Ӣ������ܺ͵�ÿ�����֣�����֮���ÿո������

���ݷ�Χ
0��N��10100
����������
12345
���������
one five
