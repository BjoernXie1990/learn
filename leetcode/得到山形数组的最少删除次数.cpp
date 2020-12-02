class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> le(n,1);
        for(int i = 0; i < n; i++)  
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) le[i] = max(le[i],le[j] + 1);
            }
        
        vector<int> ri(n,1);
        for(int i = n - 1; i >= 0; i--)
            for(int j = n - 1; j > i; j--)
                if(nums[i] > nums[j]) ri[i] = max(ri[i],ri[j] + 1);

        int ans = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            if(le[i] > 1 && ri[i] > 1)  ans = min(ans, n - le[i] - ri[i] + 1);
        }

        return ans;
    }
};

���Ƕ���?arr?�� ɽ������?���ҽ��������㣺

arr.length >= 3
����ĳ���±�?i?���� 0 ��ʼ��?����?0 < i < arr.length - 1?�ң�
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
������������?nums? �����㷵�ؽ� nums?��� ɽ��״����?��? ����?ɾ��������

?

ʾ�� 1��

���룺nums = [1,3,1]
�����0
���ͣ����鱾�����ɽ�����飬�������ǲ���Ҫɾ���κ�Ԫ�ء�
ʾ�� 2��

���룺nums = [2,1,1,5,6,2,3,1]
�����3
���ͣ�һ�ַ����ǽ��±�Ϊ 0��1 �� 5 ��Ԫ��ɾ����ʣ��Ԫ��Ϊ [1,5,6,3,1] ����ɽ�����顣
ʾ�� 3��

���룺nums = [4,3,2,1,1,2,3,1]
�����4
��ʾ��

���룺nums = [1,2,3,4,4,3,2,1]
�����1
?

��ʾ��

3 <= nums.length <= 1000
1 <= nums[i] <= 109
��Ŀ��֤?nums ɾ��һЩԪ�غ�һ���ܵõ�ɽ�����顣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-removals-to-make-mountain-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
