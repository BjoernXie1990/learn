//����һ������?n ������������?nums?�� һ��Ŀ��ֵ?target���ҳ�?nums?�е�����������ʹ�����ǵĺ���?target?��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

//���磬�������� nums = [-1��2��1��-4], �� target = 1.

//�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();

        int ans_sum = Add(nums,0,1,2);
        int ans_sub =  Sub(ans_sum,target);

        for(int i = 0; i < len - 2; i++)
        {
            int left = i + 1;
            int right = len - 1;
            while(left < right)
            {
                int sum = Add(nums,i,left,right);
                int sub = Sub(sum,target);
                if(sub < ans_sub) 
                {
                    ans_sum = sum;
                    ans_sub = sub;
                }
                if(sum > target) right--;
                else left++;
            }
        }
        return ans_sum;
    }

    static int Add(vector<int>& nums,int left,int mid,int right)
    {
        return nums[left] + nums[mid] + nums[right];
    }

    static int Sub(int num, int target)
    {
        return abs(num - target);
    }
};
