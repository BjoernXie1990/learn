����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 �������ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

?

ʾ����

�������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return {};
        sort(nums.begin(),nums.end());

        vector<vector<int> > ans;

        for(int one = 0; one < len; one++)
        {
            if(one > 0 && nums[one] == nums[one-1]) continue;

            int target = -nums[one];
            int three = len - 1;

            for(int two = one + 1; two < len - 1; two++)
            {
                if(two > one + 1 && nums[two] == nums[two - 1]) continue;

                //����
                //three = BinaryFind(nums,two + 1,three,target-nums[two]);
                // if(three != -1)
                //     ans.push_back({nums[one],nums[two],nums[three]});

                while(two < three && nums[three] > (target - nums[two]))
                    three--;

                if(two == three) continue;
                if(nums[three] == (target - nums[two]))
                    ans.push_back({nums[one],nums[two],nums[three]});
            }
        }

        return ans;
    }

    int BinaryFind(vector<int>& nums,int le,int ri, int num)
    {
        if(le > ri) return -1;

        while(le <= ri)
        {
            int mid = (le + ri) / 2;

            if(nums[mid] == num) return mid;
            else if(nums[mid] > num) ri = mid-1;
            else if(nums[mid] < num) le = mid+1;
        }
        return -1;
    }
};
