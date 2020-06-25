����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict�����ַ��������ӿո�������һ�����ӣ�ʹ�þ��������еĵ��ʶ��ڴʵ��С�����������Щ���ܵľ��ӡ�

˵����

�ָ�ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��

����:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
���:
[
? "cats and dog",
? "cat sand dog"
]
ʾ�� 2��

����:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
���:
[
? "pine apple pen apple",
? "pineapple pen apple",
? "pine applepen apple"
]
����: ע��������ظ�ʹ���ֵ��еĵ��ʡ�
ʾ��?3��

����:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
���:
[]


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string> > m;

        return dfs(m,wordDict,s);
    }

    vector<string> dfs(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s)
    {
        if(m.count(s))  return m[s];
        if(s.empty())   return {""};

        vector<string> ans;
        for(auto& str : wordDict)
        {
            if(s.substr(0,str.size()) != str)   continue;
            
            //�Ӻ��ο�ʼ��������
            vector<string> tmp = dfs(m,wordDict,s.substr(str.size()));

            for(auto eoch : tmp)
                ans.push_back(str + (eoch.empty() ? "" : " ") + eoch);
        }
        m[s] = ans;
        return ans;
    }
};
