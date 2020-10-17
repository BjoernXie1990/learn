class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n,0);

        int ri = n - 1;
        int le = 0;

        int idx = n - 1;
        while(le <= ri) {
            int numL = A[le] * A[le];;
            int numR = A[ri] * A[ri];

            if(numL >= numR) ans[idx] = numL, le++;
            else ans[idx] = numR,ri--;

            idx--;
        }

        return ans;
    }
};

����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������

?

ʾ�� 1��

���룺[-4,-1,0,3,10]
�����[0,1,9,16,100]
ʾ�� 2��

���룺[-7,-3,2,3,11]
�����[4,9,9,49,121]
?

��ʾ��

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A?�Ѱ��ǵݼ�˳������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/squares-of-a-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
