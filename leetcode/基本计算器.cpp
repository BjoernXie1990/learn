class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ") ";
        int id = 0;
        return dfs(s,id);;
    }

    int dfs(string& s,int& id) {
        int res = 0, cur = 0;
        char oper = '+';

        while(id < s.size()) {
            if(s[id] == '(') {
                cur = dfs(s,++id);
                //cout << res << " " << cur << " " << oper << endl;
                res = check(res,cur,oper);
                cur = 0;
                oper = '+';
            } else if(s[id] == ')') {
                break;
            } else if(s[id] == '+' || s[id] == '-') {
                res = check(res,cur,oper);
                oper = s[id];
                cur = 0;
            } else if(s[id] >= '0' && s[id] <= '9') {
                cur = cur * 10 + (s[id] - '0');
            } 
            id++;
        }

        return check(res,cur,oper);
    }

    int check(int a,int b,char oper) {
        if(oper == '+')
            return a + b;
        return a - b;
    }
};


ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ s ��ֵ��

?

ʾ�� 1��

���룺s = "1 + 1"
�����2
ʾ�� 2��

���룺s = " 2-1 + 2 "
�����3
ʾ�� 3��

���룺s = "(1+(4+5+2)-3)+(6+8)"
�����23
?

��ʾ��

1 <= s.length <= 3?* 105
s �����֡�'+'��'-'��'('��')'���� ' ' ���
s ��ʾһ����Ч�ı��ʽ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/basic-calculator
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
