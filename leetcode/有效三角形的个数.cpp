����һ�������Ǹ����������飬���������ͳ�����п�����������������ߵ���Ԫ�������

ʾ�� 1:

����: [2,2,3,4]
���: 3
����:
��Ч�������: 
2,3,4 (ʹ�õ�һ�� 2)
2,3,4 (ʹ�õڶ��� 2)
2,2,3
ע��:

���鳤�Ȳ�����1000��
�����������ķ�ΧΪ [0, 1000]��

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int le = 0;
        int ri = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = nums[i] + nums[j];
                int p = n-1;
                while(p > j && nums[p] >= sum) {
                    p--;
                }
                ans += p - j;
            }
        }
        return ans;
    }
};
