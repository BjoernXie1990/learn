class Solution {
public:
    static const int N = 1e5 + 10;
    int f[N + 1];
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        for(int i = 0; i < n; i++) f[i+1] = f[i] + nums[i];
        int idx = BinaryFind(0,n,x);
        int ans = f[idx] == x ? idx : INT_MAX;
        int sum = 0;

        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            if(sum > x) break;

            int p = BinaryFind(0,i,x - sum);
            if(f[p] == x - sum) ans = min(ans,p + n - i);
        }

        return ans == INT_MAX ? -1 : ans;
    }


    int BinaryFind(int le,int ri,int num) {
        while(le < ri) {
            int mid = le + ri >> 1;
            if(f[mid] >= num) ri = mid;
            else if(f[mid] < num) le = mid + 1;
        }
        return le;
    }
};

����һ���������� nums ��һ������ x ��ÿһ�β���ʱ����Ӧ���Ƴ����� nums ����߻����ұߵ�Ԫ�أ�Ȼ��� x �м�ȥ��Ԫ�ص�ֵ����ע�⣬��Ҫ �޸� �����Թ��������Ĳ���ʹ�á�

������Խ� x?ǡ�� ����?0 ������ ��С������ �����򣬷��� -1 ��

?

ʾ�� 1��

���룺nums = [1,1,4,2,3], x = 5
�����2
���ͣ���ѽ���������Ƴ�������Ԫ�أ��� x ���� 0 ��
ʾ�� 2��

���룺nums = [5,6,7,8,9], x = 4
�����-1
ʾ�� 3��

���룺nums = [3,2,20,1,1,3], x = 10
�����5
���ͣ���ѽ���������Ƴ�������Ԫ�غ�ǰ����Ԫ�أ��ܹ� 5 �β��������� x ���� 0 ��
?

��ʾ��

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
