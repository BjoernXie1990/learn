class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> fLe(n + 1,0), fRi(n + 1, 0);
        int l1 = 0, l2 = 0, c1 = 0, c2 = 0;
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(fLe[A[i]] ++ == 0) c1 ++;
            if(fRi[A[i]] ++ == 0) c2 ++;
            if(c1 < K) continue;

            while(c1 > K && l1 <= i)
                if(-- fLe[A[l1 ++]] == 0) c1 --;
            while(c2 >= K && l2 <= i)
                if(-- fRi[A[l2 ++]] == 0) c2 --;
            res += l2 - l1;
        }
        return res;
    }
};


����һ������������ A����� A?��ĳ���������в�ͬ�����ĸ���ǡ��Ϊ K����� A �������������һ��������������Ϊ�������顣

�����磬[1,2,3,1,2] ����?3?����ͬ��������1��2���Լ�?3����

����?A?�к����������Ŀ��

?

ʾ�� 1��

���룺A = [1,2,1,2,3], K = 2
�����7
���ͣ�ǡ���� 2 ����ͬ������ɵ������飺[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
ʾ�� 2��

���룺A = [1,2,1,3,4], K = 3
�����3
���ͣ�ǡ���� 3 ����ͬ������ɵ������飺[1,2,1,3], [2,1,3], [1,3,4].
?

��ʾ��

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/subarrays-with-k-different-integers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
