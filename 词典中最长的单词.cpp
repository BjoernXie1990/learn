//����һ���ַ�������words��ɵ�һ��Ӣ��ʵ䡣�����ҳ����һ�����ʣ��õ�������words�ʵ����������������һ����ĸ��ɡ��������ж�����еĴ𰸣��򷵻ش����ֵ�����С�ĵ��ʡ�

//���޴𰸣��򷵻ؿ��ַ�����

//ʾ�� 1:

//����: 
//words = ["w","wo","wor","worl", "world"]
//���: "world"
//����: 
//����"world"����"w", "wo", "wor", �� "worl"���һ����ĸ��ɡ�
//ʾ�� 2:

//����: 
//words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
//���: "apple"
//����: 
//"apply"��"apple"�����ɴʵ��еĵ�����ɡ�����"apple"���ֵ���С��"apply"��
//ע��:

//����������ַ�����ֻ����Сд��ĸ��
//words���鳤�ȷ�ΧΪ[1,1000]��
//words[i]�ĳ��ȷ�ΧΪ[1,30]��


class Solution {
public:
    const static int N = 10010;
    int son[N][26];
    int idx;
    string key[N];

    string longestWord(vector<string>& words) {
        for(auto& eoch : words) insert(eoch);

        string ret = "";
        int len = 0;

        for(auto& eoch : words)
        {
            int num = Find(eoch);
            //�жϵ�ǰ�ַ��Ƿ�����ǰ�����ĸ��ÿ�ζ�һ����ɵ�
            //word -->  w + wo + wor + word
            if(num != eoch.size()) continue;

            //�����ɵĵ��ʴ��ڵ�ǰ���ʵĳ��ȣ�ֱ�Ӹ���
            if(num > len)
            {
                len = num;
                ret = eoch;
            }
            else if(num == len)//���ڣ�����Ҫ�ж��ֵ�����С
                ret = min(ret,eoch);
        }

        return ret;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = s;
    }

    int Find(string& s)
    {
        int p = 0;
        int num = 0;//ͳ��·�����ж��ٸ�����
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return num;
            p = son[p][u];
            if(key[p] != "") num++;
        } 
        return num;
    }
};
