�ҳ��������֮��Ϊ?n ��?k?��������ϡ������ֻ������ 1 -?9 ��������������ÿ������в������ظ������֡�

˵����

�������ֶ�����������
�⼯���ܰ����ظ�����ϡ�?
ʾ�� 1:

����: k = 3, n = 7
���: [[1,2,4]]
ʾ�� 2:

����: k = 3, n = 9
���: [[1,2,6], [1,3,5], [2,3,4]]


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> tmp;
        dfs(1,k,n,tmp,ans);

        return ans;
    }

    void dfs(int idx,int k,int n,vector<int>& tmp,vector<vector<int> >& ans)
    {
        if(n == 0 && tmp.size() == k)
        {
            ans.push_back(tmp);
            return ;
        }
        else if(n < 0 || tmp.size() > k)
            return ;
        
        for(int i = idx; i <= n && i <= 9; i++)
        {
            tmp.push_back(i);
            dfs(i + 1,k,n - i,tmp,ans);
            tmp.pop_back();
        }
        
    }
};
