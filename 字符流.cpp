//������Ҫ��ʵ�� StreamChecker �ࣺ

//StreamChecker(words)�����캯�����ø������ִʳ�ʼ�����ݽṹ��
//query(letter)���������ĳЩ k >= 1�������ò�ѯ����� k���ַ������Ӿɵ���˳�򣬰����ող�ѯ����ĸ��ƴд�������ִʱ��е�ĳһ�ִ�ʱ������ true�����򣬷��� false��
//?

//ʾ����

//StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // ��ʼ���ֵ�
//streamChecker.query('a');          // ���� false
//streamChecker.query('b');          // ���� false
//streamChecker.query('c');          // ���� false
//streamChecker.query('d');          // ���� true����Ϊ 'cd' ���ִʱ���
//streamChecker.query('e');          // ���� false
//streamChecker.query('f');          // ���� true����Ϊ 'f' ���ִʱ���
//streamChecker.query('g');          // ���� false
//streamChecker.query('h');          // ���� false
//streamChecker.query('i');          // ���� false
//streamChecker.query('j');          // ���� false
//streamChecker.query('k');          // ���� false
//streamChecker.query('l');          // ���� true����Ϊ 'kl' ���ִʱ��С�
//?

//��ʾ��

//1 <= words.length <= 2000
//1 <= words[i].length <= 2000
//�ִ�ֻ����СдӢ����ĸ��
//������ֻ����СдӢ����ĸ��
//��������� 40000 ����


class StreamChecker {
public:
    const static int N = 50000;
    int son[N][26];
    int idx;
    string key[N];
    string str; 
    StreamChecker(vector<string>& words) {
        idx = 0;
        memset(son,0,sizeof(son));
        str = "";
        for(auto& eoch : words)
            insert(eoch);
    }

    void insert(string& words)
    {
        int p = 0;
        int len = words.size();
        for(int i = len - 1; i >= 0; i--)
        {
            int u = words[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = words;
    }
    
    bool query(char letter) {
        str += letter;
        int p = 0;
        int len = str.size();
        for(int i = len -1; i >= 0 ; i--)
        {
            int u = str[i] - 'a';
            if(!son[p][u]) break;

            p = son[p][u];
            if(key[p] != "") return true;
        }
        return false;
    }
};
