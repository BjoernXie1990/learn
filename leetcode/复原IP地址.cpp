����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

��Ч�� IP ��ַ�������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ�������֮���� '.' �ָ���

?

ʾ��:

����: "25525511135"
���: ["255.255.11.135", "255.255.111.35"]


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        dfs(s,0,"",ans,0);

        return ans;
    }

    void dfs(string& s,int idx,string&& cur,vector<string>& ans,int cnt)
    {
        if(idx == s.size() && cnt == 4)
        {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }

        if(cnt >= 4) return ;

        int num = 0;
        int p = idx;
        int sum = 0;
        while(num <= 255 && p < s.size())
        {
            num = num * 10 + s[p++]-'0';
            if(num < sum)  break;
            sum = (sum == 0) ? 10 : sum * 10;
            if(num <= 255)
                dfs(s,p,cur + to_string(num) + '.',ans,cnt+1);
        }
    }
};
