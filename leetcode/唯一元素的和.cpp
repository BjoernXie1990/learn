class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& e : nums) mp[e] ++;
        int res = 0;
        for(auto& e : mp) {
            if(e.second == 1) res += e.first;
        }
        return res;
    }
};

����һ����������?nums?��������ΨһԪ������Щֻ����?ǡ��һ��?��Ԫ�ء�

���㷵�� nums?��ΨһԪ�ص� ��?��

?

ʾ�� 1��

���룺nums = [1,2,3,2]
�����4
���ͣ�ΨһԪ��Ϊ [1,3] ����Ϊ 4 ��
ʾ�� 2��

���룺nums = [1,1,1,1,1]
�����0
���ͣ�û��ΨһԪ�أ���Ϊ 0 ��
ʾ�� 3 ��

���룺nums = [1,2,3,4,5]
�����15
���ͣ�ΨһԪ��Ϊ [1,2,3,4,5] ����Ϊ 15 ��
?

��ʾ��

1 <= nums.length <= 100
1 <= nums[i] <= 100
ͨ������1,695�ύ����2,048

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-unique-elements
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
