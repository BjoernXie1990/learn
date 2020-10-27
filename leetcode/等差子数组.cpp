���һ����������������Ԫ����ɣ���ÿ��������Ԫ��֮��Ĳ�ֵ����ͬ����ô������о��� �Ȳ����� ������ʽ�أ����� s �ǵȲ����У�ֻ��Ҫ���㣺����ÿ����Ч�� i �� s[i+1] - s[i] == s[1] - s[0] ��������

���磬������Щ���� �Ȳ����� ��

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
��������� ���ǵȲ����� ��

1, 1, 2, 5, 7
����һ���� n ��������ɵ����� nums���������� m ��������ɵ����� l �� r�������������ʾ m �鷶Χ��ѯ�����е� i ����ѯ��Ӧ��Χ [l[i], r[i]] ������������±궼�� �� 0 ��ʼ �ġ�

���� boolean Ԫ�ع��ɵĴ��б� answer ����������� nums[l[i]], nums[l[i]+1], ... , nums[r[i]] ���� �������� �γ� �Ȳ����� ��answer[i] ��ֵ���� true������answer[i] ��ֵ���� false ��

?

ʾ�� 1��

���룺nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
�����[true,false,true]
���ͣ�
�� 0 ����ѯ����Ӧ������ [4,6,5] ��������������Ϊ�Ȳ����� [6,5,4] ��
�� 1 ����ѯ����Ӧ������ [4,6,5,9] ���޷����������γɵȲ����С�
�� 2 ����ѯ����Ӧ������ [5,9,3,7] ��������������Ϊ�Ȳ����� [3,5,7,9] ��
ʾ�� 2��

���룺nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
�����[false,true,false,false,true,true]
?

��ʾ��

n == nums.length
m == l.length
m == r.length
2 <= n <= 500
1 <= m <= 500
0 <= l[i] < r[i] < n
-105 <= nums[i] <= 105

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/arithmetic-subarrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        
        vector<bool> ans(m,false);
        
        for(int i = 0; i < m; i++) {
            vector<int> arr;
            for(int j = l[i]; j <= r[i]; j++) arr.push_back(nums[j]);
            sort(arr.begin(),arr.end());
            
            int d = arr[1] - arr[0];
            bool flag = true;
            for(int j = 2; j < arr.size() && flag; j++) if(arr[j] - arr[j-1] != d) flag = false;
            if(flag) ans[i] = true;
        }
        
        return ans;
    }
};
