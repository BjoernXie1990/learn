class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 1; i < n; i += 2) {
            int len = nums[i-1];
            int num = nums[i];
            for(int j = 0; j < len; j++) ans.push_back(num);
        }

        return ans;
    }
};


����һ�����г̳��ȱ���ѹ���������б�?nums?��

����ÿ�����ڵ�����Ԫ�� [freq, val] = [nums[2*i], nums[2*i+1]]?������?i >= 0?����ÿһ�Զ���ʾ��ѹ�����б����� freq?��ֵΪ?val?��Ԫ�أ�����Ҫ�����������������б������ɽ�ѹ����б�

���㷵�ؽ�ѹ����б�

?

ʾ����

���룺nums = [1,2,3,4]
�����[2,4,4,4]
���ͣ���һ�� [1,2] ������ 2 �ĳ���Ƶ��Ϊ 1�������������� [2]��
�ڶ��� [3,4] ������ 4 �ĳ���Ƶ��Ϊ 3�������������� [4,4,4]��
������Ǵ�����һ�� [2] + [4,4,4] = [2,4,4,4]��
ʾ�� 2��

���룺nums = [1,1,2,3]
�����[1,3,3]
?

��ʾ��

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/decompress-run-length-encoded-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
