class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        p = 0;
        while(p < n - 1 && nums[p] <= nums[p + 1])
            p++;
        if(p == n - 1) return true;
        
        int le = nums[p ++];
        int ri = nums[p];
        while(p < n - 1 && nums[p] <= nums[p + 1])
            p++;
        if(p != n-1) return false;
        if(nums[n-1] <= nums[0]) return true;
        return false;
    }
};

����һ������ nums ��nums ��Դ�����У�����Ԫ���� nums ��ͬ�������ǵݼ�˳�����С�

���?nums �ܹ���Դ������ת����λ�ã����� 0 ��λ�ã��õ����򷵻� true �����򣬷��� false ��

Դ�����п��ܴ��� �ظ��� ��

ע�⣺���ǳ����� A ����ת x ��λ�ú�õ�������ͬ������ B ������������ A[i] == B[(i+x) % A.length] ������ % Ϊȡ�����㡣

?

ʾ�� 1��

���룺nums = [3,4,5,1,2]
�����true
���ͣ�[1,2,3,4,5] Ϊ�����Դ���顣
������ת x = 3 ��λ�ã�ʹ�������ֵΪ 3 ��Ԫ�ؿ�ʼ��[3,4,5,1,2] ��
ʾ�� 2��

���룺nums = [2,1,3,4]
�����false
���ͣ�Դ�����޷�����ת�õ� nums ��
ʾ�� 3��

���룺nums = [1,2,3]
�����true
���ͣ�[1,2,3] Ϊ�����Դ���顣
������ת x = 0 ��λ�ã�������ת���õ� nums ��
ʾ�� 4��

���룺nums = [1,1,1]
�����true
���ͣ�[1,1,1] Ϊ�����Դ���顣
��ת�����λ�ö����Եõ� nums ��
ʾ�� 5��

���룺nums = [2,1]
�����true
���ͣ�[1,2] Ϊ�����Դ���顣
������ת x = 5 ��λ�ã�ʹ�������ֵΪ 2 ��Ԫ�ؿ�ʼ��[2,1] ��
?

��ʾ��

1 <= nums.length <= 100
1 <= nums[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
