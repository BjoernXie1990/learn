//ʵ��һ�� Trie (ǰ׺��)������?insert,?search, ��?startsWith?������������

//ʾ��:

//Trie trie = new Trie();

//trie.insert("apple");
//trie.search("apple");   // ���� true
//trie.search("app");     // ���� false
//trie.startsWith("app"); // ���� true
//trie.insert("app");   
//trie.search("app");     // ���� true
//˵��:

//����Լ������е����붼����Сд��ĸ?a-z?���ɵġ�
//��֤���������Ϊ�ǿ��ַ�����



class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        idx = 0;
        memset(son,0,sizeof(son));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int u = word[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int u = word[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
            if(key[p] == word) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for(int i = 0; i < prefix.size(); i++)
        {
            int u = prefix[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }

private:
    const static int N = 100000;
    int son[N][26];
    int idx;
    string key[N];
};
