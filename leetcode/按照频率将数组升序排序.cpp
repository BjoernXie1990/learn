class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> hash;    // ͳ�Ƴ��ִ���
        for(auto& n : nums) hash[n]++;

        sort(nums.begin(),nums.end(),[&](const int a,const int b)->bool{
            int le = hash[a], ri = hash[b];
            return (le != ri) ? le < ri : a > b;
        });

        return nums;
        // unordered_map<int,int> hash;
        // for(auto& num : nums)   hash[num]++;
        
        // vector<int> ans;
        // int len = 1;
        // for(int i = 1; i <= 100; i++) {
        //     vector<int> t;
        //     for(auto& eoch : hash)  if(eoch.second == i) t.push_back(eoch.first);
            
        //     sort(t.begin(),t.end(),[](const int& a,const int& b)->bool{
        //         return a > b;
        //     });
            
        //     for(auto& n : t)
        //         for(int j = 0; j < i; j++)  ans.push_back(n);
        // }
        
        // return ans;
    }
};
����һ����������?nums?�����㽫���鰴��ÿ��ֵ��Ƶ�� ���� ��������ж��ֵ��Ƶ����ͬ�����㰴����ֵ�������� ���� ����?

���㷵�����������顣

?

ʾ�� 1��

���룺nums = [1,1,2,2,2,3]
�����[3,1,1,2,2,2]
���ͣ�'3' Ƶ��Ϊ 1��'1' Ƶ��Ϊ 2��'2' Ƶ��Ϊ 3 ��
ʾ�� 2��

���룺nums = [2,3,1,3,2]
�����[1,3,3,2,2]
���ͣ�'2' �� '3' Ƶ�ʶ�Ϊ 2 ����������֮�䰴����ֵ����������
ʾ�� 3��

���룺nums = [-1,1,-6,4,5,-6,1,4,1]
�����[5,-1,4,4,-6,-6,1,1,1]
?

��ʾ��

1 <= nums.length <= 100
-100 <= nums[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sort-array-by-increasing-frequency
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
