class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), INF = 0x3f3f3f3f;
        vector<int> f(1<<n,INF);
        vector<int> g(1<<n);
        int d[16];
        f[0] = 0;

        // Ԥ����
        for(int i = 1; i < 1<<n; i++) {
            g[i] = -1;
            if(__builtin_popcount(i) != n / k) continue;

            int cnt = 0;    // �õ���ǰ�����е����� 
            for(int j = 0; j < n; j++)
                if(i >> j & 1) d[cnt++] = nums[j];
            sort(d,d + cnt);

            bool flag = true;
            int minv = d[0],maxv = d[0];
            for(int j = 1; j < cnt; j++) {
                if(d[j] == d[j - 1]) {  // �������ظ�����
                    flag = false;
                    continue;
                }

                minv = min(minv,d[j]);
                maxv = max(maxv,d[j]);
            }
            if(flag) g[i] = maxv - minv;
        }

        for(int i = 1;i < 1<<n; i++)
            for(int j = i; j ; j = (j - 1) & i) // ö���Ӽ�
                if(g[j] != -1) f[i] = min(f[i],f[i-j] + g[j]);
        int res = f[(1<<n) - 1];
        return res == INF ? -1 : res;
    }
};


����һ����������?nums??? ��һ������?k?������Ҫ��������黮�ֵ�?k?����ͬ��С���Ӽ��У�ʹ��ͬһ���Ӽ�����û��������ͬ��Ԫ�ء�

һ���Ӽ��� ��������?�Ǹ��Ӽ��������ֵ����Сֵ�Ĳ

���㷵�ؽ�����ֳ� k?���Ӽ��󣬸��Ӽ� �������� �� ��?�� ��Сֵ?������޷��ֳɷֳ� k?���Ӽ������� -1?��

�Ӽ��Ķ�����������һЩ���ֵļ��ϣ�������˳��û��Ҫ��

?

ʾ�� 1��

���룺nums = [1,2,1,4], k = 2
�����4
���ͣ����ŵķ����� [1,2] �� [1,4] ��
�������Ժ�Ϊ (2-1) + (4-1) = 4 ��
ע�⵽ [1,1] �� [2,4] ���Եõ���С�ĺͣ����ǵ�һ�������� 2 ����ͬ��Ԫ�أ����Բ����С�
ʾ�� 2��

���룺nums = [6,3,8,1,3,1,2,2], k = 4
�����6
���ͣ����ŵ��Ӽ�����Ϊ [1,2]��[2,3]��[6,8] �� [1,3] ��
�������Ժ�Ϊ (2-1) + (3-2) + (8-6) + (3-1) = 6 ��
ʾ�� 3��

���룺nums = [5,3,3,6,3,3], k = 3
�����-1
���ͣ�û�취����Щ���ַ��䵽 3 ���Ӽ�������ÿ���Ӽ���û����ͬ���֡�
?

��ʾ��

1 <= k <= nums.length <= 16
nums.length �ܱ�?k ������
1 <= nums[i] <= nums.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-incompatibility
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
