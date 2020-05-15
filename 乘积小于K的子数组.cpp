//����һ������������?nums��

//�ҳ��������ڳ˻�С��?k?��������������ĸ�����

//ʾ�� 1:

//����: nums = [10,5,2,6], k = 100
//���: 8
//����: 8���˻�С��100��������ֱ�Ϊ: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]��
//��Ҫע����� [10,5,2] �����ǳ˻�С��100�������顣
//˵��:

//0 < nums.length <= 50000
//0 < nums[i] < 1000
//0 <= k < 10^6


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        int left = 0;
        int mul = 1;
        for(int i = 0; i < len; i++)
        {
            mul *= nums[i];

            while(mul >= k && left <= i)
                mul /= nums[left++];

            if(mul < k) ans += i-left+1; 
            //cout<<left<<' '<<i<<' '<<ans<<endl;
        }
        return ans;
    }
};
