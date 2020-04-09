//���� n?�����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�

//?

//ʾ����

//���룺n = 3
//�����[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string src;
        dfs(ans,src,n,n);
        return ans;
    }

    void dfs(vector<string>& ans,string src, int left,int right)
    {
        //��������ȫ��������
        if(left + right == 0)
        {
            ans.push_back(src);
            return;
        }

        //�ȼ�������
        if(left > 0)
            dfs(ans,src + '(',left-1,right);

        //��������ű������Ŷ࣬��������
        if(right > left)
            dfs(ans,src + ')',left,right-1);
       
    }
}
