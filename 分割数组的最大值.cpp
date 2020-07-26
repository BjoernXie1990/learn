����һ���Ǹ����������һ������?m������Ҫ���������ֳ�?m?���ǿյ����������顣���һ���㷨ʹ����?m?����������Ժ͵����ֵ��С��

ע��:
���鳤��?n?������������:

1 �� n �� 1000
1 �� m �� min(50, n)
ʾ��:

����:
nums = [7,2,5,10,8]
m = 2

���:
18

����:
һ�������ַ�����nums�ָ�Ϊ2�������顣
������õķ�ʽ�ǽ����Ϊ[7,2,5] �� [10,8]��
��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0;
        long right = 0;
        for(auto& num : nums)
        {
            left = max(num,(int)left);
            right += num;
        }

        while(left - right != 0)
        {
            long mid = left + (right - left) / 2;

            int count = 0;
            long sum = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                if(sum > mid)
                {
                    sum = nums[i];
                    count++;
                }
            }
            count++;

            if(count <= m) right = mid;
            else left = mid + 1;
        }

        return (int)left;
    }
};
