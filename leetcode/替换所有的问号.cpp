����һ��������СдӢ����ĸ�� '?' �ַ����ַ��� s<var> </var>�����㽫���е� '?' ת��Ϊ����Сд��ĸ��ʹ���յ��ַ����������κ� �����ظ� ���ַ���

ע�⣺�� ���� �޸ķ� '?' �ַ���

��Ŀ����������֤ �� '?' �ַ� ֮�⣬�����������ظ����ַ���

���������ת������������ת�����󷵻����յ��ַ���������ж������������뷵�������κ�һ��������֤�����ڸ�����Լ�������£������Ǵ��ڵġ�

?

ʾ�� 1��

���룺s = "?zs"
�����"azs"
���ͣ���ʾ������ 25 �ֽ���������� "azs" �� "yzs" ���Ƿ�����ĿҪ��ġ�ֻ�� "z" ����Ч���޸ģ���Ϊ�ַ��� "zzs" ���������ظ������� 'z' ��
ʾ�� 2��

���룺s = "ubv?w"
�����"ubvaw"
���ͣ���ʾ������ 24 �ֽ��������ֻ���滻�� "v" �� "w" ��������ĿҪ����Ϊ "ubvvw" �� "ubvww" �����������ظ����ַ���
ʾ�� 3��

���룺s = "j?qg??b"
�����"jaqgacb"
ʾ�� 4��

���룺s = "??yw?ipkj?"
�����"acywaipkja"
?

��ʾ��

1 <= s.length?<= 100

s ������СдӢ����ĸ�� '?' �ַ�


class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        string ans(s);

        for(int i = 0; i < s.size(); i++) {
            if(ans[i] >= 'a' && ans[i] <= 'z')
                continue;
            //s[i] == '?'
            ans[i] = check(ans,i,n);
        } 

        return ans;
    }

    char check(string& s,int cur,int n) {
        char pre = '\0';
        char next = '\0';
        if(cur != 0) {
            pre = s[cur-1];
        }

        if(cur != n-1) {
            next = s[cur+1];
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(ch != pre && ch != next) {
                return ch;
            }
        }
    
        return '\0';
    }
};
