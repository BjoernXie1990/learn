����һ���������飬������������֮��ĵ� k ����С���롣һ�� (A, B) �ľ��뱻����Ϊ A �� B ֮��ľ��Բ�ֵ��

ʾ�� 1:

���룺
nums = [1,3,1]
k = 1
�����0 
���ͣ�
�����������£�
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
��˵� 1 ����С����������� (1,1)������֮��ľ���Ϊ 0��
��ʾ:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.



class Solution {
public:
    int len = 0;
    int smallestDistancePair(vector<int>& nums, int k) {
        len = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;//��С��ֵ
        int right = nums[len - 1] - nums[0];//����ֵ

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(check(nums,mid) >= k)
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
    //Ѱ��nums�����У���valֵС�ľ�������
    int check(vector<int>& nums,int val)
    {
        int le = 0;
        int ans = 0;

        for(int i = 0; i < len; i++)
        {
            while(nums[i] - nums[le] > val) le++;
            ans += i - le;//i һ������ le,numsΪ��������
        }
        return ans;
    }
};
