����һ�鵥��words����дһ�������ҳ����е�����ʣ��Ҹõ��������鵥���е�����������϶��ɡ����ж��������ͬ�Ľ�������������ֵ�����С��һ���û�з���Ҫ��ĵ����򷵻ؿ��ַ�����

ʾ����

���룺 ["cat","banana","dog","nana","walk","walker","dogwalker"]
����� "dogwalker"
���ͣ� "dogwalker"����"dog"��"walker"��ɡ�
��ʾ��

0 <= len(words) <= 100
1 <= len(words[i]) <= 100

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> map(words.begin(),words.end());
        sort(words.begin(),words.end(),cmp);

        for(auto& word : words)
        {
            map.erase(word);
            if(check(word,map))    return word;
            map.insert(word);
        }
        return "";
    }

    bool check(string str,unordered_set<string>& map)
    {
        if(str == "")   return true;

        for(int len = 1; len <= str.size(); len++)
        {
            string tmp = str.substr(0,len);
            if(map.find(tmp) != map.end() && check(str.substr(len),map))
                return true;
        }
        return false;
    }

    static bool cmp(const string& a,const string& b)
    {
        if(a.size() != b.size())
            return a.size() > b.size();
        return a < b;
    }
};
