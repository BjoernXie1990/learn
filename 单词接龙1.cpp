//�����������ʣ�beginWord?�� endWord����һ���ֵ䣬�ҵ���?beginWord ��?endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���

//ÿ��ת��ֻ�ܸı�һ����ĸ��
//ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
//˵��:

//���������������ת�����У����� 0��
//���е��ʾ�����ͬ�ĳ��ȡ�
//���е���ֻ��Сд��ĸ��ɡ�
//�ֵ��в������ظ��ĵ��ʡ�
//����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
//ʾ��?1:

//����:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]

//���: 5

//����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     �������ĳ��� 5��
//ʾ�� 2:

//����:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]

//���:?0

//����:?endWord "cog" �����ֵ��У������޷�����ת����


class Solution {
public:
    const static int N = 100010;
    int son[N][26];
    string key[N];
    int idx;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> map_begin;
        //�����ֵ�����
        for(auto& eoch : wordList)
        {
            insert(eoch);
            map_begin[eoch] = 0;
            //map_end[eoch] = 0;
        }
        insert(beginWord);
        //endword�������ֵ���
        if(!Search(endWord)) return 0;
        
        int ans = 1;
        queue<string> que;
        que.push(beginWord);
        map_begin[beginWord] = 1;

        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                string str = que.front();
                que.pop();

                //�ҵ����ַ���һ�����Ա䵽�������ַ���
                vector<string> cur;
                Search_neighbors(str,cur);

                for(auto& eoch : cur)
                {
                    if(eoch == endWord)
                        return ans+1;
                    //��ֹ���ַ������ɻ�·
                    if(map_begin[eoch]) continue;
                    //cout<<eoch<<' ';
                    map_begin[eoch] = 1;
                    que.push(eoch);
                }
                //cout<<endl;
            }
            ans++;
        }

        return 0;
    }

    //�����ַ������ֵ�����
    void insert(string& str)
    {
        int p = 0;
        for(int i = 0; i < str.size(); i++)
        {
            int u = str[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = str;
    }

    //�Ӹ��ڵ��λ�ò���ָ���ַ���
    bool Search(string& str,int p = 0)
    {
        for(int i = 0; i < str.size(); i++)
        {
            int u = str[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];    
        }
        return true;
    }

    void Search_neighbors(string& str,vector<string>& arr)
    {
        int p = 0;
        for(int i = 0; i < str.size(); i++)
        {
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                //����ı䵱ǰiλ��Ϊch �󣬽ڵ�λ��û�и��ַ� ����˵�ı����ַ�������ƥ�䣬�ͼ�����һ��
                if(ch == str[i] || !son[p][ch-'a']) continue;
                string right = str.substr(i+1);
                if(!Search(right,son[p][ch-'a'])) continue;

                //������ַ������Ǹı��ƥ���
                string tmp = str;
                tmp[i] = ch;
                arr.push_back(tmp);
            }
            //������һ�θ��ڵ��λ��
            p = son[p][str[i]-'a'];
        }
    }
};
