class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp,d;
        int res = 1e9, cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(d.find(nums[i]) == d.end()) d[nums[i]] = i;
            mp[nums[i]] ++;
            int e = mp[nums[i]];
            if(e > cnt) {
                cnt = e;
                res = 1e9; 
            }
            if(e == cnt)  res = min(res, i - d[nums[i]] + 1);
        }

        return res;
    }
};

����һ���ǿ���ֻ�����Ǹ�������������?nums������ĶȵĶ�����ָ��������һԪ�س���Ƶ�������ֵ��

����������� nums ���ҵ���?nums?ӵ����ͬ��С�Ķȵ�������������飬�����䳤�ȡ�

?

ʾ�� 1��

���룺[1, 2, 2, 3, 1]
�����2
���ͣ�
��������Ķ���2����ΪԪ��1��2�ĳ���Ƶ����󣬾�Ϊ2.
��������������ӵ����ͬ�ȵ���������ʾ:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
�������������[2, 2]�ĳ���Ϊ2�����Է���2.
ʾ�� 2��

���룺[1,2,2,3,1,4,2]
�����6
?

��ʾ��

nums.length?��1�� 50,000 ���䷶Χ�ڡ�
nums[i]?��һ���� 0 �� 49,999 ��Χ�ڵ�������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/degree-of-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
