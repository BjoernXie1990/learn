#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

string s;
stack<int> num;
stack<char> op;

void eval() {
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    
    if(c == '+') num.push(a + b);
    else if(c == '-') num.push(b - a);
    else if(c == '*') num.push(a * b);
    else num.push(b / a);
}

int main() {
    cin >> s;
    // ���ȼ�
    unordered_map<char,int> mp{{'-',1},{'+',1},{'*',2},{'/',2}};
    
    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if(isdigit(ch)) {
            int x = 0, j = i;
            while(j < s.size() && isdigit(s[j]))
                x = x * 10 + s[j ++ ] - '0';
            i = j - 1;
            num.push(x);
        } else if(ch == '(') {
            op.push(ch);
        } else if(ch == ')') {
            while(op.top() != '(') eval();
            op.pop();
        } else {
            while(op.size() && mp[op.top()] >= mp[ch])
                eval();
            op.push(ch);
        }
    }
    
    while(op.size()) 
        eval();
    
    cout << num.top() << endl;
    return 0;
}


����һ�����ʽ����������������� +,-,*,/���� �� �� �����������ܰ������ţ�����������ʽ������ֵ��

ע�⣺

���ݱ�֤�����ı��ʽ�Ϸ���
��Ŀ��֤���� - ֻ��Ϊ���ų��֣�������Ϊ���ų��֣����磬-1+2,(2+2)*(-(1+1)+2) ֮����ʽ��������֡�
��Ŀ��֤���ʽ���������־�Ϊ��������
��Ŀ��֤���ʽ���м��������Լ�����У��������� 231?1��
��Ŀ�е�������ָ�� 0 ȡ����Ҳ����˵���ڴ��� 0 �Ľ������ȡ�������� 5/3=1������С�� 0 �Ľ������ȡ�������� 5/(1?4)=?1��
C++��Java�е�����Ĭ��������ȡ����Python�е�����//Ĭ������ȡ�������Python��eval()�����е�����Ҳ������ȡ�����ڱ����в���ֱ��ʹ�á�
�����ʽ
��һ�У�Ϊ�������ʽ��

�����ʽ
��һ�У�Ϊ���ʽ�Ľ����

���ݷ�Χ
���ʽ�ĳ��Ȳ����� 105��

����������
(2+2)*(1+1)
���������
8
