
����һ�����������飬 ���������������1�ĸ�����

ʾ�� 1:

����: [1,1,0,1,1,1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
ע�⣺

���������ֻ����?0 ��1��
��������ĳ��������������Ҳ����� 10,000��


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)   
                sum++;
            else {
                ans = max(sum,ans);
                sum = 0;
            }
        }
        ans = max(ans,sum);
        return ans;
    }
};
