class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i = 1; i < nums.size(); i+=2) {
        //     swap(nums[i],nums[i-1]);
        // }

        int n = nums.size();
        // 0 ��  1 ��   
        for(int i = 1; i < n; i ++) {
            if(i & 1) {
                // ��
                if(nums[i] > nums[i-1]) swap(nums[i],nums[i-1]);
            } else {
                // ��
                if(nums[i] < nums[i-1]) swap(nums[i],nums[i-1]);
            }
        }
    }
};

��һ�����������У����塱�Ǵ��ڻ��������������Ԫ�أ���Ӧ�أ����ȡ���С�ڻ��������������Ԫ�ء����磬������{5, 8, 4, 2, 3, 4, 6}�У�{8, 6}�Ƿ壬 {5, 2}�ǹȡ����ڸ���һ���������飬�������鰴����ȵĽ���˳������

ʾ��:

����: [5, 3, 1, 2, 3]
���:?[5, 1, 3, 2, 3]
��ʾ��

nums.length <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/peaks-and-valleys-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
