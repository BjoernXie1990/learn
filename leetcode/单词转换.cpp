class Solution {
public:
    vector<string> ans;
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> st;
        for(auto& s : wordList) st[s] = false;
        
        if(st.count(endWord) == 0) return ans;
        st.erase(beginWord);

        dfs(beginWord,endWord,st);

        return ans;
    }

    bool dfs(string& pre,string& endWord,unordered_map<string,bool>& st) {
        st[pre] = true;
        ans.push_back(pre);
        if(pre == endWord) {
            return true;
        }

        int n = pre.size();
        for(int i = 0; i < n; i++) {
            string t = pre;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                t[i] = ch;
                if(st.count(t) && st[t] == false)
                    if(dfs(t,endWord,st)) return true;
            }
        }
        ans.pop_back();
        return false;
    }
};
�����ֵ��е������ʣ�������ȡ�дһ����������һ����ת������һ���ʣ� ����һ��ֻ�ܸı�һ���ַ���ÿһ���õ����´ʶ����������ֵ����ҵ���

��дһ�����򣬷���һ�����ܵ�ת�����С����ж�����ܵ�ת�����У�����Է����κ�һ����

ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���:
["hit","hot","dot","lot","log","cog"]
ʾ�� 2:

����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

���: []

����:?endWord "cog" �����ֵ��У����Բ����ڷ���Ҫ���ת�����С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-transformer-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
