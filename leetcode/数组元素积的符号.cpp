class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto& e : nums) {
            if(e == 0)
                return 0;
            
            if(e > 0)
                a ++;
            if(e < 0)
                b ++;
        }
        
        if(b & 1)
            return -1;
        return 1;
    }
};

��֪����?signFunc(x) ������� x �����������ض�ֵ��

��� x ������������ 1 ��
��� x �Ǹ��������� -1 ��
��� x �ǵ��� 0 ������ 0 ��
����һ���������� nums ���� product Ϊ���� nums ������Ԫ��ֵ�ĳ˻���

���� signFunc(product) ��

?

ʾ�� 1��

���룺nums = [-1,-2,-3,-4,3,2,1]
�����1
���ͣ�����������ֵ�ĳ˻��� 144 ���� signFunc(144) = 1
ʾ�� 2��

���룺nums = [1,5,0,2,-3]
�����0
���ͣ�����������ֵ�ĳ˻��� 0 ���� signFunc(0) = 0
ʾ�� 3��

���룺nums = [-1,1,-1,1,-1]
�����-1
���ͣ�����������ֵ�ĳ˻��� -1 ���� signFunc(-1) = -1
?

��ʾ��

1 <= nums.length <= 1000
-100 <= nums[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sign-of-the-product-of-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
