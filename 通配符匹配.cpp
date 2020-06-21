����һ���ַ���?(s) ��һ���ַ�ģʽ?(p) ��ʵ��һ��֧��?'?'?��?'*'?��ͨ���ƥ�䡣

'?' ����ƥ���κε����ַ���
'*' ����ƥ�������ַ������������ַ�������
�����ַ�����ȫƥ�����ƥ��ɹ���

˵��:

s?����Ϊ�գ���ֻ������?a-z?��Сд��ĸ��
p?����Ϊ�գ���ֻ������?a-z?��Сд��ĸ���Լ��ַ�???��?*��
ʾ��?1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����
ʾ��?2:

����:
s = "aa"
p = "*"
���: true
����:?'*' ����ƥ�������ַ�����
ʾ��?3:

����:
s = "cb"
p = "?a"
���: false
����:?'?' ����ƥ�� 'c', ���ڶ��� 'a' �޷�ƥ�� 'b'��
ʾ��?4:

����:
s = "adceb"
p = "*a*b"
���: true
����:?��һ�� '*' ����ƥ����ַ���, �ڶ��� '*' ����ƥ���ַ��� "dce".
ʾ��?5:

����:
s = "acdcb"
p = "a*c?b"
���: false


//��̬�滮 
bool isMatch(char * s, char * p){
    int lens = strlen(s);
    int lenp = strlen(p);

    int i = 0;
    int j = 0;
    int** dp = (int**)malloc(sizeof(int*) * (lens + 1));
    for(i = 0; i <= lens; i++)
    {
        dp[i] = (int*)calloc((lenp + 1),sizeof(int));
    }

    dp[0][0] = true;
    for(i = 0; i < lenp; i++)
    {
        if(p[i] == '*')
        {
            dp[0][i+1] = true;
        }
        else
        {
            break;
        }
    }

    for(i = 1; i <= lens; i++)
    {
        for(j = 1; j <= lenp; j++)
        {
            if(p[j-1] == s[i-1] || p[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[lens][lenp];
}


class Solution {
public:
    //����
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        int idp = 0;
        int star = -1;//��һ�� *�ַ���λ��
        int k = 0;//��һ�� * �ַ�ƥ��s��λ��
        int ids = 0;

        while(ids < n)
        {
            if(s[ids] == p[idp] || p[idp] == '?')
            {
                idp++;
                ids++;
                continue;
            }

            if(p[idp] == '*')
            {
                star = idp++;
                k = ids;
                continue;
            }

            //���ݵ���һ�� * ��λ��
            if(star != -1)
            {
                ids = ++k;
                idp = star + 1;
                continue;
            }
            return false;
        }

        //��ֹ p�ַ�������ȫ��*�����
        while(idp < m && p[idp] == '*')
            idp++;
        return idp == m;
    }
};
