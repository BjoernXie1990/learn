����һ������������ nums������Ҫ������ѡһЩ�Ӽ���Ȼ���Ӽ���ÿһ��������һ�� ������������������ǵĺ͡�

����úͽ��Ϊ?1����ôԭ�������һ���������项���򷵻� True�������뷵�� False��

?

ʾ�� 1��

���룺nums = [12,5,7,23]
�����true
���ͣ���ѡ���� 5 �� 7��
5*3 + 7*(-2) = 1
ʾ�� 2��

���룺nums = [29,6,10]
�����true
���ͣ���ѡ���� 29, 6 �� 10��
29*1 + 6*(-3) + 10*(-1) = 1
ʾ�� 3��

���룺nums = [3,6]
�����false
?

��ʾ��

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            res = gcd(res,nums[i]);
            if(res == 1)    return true;
        }

        return res == 1;
    }

    inline int gcd(int a,int b)
    {
        return b==0 ? a : gcd(b,a%b);
    }
};
