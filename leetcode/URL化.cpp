URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ%20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ���ע����Javaʵ�ֵĻ�����ʹ���ַ�����ʵ�֣��Ա�ֱ���������ϲ�������

ʾ��1:

 ���룺"Mr John Smith    ", 13
 �����"Mr%20John%20Smith"
ʾ��2:

 ���룺"               ", 5
 �����"%20%20%20%20%20"
��ʾ��

�ַ���������[0, 500000]��Χ�ڡ�
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ans("");
        for(int i = 0; i < length; i++) {
            if(S[i]==' ')
                ans += "%20";
            else
                ans += S[i];
        }
        return ans;
    }
};
