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
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(1,0,k,n,tmp);
        return ans;
    }

    void dfs(int idx,int sum,int k,int n,vector<int>& tmp) {
        if(sum == n && tmp.size() == k) {
            ans.push_back(tmp);
            return ;
        }
        if (sum > n || tmp.size() > k) 
            return ;

        for(int i = idx; i <= 9; i++) {
            tmp.push_back(i);
            dfs(i + 1, sum + i,k,n,tmp);
            tmp.pop_back();
        }
    }
};
