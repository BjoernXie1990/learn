//����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

//?

//ʾ�� 1��

//����: "the sky is blue"
//���:?"blue is sky the"
//ʾ�� 2��

//����: " ?hello world! ?"
//���:?"world! hello"
//����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
//ʾ�� 3��

//����: "a good ? example"
//���:?"example good a"
//����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����

class Solution {
public:
    string reverseWords(string s) {
        //�����ַ���
        reverse(s.begin(),s.end());
        int start = 0;
        int lenWord = 0;//��ת���ʳ���
        int len = s.size();
        int i = 0;
        //�ų�ǰ��Ŀո�
        while(i < len && s[i] == ' ')
            i++;

        for(; i < len; i++)
        {
            if(s[i] != ' ')
            {
                lenWord++;
                continue;
            }
               
            //�ҵ�һ���ո�,���ô�start����λ�õĵ���
            reverse(&s[start],&s[i]);
            start += lenWord + 1;
            lenWord = 0;
            int flag = 0;
            //�������һ�����ǿո����ĸ
            while(i < len && s[i] == ' ')
            {
                i++;
                flag = 1;
            }
            if(flag)
                i--;
        }
        reverse(&s[start],&s[len]);
        //ȥ������Ŀո�
        while(i>0 &&  s[i-1] == ' ')
        {
            s[i-1] = '\0';
            i--;
        }
        return s;
    }
};
