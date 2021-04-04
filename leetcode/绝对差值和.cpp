class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef pair<int,int> PII;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> tt(n,0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            int t = abs(nums1[i] - nums2[i]);
            res += t;
            res %= MOD;
            tt[i] = t;
        }
        if(res == 0)
            return res;          

        vector<int> f = nums1;
        sort(f.begin(),f.end());
        
        int pre = res;
        for(int i = 0; i < n; i++) {
            int x = tt[i], y = i;
            
            int le = 0, ri = n - 1;
            while(le < ri) {
                int mid = (le + ri) / 2;
                if(f[mid] >= nums2[y])
                    ri = mid;
                else if(f[mid] < nums2[y])
                    le = mid + 1;
            }
            
            int sub = abs(nums2[i] - f[le]);
            if(le < n - 1 && x > abs(nums2[i] - f[le + 1])) {
                sub = min(sub,abs(nums2[i] - f[le + 1]));
            }
            if(le > 0 && x > abs(nums2[i] - f[le - 1])) {
                sub = min(sub,abs(nums2[i] - f[le - 1]));
            }
            
            res = min(res,(pre - x + sub) % MOD);
        }
                        
        return res;
    }
};


������������������ nums1 �� nums2 ������ĳ��ȶ��� n ��

���� nums1 �� nums2 �� ���Բ�ֵ�� ����Ϊ���� |nums1[i] - nums2[i]|��0 <= i < n���� �ܺͣ��±�� 0 ��ʼ����

�����ѡ�� nums1 �е� ����һ�� Ԫ�����滻 nums1 �е� ���� һ��Ԫ�أ��� ��С�� ���Բ�ֵ�͡�

���滻���� nums1 �����һ��Ԫ�� ֮�� ��������С���Բ�ֵ�͡���Ϊ�𰸿��ܴܺ�������Ҫ�� 109 + 7 ȡ�� �󷵻ء�

|x| ����Ϊ��

��� x >= 0 ��ֵΪ x ������
��� x <= 0 ��ֵΪ -x
?

ʾ�� 1��

���룺nums1 = [1,7,5], nums2 = [2,3,5]
�����3
���ͣ������ֿ��ܵ����ŷ�����
- ���ڶ���Ԫ���滻Ϊ��һ��Ԫ�أ�[1,7,5] => [1,1,5] ������
- ���ڶ���Ԫ���滻Ϊ������Ԫ�أ�[1,7,5] => [1,5,5]
���ַ����ľ��Բ�ֵ�Ͷ��� |1-2| + (|1-3| ���� |5-3|) + |5-5| = 3
ʾ�� 2��

���룺nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
�����0
���ͣ�nums1 �� nums2 ��ȣ����Բ����滻Ԫ�ء����Բ�ֵ��Ϊ 0
ʾ�� 3��

���룺nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
�����20
���ͣ�����һ��Ԫ���滻Ϊ�ڶ���Ԫ�أ�[1,10,4,4,2,7] => [10,10,4,4,2,7]
���Բ�ֵ��Ϊ |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
?

��ʾ��

n == nums1.length
n == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 105

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-absolute-sum-difference
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
