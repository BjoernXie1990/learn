����һ������ n������ÿ����λ��ӵ㣨�� "." ���ţ���Ϊǧλ�ָ���������������ַ�����ʽ���ء�

 

ʾ�� 1��

���룺n = 987
�����"987"
ʾ�� 2��

���룺n = 1234
�����"1.234"
ʾ�� 3��

���룺n = 123456789
�����"123.456.789"
ʾ�� 4��

���룺n = 0
�����"0"
 

��ʾ��

0 <= n < 2^31

class Solution {
public:
    string thousandSeparator(int n) {
        string ans = to_string(n);
        
        string ret = "";
        int f = 0;
        for(int i = ans.size()-1; i >= 0; i--){
            
            if(f == 3){
                ret += '.';
                f = 0;
            }
            ret += ans[i];f++;
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
