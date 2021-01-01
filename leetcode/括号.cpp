class Solution {
public:
    vector<string> ans;
    string s;
    vector<string> generateParenthesis(int n) {
        s.reserve(n*2);
        dfs(n,n);
        return ans;
    }

    void dfs(int le,int ri) {
        if(le > ri) return;
        if(le == 0 && ri == 0) {
            ans.push_back(s);
            return ;
        }

        if(le) {
            s += '(';
            dfs(le - 1,ri);
            s.pop_back();
        }
            
        if(ri) {
            s += ')';
            dfs(le , ri - 1);
            s.pop_back();
        }
    }
};


���š����һ���㷨����ӡn�����ŵ����кϷ��ģ����磬����һһ��Ӧ����ϡ�

˵�����⼯���ܰ����ظ����Ӽ���

���磬����?n = 3�����ɽ��Ϊ��

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/bracket-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
