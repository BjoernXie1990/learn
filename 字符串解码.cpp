//����һ������������ַ������������������ַ�����

//�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������

//�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�

//���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻�������?3a?��?2[4]?�����롣

//ʾ��:

//s = "3[a]2[bc]", ���� "aaabcbc".
//s = "3[a2[c]]", ���� "accaccacc".
//s = "2[abc]3[cd]ef", ���� "abcabccdcdcdef".

class Solution {
public:
    
    string decodeString(string s) {
        int len = s.size();
        string ret = "";

        for(int i = 0; i < len; i++)
        {
            if(s[i]<='9' && s[i]>='0')
                ret += dfs(s,len,i); //ÿһ��������ȡ�ظ����ַ���
            else ret += s[i];
        }

        return ret;
    }

    string dfs(string& s, int len, int& i)
    {
        if(i >= len) return "";
        string ret = "";

        while(i < len)
        {
            if(s[i]<='9' && s[i]>='0')
            {
                //��ȡ���ֲ��֣���ȡ֮��i��λ���� ���ֺ��� [ ��λ��
                int count = ToNum(s,i);
                i++;//������� [
                string tmp = dfs(s,len,i);
                ret += connect(tmp,count);//������ظ��ַ���ƴ��
            }
            else if(s[i] == ']')
                return ret;
            else 
                ret += s[i];
            
            i++;
        }

        return ret;
    }

    string connect(string& tmp,int count)
    {
        string ret = "";
        for(int i = 0; i < count; i++)
            ret += tmp;
        return ret;
    }

    int ToNum(string& s,int& index)
    {
        int num = 0;
        while(s[index] != '[')
            num = num * 10 + s[index++]-'0';

        return num;
    }
};
