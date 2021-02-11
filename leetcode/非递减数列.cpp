class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int le = nums[i], ri = nums[i + 1];
            if(le > ri) {
                cnt ++;
                if(cnt > 1) return false;
                if(i && ri < nums[i - 1]) nums[i+1] = le;
            }
        }

        return true;
    }
};


����һ������Ϊ?n?���������飬�����ж��� ��� �ı�?1 ��Ԫ�ص�����£��������ܷ���һ���ǵݼ����С�

��������������һ���ǵݼ����еģ�?�������������е�?i (0 <= i <= n-2)�������� nums[i] <= nums[i + 1]��

?

ʾ�� 1:

����: nums = [4,2,3]
���: true
����: �����ͨ���ѵ�һ��4���1��ʹ������Ϊһ���ǵݼ����С�
ʾ�� 2:

����: nums = [4,2,1]
���: false
����: �㲻����ֻ�ı�һ��Ԫ�ص�����½����Ϊ�ǵݼ����С�
?

˵����

1 <= n <= 10 ^ 4
- 10 ^ 5?<= nums[i] <= 10 ^ 5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/non-decreasing-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
