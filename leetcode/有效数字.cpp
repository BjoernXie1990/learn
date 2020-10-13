class Solution {
public:
    vector<vector<int> > statu = 
        {
            { 0,  1,  2,  6, -1, -1},
            {-1, -1,  2,  6, -1, -1},
            {-1, -1, -1,  3, -1, -1},
            { 8, -1, -1,  3,  4, -1},
            {-1,  7, -1,  5, -1, -1},
            { 8, -1, -1,  5, -1, -1},
            { 8, -1,  3,  6,  4, -1},
            {-1, -1, -1,  5, -1, -1},
            { 8, -1, -1, -1, -1, -1}
        };

    bool isNumber(string s) {
        int st = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int idx = check(s[i]);
            st = statu[st][idx];
            if(st == -1) return false; 
        }

        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // �Ϸ�����ֹ״̬
        return finals[st];
    }

    int check(char& ch) {
        switch(ch) {
            case ' ':   return 0;
            case '+':
            case '-':   return 1;
            case '.':   return 2;
            case 'e':   return 4;
            default:
                if(ch >= '0' && ch <= '9') return 3;
        }

        return 5;
    }
};

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

