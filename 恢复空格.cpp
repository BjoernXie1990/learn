Ŷ�������㲻С�İ�һ����ƪ�����еĿո񡢱�㶼ɾ���ˣ����Ҵ�дҲŪ����Сд�������"I reset the computer. It still didn��t boot!"�Ѿ������"iresetthecomputeritstilldidntboot"���ڴ�������źʹ�Сд֮ǰ������Ȱ����ϳɴ����Ȼ�ˣ�����һ�����Ĵʵ�dictionary����������Щ��û�ڴʵ������������sentence��ʾ�����һ���㷨�������¶Ͽ���Ҫ��δʶ����ַ����٣�����δʶ����ַ�����

ע�⣺�������ԭ�������Ķ���ֻ�践��δʶ����ַ���

?

ʾ����

���룺
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
����� 7
���ͣ� �Ͼ��Ϊ"jess looked just like tim her brother"����7��δʶ���ַ���
��ʾ��

0 <= len(sentence) <= 1000
dictionary�����ַ��������� 150000��
�������Ϊdictionary��sentence��ֻ����Сд��ĸ��


class Solution {
public:
    static const int N = 150010;
    int son[N][26];
    int idx = 0;
    bool key[N];
    //�ֵ��� + ����
    int respace1(vector<string>& dictionary, string sentence) {
        for(auto& word : dictionary)
            insert(word);
        int ans = INT_MAX;

        dfs(sentence,0,0,ans);

        return ans==INT_MAX ? 0 : ans;
    }

    void dfs(string& str,int index, int len,int& ans)
    {
        for(int i = index; i < str.size(); i++)
        {
            vector<int> tmp = search(str,i);
            if(tmp.size() != 0)
            {
                for(int i = tmp.size() - 1; i >= 0; i--)
                    dfs(str,tmp[i],len,ans);
                return;
            }
            len++;//δʶ���ַ��� + 1
        }

        ans = min(len,ans);
    }

    //�ֵ��� +��̬�滮
    int respace(vector<string>& dictionary, string sentence) {
        for(auto& word : dictionary)
            insert(word);
        
        int len = sentence.size();
        vector<int> dp(len+1,0);

        for(int i = 1; i <= len; i++)
        {
            dp[i] = dp[i-1] + 1;
            int p = 0;
            for(int j = i; j >= 1; j--)
            {
                int v = sentence[j - 1] - 'a';
                if(son[p][v] == 0)
                {
                    dp[i] = min(dp[i],dp[j-1] + i-j+1);
                    break;
                }
                p = son[p][v];
                //son[p][v] == 1
                if(key[p] == true)//�ǿ���ƥ������һ������
                    dp[i] = min(dp[i],dp[j-1]);
                else
                    dp[i] = min(dp[i],dp[j-1] + i - j + 1);
            }
        }
        return dp[len];
    }

    vector<int> search(string& str,int index)
    {
        int p = 0;
        vector<int> ret;
        for(int i = index; i < str.size(); i++)
        {
            int v = str[i] - 'a';
            if(son[p][v] == 0)  break;
            p = son[p][v];
            if(key[p] == true) ret.push_back(i+1);//������ index ���ʿ�ͷ���� i ���ʽ�β����һ�Ӳ�ѯλ��
        }
        
        return ret;
    }

    void insert(string& str)
    {
        int p = 0;
        for(int i = str.size() - 1; i >= 0; i--)
        {
            int v = str[i] - 'a';
            if(son[p][v] == 0)  son[p][v] = ++idx;
            p = son[p][v];
        }
        key[p] = true;
    }

    //��̬�滮
    int respace2(vector<string>& dictionary, string sentence)
    {
        unordered_set<string> set(dictionary.begin(),dictionary.end());
        int len = sentence.size();
        vector<int> dp(len + 1,0);

        for(int i = 1; i <= len; i++)
        {
            dp[i] = dp[i-1] + 1;//���赱ǰ�ַ������ֵ���
            for(int j = 0; j < i; j++)
                if(set.find(sentence.substr(j,i-j)) != set.end())
                    dp[i] = min(dp[i],dp[j]);
        }
        return dp[len];
    }
};
