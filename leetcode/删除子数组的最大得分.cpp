class Solution {
public:

    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        //unordered_map<int,int> hash;
        int hash[10010];
        memset(hash,0x00,sizeof hash);

        int le = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(le < i && hash[nums[i]]) {
                hash[nums[le]] = 0;
                sum -= nums[le++];
            }

            hash[nums[i]] = 1;
            ans = max(ans,sum);
        }

        return ans;
    }
};


����һ������������ nums ���������ɾ��һ������ ���ɲ�ͬԪ�� �������顣ɾ��������� �÷� �����������Ԫ��֮ �� ��

���� ֻɾ��һ�� ������ɻ�õ� ���÷� ��

������� b ������ a ��һ�����������У������������ a[l],a[l+1],...,a[r] ����ô������?a ��һ�������顣

?

ʾ�� 1��

���룺nums = [4,2,4,5,6]
�����17
���ͣ������������� [2,4,5,6]
ʾ�� 2��

���룺nums = [5,2,1,2,5,2,1,2,5]
�����8
���ͣ������������� [5,2,1] �� [1,2,5]
?

��ʾ��

1 <= nums.length <= 105
1 <= nums[i] <= 104

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-erasure-value
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
