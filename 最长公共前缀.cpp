��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ���?""��

ʾ��?1:

����: ["flower","flow","flight"]
���: "fl"
ʾ��?2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ?a-z?��


class Solution {
public:
    //��������
    const static int N = 100010;
    int son[N][26] = {0};
    int idx = 0;
    string longestCommonPrefix1(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";

        insert(strs[0]);

        int ans = strs[0].size();
        for(int i = 1; i < len; i++)
        {
            ans = min(ans,search(strs[i]));
            if(ans == 0)    return "";
        }
            
        
        return strs[0].substr(0,ans);
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u])  son[p][u] = ++idx;
            p = son[p][u];
       }
    }

    int search(string& s)
    {
        int p = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u])  return ans;
            p = son[p][u];
            ans++;
        }
        return ans;
    }

    //��������
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";


        int ans = strs[0].size();
        int ret = 0;
        for(int i = 0; i < ans; i++)
        {
            for(int j = 1; j < len; j++)
                if(strs[j][i] != strs[0][i])    return strs[0].substr(0,ret);

            ret++;
        }

        return strs[0];
    }

};
