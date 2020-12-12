class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        ans.push_back({});
        int n = nums.size();

        int pre = 1;
        for(int i = 0; i < n; i++) {
            int m = ans.size();
            if(i && nums[i] != nums[i - 1]) pre = m;

            for(int j = m - pre; j < m; j++) {
                
               vector<int> t = ans[j];
               t.push_back(nums[i]); 
               ans.push_back(t);
            }
        }

        return ans;
    }
};


����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: [1,2,2]
���:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/subsets-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
