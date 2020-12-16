class Solution {
public:
    const int N = 1e5+10;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        int f[N];
        memset(f,0x00,sizeof f);
        
        for(int i = 0; i < n; i++) {
            f[i+1] = nums[i] + f[i];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            //cout << f[i] << " " << f[i+1] << endl;
            int le = nums[i] * i - f[i];
            int ri = f[n] - f[i + 1] - nums[i] * (n - i - 1);
            
            ans.push_back(abs(le) + abs(ri));
        }
        
        return ans;
    }
};


����һ�� �ǵݼ�?������������?nums?��

���㽨��������һ����������?result������?nums?������ͬ����result[i]?����?nums[i]?����������������Ԫ�ز�ľ���ֵ֮�͡�

���仰˵��?result[i]?����?sum(|nums[i]-nums[j]|) ������?0 <= j < nums.length ��?j != i?���±�� 0 ��ʼ����

?

ʾ�� 1��

���룺nums = [2,3,5]
�����[4,3,5]
���ͣ����������±�� 0 ��ʼ����ô
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4��
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3��
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5��
ʾ�� 2��

���룺nums = [1,4,6,8,10]
�����[24,15,13,15,21]
?

��ʾ��

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
