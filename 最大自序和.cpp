//����һ���������� nums?���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

//ʾ��:

//����: [-2,1,-3,4,-1,2,1,-5,4],
//���: 6
//����:?����������?[4,-1,2,1] �ĺ����Ϊ?6��



class Solution {
public:
    //����O(n)
    int maxSubArray1(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;

        for(auto& eoch : nums) {
            if(sum > 0) sum += eoch;
            else sum = eoch;

            ans = max(sum,ans);
        }

        return ans;
    }
    //��̬�滮
    int maxSubArray2(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0);

        dp[0] = nums[0];
        int ans = dp[0];

        for(int i = 1; i < len; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
    //���� O(Nlogn)
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        return merger(nums,0,len-1);
    }
    //����������������������������䣬������еĴ�С
    int AddMerger(vector<int>& nums,int left, int mid, int right) {
        //�������Ӧ����mid�м��Ϊ���
        int sum = 0;
        int leftSum = INT_MIN;
        for(int i = mid; i >= left; i--){
            sum += nums[i];
            leftSum = max(leftSum,sum);
        }

        sum = 0;
        int rightSum = INT_MIN;
        //y�ұ�������mid+1Ϊ���
        for(int i = mid+1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum,sum);
        }
        return leftSum + rightSum;
    }

    int merger(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];

        int mid = left + (right - left) / 2;
        return max3(merger(nums,left,mid),
                    merger(nums,mid+1,right),
                    AddMerger(nums,left,mid,right));
    }

    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
};
