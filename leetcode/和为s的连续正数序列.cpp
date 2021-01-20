class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        unordered_map<long long,int> mp;
        mp[0] = 0;
        vector<vector<int> > res;
        long long sum = 0;
        for(int i = 1; i < target; i++) {
            sum += i;
            // f[i] - f[j] = target
            if(mp.count(sum - target)) {
                int j = mp[sum - target];
                vector<int> t;
                while(j < i) t.push_back(++j);
                res.push_back(t);
            }
            mp[sum] = i;
        }

        return res;
    }
};

����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������

�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�

?

ʾ�� 1��

���룺target = 9
�����[[2,3,4],[4,5]]
ʾ�� 2��

���룺target = 15
�����[[1,2,3,4,5],[4,5,6],[7,8]]
?

���ƣ�

1 <= target <= 10^5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
