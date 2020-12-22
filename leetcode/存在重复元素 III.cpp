class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            auto it = st.lower_bound((long)(nums[i]) - t); // *it >= nums[i] - t
            if(it != st.end() && (abs(nums[i] - *it) <= t)) 
                return true;
            
            st.insert(nums[i]);
            if(st.size() > k)
                st.erase(nums[i-k]);
        }

        return false;
    }
};

���������� nums �У��Ƿ���������±� i �� j��ʹ��?nums [i] ��?nums [j]?�Ĳ�ľ���ֵС�ڵ��� t �������� i �� j �Ĳ�ľ���ֵҲС�ڵ��� ? ��

��������򷵻� true�������ڷ��� false��

?

ʾ��?1:

����: nums = [1,2,3,1], k = 3, t = 0
���: true
ʾ�� 2:

����: nums = [1,0,1,1], k = 1, t = 2
���: true
ʾ�� 3:

����: nums = [1,5,9,1,5,9], k = 2, t = 3
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/contains-duplicate-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
