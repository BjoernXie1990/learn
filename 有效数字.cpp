
��֤�������ַ����Ƿ���Խ���Ϊʮ�������֡�

����:

"0"?=>?true
" 0.1 "?=>?true
"abc"?=>?false
"1 a"?=>?false
"2e10"?=>?true
" -90e3? ?"?=>?true
" 1e"?=>?false
"e3"?=>?false
" 6e-1"?=>?true
" 99e2.5?"?=>?false
"53.5e93"?=>?true
" --6 "?=>?false
"-+3"?=>?false
"95a54e53"?=>?false

˵��:?�������⽫��������رȽ�ģ������ʵ�ִ���֮ǰ����Ӧ������˼�����п��ܵ�������������һ�ݿ��ܴ�������Чʮ���������е��ַ��б�

���� 0-9
ָ�� - "e"
��/���� - "+"/"-"
С���� - "."
��Ȼ���������У���Щ�ַ���������Ҳ����Ҫ��

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();

        if(len == 0)    return false;
        int p = 0;
        //ȥ��ǰ��ո�
        while(p < len && s[p] == ' ' )  p++;
        while(len > 0 && s[len-1] == ' ')  len--;
        if(len - 1 < p) return false;
        
        //��һ��������
        if(s[p] == '-' || s[p] == '+') p++;

        //��һ��e
        int idx = s.find('e',p);
        if(idx == len || idx == p) return false;    //"e9"  "9e"
        if(idx != -1)
        {
            int n = idx + 1;
            if(s[n] == '-' || s[n] == '+') n++;
            if(n == len)    return false;
            for(int i = n; i < len; i++)
                if(s[i] < '0' || s[i] > '9')    return false;
        }

        idx = (idx == -1) ? len : idx;//��ֹ idx=-1 Ҳ����û�� e �����
        int flag = true;
        if(s[p] == '.')
        {
            p++;
            if(p < idx) //".1"
                flag = false;
            else
                return false;
        }  

        //e֮ǰ�������Ƿ�Ϸ�
        while(p < idx)
        {
            if(s[p] == '.' && flag)
            {
                flag = false;
                p++;
                continue;
            }
            if(s[p] < '0' || s[p] > '9')    return false;
            p++;
        } 
        return true;
    }
};
