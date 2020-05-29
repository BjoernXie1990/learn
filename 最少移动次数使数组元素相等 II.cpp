//����һ���ǿ��������飬�ҵ�ʹ��������Ԫ������������С�ƶ���������ÿ���ƶ��ɽ�ѡ����һ��Ԫ�ؼ�1���1�� �����Լ�������ĳ������Ϊ10000��

//����:

//����:
//[1,2,3]

//���:
//2

//˵����
//ֻ�����������Ǳ�Ҫ�ģ��ǵ�ÿһ������ʹ����һ��Ԫ�ؼ�1���1���� 

//[1,2,3]  =>  [2,2,3]  =>  [2,2,2]


class Solution {
public:
    int minMoves1(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        sort(nums.begin(),nums.end());
        int midNum = nums[len/2];

        int ret = 0;
        for(auto& eoch : nums)
            ret += abs(eoch - midNum);
        return ret;
    }

    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int ret = 0;

        while(left < right)
        {
            ret += nums[right--] - nums[left++];
        }
        return ret;
    }
};
