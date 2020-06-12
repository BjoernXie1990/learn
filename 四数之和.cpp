//����һ������?n ������������?nums?��һ��Ŀ��ֵ?target���ж�?nums?���Ƿ�����ĸ�Ԫ�� a��b��c?�� d?��ʹ��?a + b + c + d?��ֵ��?target?��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

//ע�⣺

//���в����԰����ظ�����Ԫ�顣

//ʾ����

//�������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

//����Ҫ�����Ԫ�鼯��Ϊ��
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 4) return {};

        sort(nums.begin(),nums.end());

        vector<vector<int> > ans;
        for(int i = 0; i < len; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            vector<vector<int> > tmp = threeSum(nums,i+1,len-1,target - nums[i],nums[i]);

            for(auto& eoch : tmp)
                ans.push_back(eoch);
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums,int le,int ri,int tar,int n) {
        int len = ri - le + 1;
        if(len <= 2) return {};

        vector<vector<int> > ans;

        for(int one = le; one < ri; one++)
        {
            if(one > le && nums[one] == nums[one-1]) continue;

            int target = tar - nums[one];
            int three = ri;

            for(int two = one + 1; two < ri; two++)
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
                    ans.push_back({n,nums[one],nums[two],nums[three]});
            }
        }

        return ans;
    }
};
