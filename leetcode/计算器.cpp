class Solution {
public:
    int calculate(string s) {
        s += "+";
        stack<int> st;
        char oper = '+';
        int t = 0;
        for(auto& e : s) {
            if(e <= '9' && e >= '0') {
                t = t * 10 + (e - '0');
                continue;
            }
            if(e == ' ') continue;

            if(oper == '+') st.push(t);
            else if(oper == '-') st.push(-t);
            else if(oper == '*') {
                t *= st.top();st.pop();
                st.push(t);
            } else {
                t = st.top() / t;st.pop();
                st.push(t);
            }
            t = 0;
            oper = e;
        }

        int res = 0;
        while(st.size()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

����һ����������������(+)����(-)����(*)����(/)���������ʽ(���ų���)������������

���ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�??�� ���������������������֡�

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
���ӣ�https://leetcode-cn.com/problems/calculator-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
