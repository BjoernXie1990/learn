�����������ʣ�beginWord �� endWord����һ���ֵ� wordList���ҳ����д� beginWord �� endWord �����ת�����С�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У�����һ�����б�
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���:
[
  ["hit","hot","dot","dog","cog"],
? ["hit","hot","lot","log","cog"]
]
ʾ�� 2:

����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

���: []

����:?endWord "cog" �����ֵ��У����Բ����ڷ���Ҫ���ת�����С�




class Solution {
public:
    unordered_map<string,vector<string> > hash;
    vector<vector<string> > res;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //���е��ʲ����ֵ��У���ȥ��
        unordered_set<string> dirc(wordList.begin(),wordList.end());
        //��ֹĩβ���ʲ����ֵ���
        if(dirc.find(endWord) == dirc.end()) return res;

        //�ֱ��·�������˿�ʼ��ά��һ��˫�˵�·������ֹ���߹�������
        unordered_set<string> beginW{beginWord};//ʼ�ն����бȽ��ٵ���ʼ��
        unordered_set<string> endW{endWord};//���ڱȽ϶����ʼ��
        bool flag1 = false;
        bool flag2 = false;//true --> ά��һ�� to->from  false  --> ά��һ�� from-->to

        while(!beginW.empty())
        {
            unordered_set<string> tmp;

            for(auto& str : beginW) dirc.erase(str);

            for(auto& str : beginW)
                for(int i = 0; i < str.size(); i++)
                {
                    string s = str;
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        s[i] = ch;
                        //���û��ת����ĵ���
                        if(dirc.find(s) == dirc.end()) continue;

                        //�����ǰ�����ڽ�βset�г��֣�˵����ξ�����̵�·����
                        if(endW.find(s) != endW.end()) flag1 = true;
                        else tmp.insert(s);

                        flag2 ? hash[s].push_back(str) : hash[str].push_back(s);
                    }
                }

            //�Ѿ�������̶���
            if(flag1) break;

            if(tmp.size() <= endW.size())
                beginW = tmp;
            else
            {
                beginW = endW;
                endW = tmp;
                flag2 = !flag2;
            }
        }

        vector<string> ans;
        ans.push_back(beginWord);
        dfs(ans,beginWord,endWord);
        return res;
    }

    void dfs(vector<string>& ans,string& begin,string& end)
    {
        if(begin == end)
        {
            res.push_back(ans);
            return;
        }

        if(hash.find(begin) == hash.end()) return;

        for(auto& str : hash[begin])
        {
            ans.push_back(str);
            dfs(ans,str,end);
            ans.pop_back();
        }
    }

};
