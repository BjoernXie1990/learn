һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�

?

ʾ�� 1:

����: [0,1,3]
���: 2
ʾ��?2:

����: [0,1,2,3,4,5,6,7,9]
���: 8
?

���ƣ�

1 <= ���鳤�� <= 10000



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left < right)
        {
            int mid = (left + right) / 2;

            if(mid == nums[mid])
                left = mid+1;
            else if(mid < nums[mid])
                right = mid;
        }

        return left == nums.size()-1 && nums[left] == left ? left+1 : left;
    }
};
