����һ������?n, ���ش�?1?��?n?���ֵ�˳��

���磬

���� n =1 3������ [1,10,11,12,13,2,3,4,5,6,7,8,9] ��

�뾡���ܵ��Ż��㷨��ʱ�临�ӶȺͿռ临�Ӷȡ� ���������?n?С�ڵ���?5,000,000

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            dfs(ans,i,n);
        return ans;
    }

    void dfs(vector<int>& ans,int cur, int n)
    {
        if(cur > n) return ;
        ans.push_back(cur);
        cur *= 10;
        for(int i = 0; i <= 9; i++)
            dfs(ans,cur+i,n);
    }
};
