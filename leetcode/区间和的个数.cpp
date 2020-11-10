class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum{0};
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum.push_back(sum.back() + nums[i]);
        }

        return merge(sum,lower,upper,0,n);
    }

    int merge(vector<long>& sum,int lower,int upper,int left,int right) {
        if(left == right) return 0;

        int mid = (left + right) / 2;
        int n1 = merge(sum,lower,upper,left,mid);
        int n2 = merge(sum,lower,upper,mid+1,right);
        int ret = n1 + n2;

        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        while(i <= mid) {
            while(l <= right && sum[l] - sum[i] < lower) l++;
            while(r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }

        vector<long> tmp(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while(p1 <= mid || p2 <= right) {
            if(p1 > mid) tmp[p++] = sum[p2++];
            else if(p2 > right) tmp[p++] = sum[p1++];
            else if(sum[p1] <= sum[p2]) tmp[p++] = sum[p1++];
            else tmp[p++] = sum[p2++];
        }
        for(int i = 0; i < tmp.size(); i++) sum[left + i] = tmp[i];
        return ret;
    }
};


����һ����������?nums�������������?[lower, upper]?֮��ĸ���������?lower?��?upper��
�����?S(i, j)?��ʾ��?nums?�У�λ�ô�?i?��?j?��Ԫ��֮�ͣ�����?i?��?j?(i �� j)��

˵��:
��ֱ�۵��㷨���Ӷ���?O(n2) �����ڴ˻������Ż�����㷨��

ʾ��:

����: nums = [-2,5,-1], lower = -2, upper = 2,
���: 3 
����: 3������ֱ���: [0,0], [2,2], [0,2]�����Ǳ�ʾ�ĺͷֱ�Ϊ: -2, -1, 2��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-of-range-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
