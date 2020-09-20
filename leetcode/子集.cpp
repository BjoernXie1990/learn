class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int m = ans.size();
            for(int j = 0; j < m; j++) {
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
            ans.push_back({nums[i]});
        }
        ans.push_back({});

        return ans;
    }
};


����һ�鲻���ظ�Ԫ�ص���������?nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
[
  [3],
? [1],
? [2],
? [1,2,3],
? [1,3],
? [2,3],
? [1,2],
? []
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/subsets
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
