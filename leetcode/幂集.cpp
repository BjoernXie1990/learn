class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back({});

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int m = res.size();
            for(int j = 0; j < m; j++) {
                vector<int> t = res[j];
                t.push_back(nums[i]);
                res.push_back(move(t));
            }
        }

        return res;
    }
};

�ݼ�����дһ�ַ���������ĳ���ϵ������Ӽ��������в������ظ���Ԫ�ء�

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

 ���룺 nums = [1,2,3]
 �����
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
���ӣ�https://leetcode-cn.com/problems/power-set-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
