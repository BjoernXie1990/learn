����һ���ַ�������ӡ�����ַ������ַ����������С�

?

�����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�

?

ʾ��:

���룺s = "abc"
�����["abc","acb","bac","bca","cab","cba"]
?


class Solution {
public:
    int len;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        len = s.size();

        vector<string> ans;
        dfs(s,0,ans);
        return ans;
    }

    void dfs(string& s,int idx,vector<string>& ans)
    {
        if(idx == len - 1)
        {
            ans.push_back(s);
            return;
        }

        //����������
        for(int i = idx; i < len; i++)
        {
            if(check(s,idx,i))  continue;

            swap(s[i],s[idx]);
            dfs(s,idx+1,ans);
            swap(s[i],s[idx]);
        }

        // for(int i = idx; i < len; i++)
        // {
        //     //��������������ʹ������
        //     if(i != idx && s[i] == s[idx])  continue;

        //     swap(s[i],s[idx]);
        //     dfs(s,idx+1,ans);
        // }
    }

    bool check(string& s,int start,int end)
    {
        for(int i = start; i < end; i++)
            if(s[i] == s[end])  return true;
        return false;
    }
};
