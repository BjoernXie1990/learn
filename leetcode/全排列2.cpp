����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ��:

����: [1,1,2]
���:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutations-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    vector<vector<int> > ans;
    vector<int> tmp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        dfs(nums,0,n);

        return ans;
    }

    void dfs(vector<int>& nums,int idx,int n) {
        if(idx == n) {
            ans.push_back(tmp);
            return ;
        }

        int pre = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0x3f3f3f3f || nums[i] == pre) continue;
            pre = nums[i];
            tmp.push_back(nums[i]);
            nums[i] = 0x3f3f3f3f;
            
            dfs(nums,idx+1,n);

            tmp.pop_back();
            nums[i] = pre;
        }
    }
};
