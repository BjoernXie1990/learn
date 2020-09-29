class Solution {
public:
    bool parseBoolExpr(string expression) {
        return check(expression,0,expression.size());
    }

    bool check(string& str,int le,int ri) {
        if(le == ri-1) return str[le] == 't' ? true : false;
        if(str[le] == '!') return !check(str,le+2,ri-1);

        int cnt = 1;
        int p = le+2;
        bool ans = (str[le] == '&');

        for(int i = p; cnt!= 0; i++) {
            if(str[i] == '(') ++cnt;
            else if(str[i] == ')') --cnt;

            // )   &(&(f,t),|(t,f))
            if(cnt == 0 || (str[i] == ',' && cnt==1)) {
                if(str[le] == '&')  ans = ans && check(str,p,i);
                else if(str[le] == '|') ans = ans || check(str,p,i);

                p = i + 1; 
            }
        }

        return ans;
    }
};


����һ�����ַ�����ʽ������?�������ʽ��boolean�� expression�����ظ�ʽ����������

��Ч�ı��ʽ����ѭ����Լ����

"t"��������Ϊ True
"f"��������Ϊ False
"!(expr)"���������Ϊ���ڲ����ʽ expr �����߼� �ǵ����㣨NOT��
"&(expr1,expr2,...)"���������Ϊ�� 2 ���������ڲ����ʽ expr1, expr2, ... �����߼� ������㣨AND��
"|(expr1,expr2,...)"���������Ϊ�� 2 ���������ڲ����ʽ expr1, expr2, ... �����߼� ������㣨OR��
?

ʾ�� 1��

���룺expression = "!(f)"
�����true
ʾ�� 2��

���룺expression = "|(f,t)"
�����true
ʾ�� 3��

���룺expression = "&(t,f)"
�����false
ʾ�� 4��

���룺expression = "|(&(t,f,t),!(t))"
�����false
?

��ʾ��

1 <= expression.length <= 20000
expression[i] �� {'(', ')', '&', '|', '!', 't', 'f', ','} �е��ַ���ɡ�
expression ����������ʽ��������Ч���ʽ����ʾһ������ֵ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/parsing-a-boolean-expression
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
