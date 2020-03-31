//����һ���ַ��� s�������ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ���
//�ҵ������ؿ��������ַ�ʽת������̻��Ĵ���

//ʾ��?1:

//����: "aacecaaa"
//���: "aaacecaaa"
//ʾ�� 2:

//����: "abcd"
//���: "dcbabcd"




class Solution {
public:
    //������
    string shortestPalindrome1(string s) {
        int len = s.size();
        string src(s);//��������
        reverse(src.begin(),src.end()); //����һ�ݿ������ַ���

        for(int i = 0; i < len; i++)
        {
            if(s.substr(0,len - i) == src.substr(i))
                return src.substr(0,i) + s;
        }

        //������forѭ���оͻ���ֹ������return �ų����ַ��������
        return "";
    }

    //�ݹ�
    string shortestPalindrome2(string s) {
        int len = s.size();
        
        int left = 0;
        int right = len - 1;
        for(; right >= 0; right--)
        {
            //�ҵ�������ַ�ƥ����ַ�
            if(s[left] == s[right])
                left++;
        }
        //�����ߺ��ұ���ȫƥ�䣬���ǻ����ַ���
        if(left == len)
            return s;

        //�����ƥ�䣬˵�� [left,len) ���ַ������ǲ����ʵ�
        string src = s.substr(left,len);
        reverse(src.begin(),src.end());
        return src + shortestPalindrome2(s.substr(0,left)) + s.substr(left);
    }

    //KMP�㷨
    string shortestPalindrome(string s) {
        int len = s.size();
        string src(s);
        reverse(src.begin(),src.end());
        string s_new = s + '#' + src; //'#'�ַ������������ַ��� "abc" --> abc # cba

        int new_len = s_new.size();
        vector<int> arr(new_len,0);

        for(int i = 1; i < new_len; i++)
        {
            int t = arr[i-1];
            //��������ַ�����ȣ����ҹ���ǰ׺�ĺ�׺����
            while(t > 0 && s_new[i] != s_new[t])
                t = arr[t-1];
            //��һ������λ�þ��ǣ�����ǰ׺�ĳ��� + 1
            if(s_new[i] == s_new[t])
                t++;
            arr[i] = t;
        }

        return src.substr(0, len - arr[new_len-1]) + s;
    }
};
