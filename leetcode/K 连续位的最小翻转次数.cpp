class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> f(n + 1,0);
        int res = 0, cur = 0;

        for(int i = 0; i < n; i++) {
            cur += f[i];
            if((A[i] + cur) % 2 == 0) {
                if(i + K > n) return -1;
                res ++;
                f[i + 1] ++;
                f[i + K] --;
            }
        }

        return res;
    }
};


class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int res = 0, cur = 0;

        for(int i = 0; i < n; i++) {
            if(i >= K && A[i - K] > 1) {
                cur --;
                A[i - K] -= 2;
            }

            if((A[i] + cur) % 2 == 0) {
                if(i + K > n) return -1;
                cur ++;
                res ++;
                A[i] += 2;
            }
        }

        return res;
    }
};


�ڽ����� 0 �� 1 ������ A �У�һ�� K λ��ת����ѡ��һ������Ϊ K �ģ������������飬ͬʱ���������е�ÿ�� 0 ����Ϊ 1����ÿ�� 1 ����Ϊ 0��

��������� K λ��ת����С�������Ա�����û��ֵΪ 0 ��Ԫ�ء���������ܣ����� -1��

?

ʾ�� 1��

���룺A = [0,1,0], K = 1
�����2
���ͣ��ȷ�ת A[0]��Ȼ��ת A[2]��
ʾ�� 2��

���룺A = [1,1,0], K = 2
�����-1
���ͣ���������������ת��СΪ 2 �������飬���Ƕ�����ʹ�����Ϊ [1,1,1]��
ʾ�� 3��

���룺A = [0,0,0,1,0,1,1,0], K = 3
�����3
���ͣ�
��ת A[0],A[1],A[2]:?A��� [1,1,1,1,0,1,1,0]
��ת A[4],A[5],A[6]:?A��� [1,1,1,1,1,0,0,0]
��ת A[5],A[6],A[7]:?A��� [1,1,1,1,1,1,1,1]
?

��ʾ��

1 <= A.length <=?30000
1 <= K <= A.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
