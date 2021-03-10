class Solution {
public:
    int calculate(string s) {
        s += " ";
        string oper("");
        vector<int> st;

        for(int i = 0, j = -1; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(j == -1) j = 0;
                j = j * 10 + (s[i] - '0');
                continue;
            }

            if(j != -1) {
                st.push_back(j);
            }

            if(st.size() > 1 && j != -1 && (oper.back() == '*' || oper.back() == '/')) {
                int a = st.back();
                st.pop_back();
                int b = st.back();
                st.pop_back();

                st.push_back(check(b,a,oper.back()));
                oper.pop_back();
            }

            if(s[i] != ' ') oper += s[i];
            j = -1;
        }

       int res = st[0];
       for(int i = 1; i < st.size(); i++) {
           res = check(res,st[i],oper[i - 1]);
       }

       return res;
    }
    int check(int a,int b,char oper) {
        if(oper == '+')
            return a + b;
        if(oper == '-')
            return a - b;
        if(oper == '*')
            return a * b;
        return a / b;
    }

};


ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��

�ַ������ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�??�� ���������������������֡�

ʾ��?1:

����: "3+2*2"
���: 7
ʾ�� 2:

����: " 3/2 "
���: 1
ʾ�� 3:

����: " 3+5 / 2 "
���: 5
˵����

����Լ����������ı��ʽ������Ч�ġ�
�벻Ҫʹ�����õĿ⺯�� eval��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/basic-calculator-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
