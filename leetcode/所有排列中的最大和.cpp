class Solution {
public:
    const int mod = 1e9 + 7;
    struct comp {
        bool operator()(const int a,const int b) {
            return a > b;
        }
    };
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> arr(n+1,0);
        for(auto& eoch : requests) {
            arr[eoch[0]]++;
            arr[eoch[1]+1]--;
        }
        for(int i = 1; i < n; i++)  arr[i] += arr[i-1];
        comp com;//�Ӵ�С����
        sort(arr.begin(),arr.end(),com);
        sort(nums.begin(),nums.end(),com);

        long long ans = 0;
        int p = 0;
        for(int i = 0; arr[i] > 0; i++) ans += arr[i] * nums[p++];

        return ans % mod;
    }
};

��һ����������?nums?����һ����ѯ����?requests?������?requests[i] = [starti, endi]?����?i?����ѯ��?nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]?�Ľ��?��starti ��?endi?������������ �� 0 ��ʼ �ġ�

������������� nums?�е����֣����㷵�����в�ѯ���֮�͵����ֵ��

���ڴ𰸿��ܻ�ܴ����㽫����?109 + 7?ȡ��?�󷵻ء�

?

ʾ�� 1��

���룺nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
�����19
���ͣ�һ�����е� nums ����Ϊ [2,1,3,4,5]���������½����
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
�ܺ�Ϊ��8 + 3 = 11��
һ���ܺ͸��������Ϊ [3,5,4,2,1]���������½����
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
�ܺ�Ϊ�� 11 + 8 = 19��������������������в�ѯ֮�����Ľ����
ʾ�� 2��

���룺nums = [1,2,3,4,5,6], requests = [[0,1]]
�����11
���ͣ�һ���ܺ���������Ϊ [6,5,4,3,2,1] ����ѯ��Ϊ [11]��
ʾ�� 3��

���룺nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
�����47
���ͣ�һ������������Ϊ [4,10,5,3,2,1] ����ѯ����ֱ�Ϊ [19,18,10]��
?

��ʾ��

n == nums.length
1 <= n <= 105
0 <= nums[i]?<= 105
1 <= requests.length <=?105
requests[i].length == 2
0 <= starti?<= endi?<?n

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-sum-obtained-of-any-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
