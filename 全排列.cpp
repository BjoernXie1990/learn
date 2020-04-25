//����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

//ʾ��:

//����: [1,2,3]
//���:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]



class Solution {
public:
    int len;
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp(len);
        vector<int> visit(len);
        dfs(nums,ans,visit,tmp,0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int> >& ans, vector<int>& visit,vector<int>& tmp, int index){
        if(index == len){
            vector<int> ret = tmp;
            ans.push_back(ret);
            return ;
        }

        for(int i = 0; i < len; i++){
            if(!visit[i]){
                visit[i] = 1;
                tmp[index] = nums[i];
                dfs(nums,ans,visit,tmp,index+1);
                visit[i] = 0;
            }
        }
    }
};
