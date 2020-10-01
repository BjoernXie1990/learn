class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i = 1; i < n; i++) if(nums[i] > nums[pos]) pos = i;

        for(int i = 0; i < n; i++) {
            if(i == pos) continue;
            if(nums[i] * 2 > nums[pos]) return -1;
        }

        return pos;
    }
};

��һ������������nums�У����Ǵ���һ�����Ԫ�� ��

���������е����Ԫ���Ƿ�������������ÿ���������ֵ�������

����ǣ��򷵻����Ԫ�ص����������򷵻�-1��

ʾ�� 1:

����: nums = [3, 6, 1, 0]
���: 1
����: 6����������, ���������е���������,
6��������������Ԫ�ص�������6��������1, �������Ƿ���1.
?

ʾ�� 2:

����: nums = [1, 2, 3, 4]
���: -1
����: 4û�г���3��������, �������Ƿ��� -1.
?

��ʾ:

nums?�ĳ��ȷ�Χ��[1, 50].
ÿ��?nums[i]?��������Χ��?[0, 100].

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
