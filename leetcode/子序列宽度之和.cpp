class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        sort(A.begin(),A.end());

        vector<long> pown(n,1);
        for(int i = 1; i < n; i++) pown[i] = pown[i-1] * 2 % mod;

        long ans = 0;
        for(int i = 0; i < n; i++) ans = (ans + (pown[i] - pown[n-1-i]) * A[i]) % mod;

        return ans;
    }
};


����һ���������� A ������ A �����зǿ������С�

������������ S ���� S �Ŀ���� S �����Ԫ�غ���СԪ�صĲ

���� A �����������еĿ��֮�͡�

���ڴ𰸿��ܷǳ����뷵�ش�ģ 10^9+7��

?

ʾ����

���룺[2,1,3]
�����6
���ͣ�
������Ϊ [1]��[2]��[3]��[2,1]��[2,3]��[1,3]��[2,1,3] ��
��Ӧ�Ŀ���� 0��0��0��1��1��2��2 ��
��Щ���֮���� 6 ��
?

��ʾ��

1 <= A.length <= 20000
1 <= A[i] <= 20000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-subsequence-widths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
