����һ������?n?���������������һ��������?s ���ҳ���������������� �� s �ĳ�����С�����������飬�������䳤�ȡ���������ڷ������������������飬���� 0��

ʾ��:?

����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������?[4,3]?�Ǹ������µĳ�����С�����������顣

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0;
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            num += nums[i];
            while(num >= s && left <= i)
            {
                ans = min(ans,i - left + 1);
                num -= nums[left++];
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
