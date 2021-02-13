class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        //vector<vector<int> > f(n+1,vector<int> (2,1));

        int res = 1;
        int up = 1, down = 1;
        for(int i = 2; i <= n; i++) {
            int tup = 1,tdown = 1;
            if(arr[i - 1] > arr[i - 2]) tup += down;
            if(arr[i - 1] < arr[i - 2]) tdown += up;
            res = max(res,max(tdown,tup));
            up = tup, down = tdown;
        }

        return res;
    }
};


�� A?��������?A[i], A[i+1], ..., A[j]?������������ʱ�����ǳ���Ϊ���������飺

��?i <= k < j���� k?Ϊ����ʱ��?A[k] > A[k+1]���ҵ� k Ϊż��ʱ��A[k] < A[k+1]��
�� ��?i <= k < j���� k Ϊż��ʱ��A[k] > A[k+1]?���ҵ� k?Ϊ����ʱ��?A[k] < A[k+1]��
Ҳ����˵������ȽϷ������������е�ÿ������Ԫ�ض�֮�䷭ת����������������������顣

���� A ���������������ĳ��ȡ�

?

ʾ�� 1��

���룺[9,4,2,10,7,8,8,1,9]
�����5
���ͣ�(A[1] > A[2] < A[3] > A[4] < A[5])
ʾ�� 2��

���룺[4,8,12,16]
�����2
ʾ�� 3��

���룺[100]
�����1
?

��ʾ��

1 <= A.length <= 40000
0 <= A[i] <= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-turbulent-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
