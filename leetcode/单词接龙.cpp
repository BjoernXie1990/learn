class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(),wordList.end());
        if(hash.find(endWord) == hash.end()) return 0;

        queue<string> que;
        que.push(beginWord);
        
        int ans = 0;
        while(!que.empty()) {
            int size = que.size();
            ans ++;
            while(size --) {
                string f = que.front();
                que.pop();

                for(int i = 0; i < f.size(); i++) {
                    int ch = f[i];
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(j == ch) continue;
                        f[i] = j;
                        if(hash.find(f) == hash.end()) continue;
                        if(f == endWord) {
                            //cout << f << endl;
                            return ans + 1;
                        }
                        que.push(f);
                        hash.erase(f);
                    }
                    f[i] = ch;
                }
            }
        }

        return 0;
    }
};


�����������ʣ�beginWord?�� endWord����һ���ֵ䣬�ҵ���?beginWord ��?endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У����� 0��
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
ʾ��?1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���: 5

����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     �������ĳ��� 5��
ʾ�� 2:

����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

���:?0

����:?endWord "cog" �����ֵ��У������޷�����ת����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-ladder
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
