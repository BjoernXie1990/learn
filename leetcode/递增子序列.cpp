����һ����������, ����������ҵ����и�����ĵ��������У����������еĳ���������2��

ʾ��:

����: [4, 6, 7, 7]
���: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
˵��:

��������ĳ��Ȳ��ᳬ��15��
�����е�������Χ��?[-100,100]��
���������п��ܰ����ظ����֣���ȵ�����Ӧ�ñ���Ϊ������һ�������

class Solution {
public:
    int n = 0;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> tmp;
        set<vector<int> > ans;
        dfs(ans,0,nums,tmp);

        return vector<vector<int> > (ans.begin(),ans.end());
    }

    void dfs(set<vector<int> >& ans,int idx,vector<int>& nums,vector<int>& tmp){
        if(tmp.size() > 1) ans.insert(tmp);
        if(idx >= n)    return;

        int pre = (tmp.size() == 0) ?  INT_MIN : tmp.back();
        for(int i = idx; i < n; i++){
            tmp.push_back(nums[i]);

            if(tmp.back() >= pre)
                dfs(ans,i+1,nums,tmp);

            tmp.pop_back();
        }
    }
};
