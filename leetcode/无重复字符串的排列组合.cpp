class Solution {
public:
    vector<string> ans;

    vector<string> permutation(string S) {
        int n = S.size();
        dfs(S,0);

        return ans;
    }

    void dfs(string& s,int idx) {
        if(idx == s.size()) {
            ans.push_back(s);
            return ;
        }

        for(int i = idx; i < s.size(); i++) {
            swap(s[i],s[idx]);
            dfs(s,idx+1);
            swap(s[i],s[idx]);
        }
    }
};


���ظ��ַ�����������ϡ���дһ�ַ���������ĳ�ַ���������������ϣ��ַ���ÿ���ַ�������ͬ��

ʾ��1:

 ���룺S = "qwe"
 �����["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
ʾ��2:

 ���룺S = "ab"
 �����["ab", "ba"]
��ʾ:

�ַ�����Ӣ����ĸ��
�ַ���������[1, 9]֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutation-i-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
