class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        // dp
        int n = A.size();
        int dp[n][n];
        memset(dp,0x00,sizeof dp);

        int sum = 0, ans = 0;
        int le = 0, ri = 0;
        for(int i = 1; i < n; i++) {
            le = 0, ri = i - 1;
            while(le < ri) {
                sum = A[le] + A[ri];
                if(sum == A[i]) {
                    dp[ri][i] = dp[le][ri] + 1;
                    ans = max(dp[ri][i],ans);
                    le++,ri--;
                } else if(sum < A[i])   le++;
                else if(sum > A[i])     ri--;
            }
        }
        return ans == 0 ? 0 : ans + 2;
        // set 
        // int n = A.size();
        // unordered_set<int> hash(A.begin(),A.end());

        // int ans = 0;
        // for(int i = 0; i < n; i++)
        //     for(int j = i + 1; j < n; j++) {
        //         int pre = A[i], next = A[j];
        //         int sum = pre + next;
        //         int len = 2;
        //         while(hash.find(sum) != hash.end()) {
        //             pre = next;
        //             next = sum;
        //             sum = pre + next;
        //             ans = max(ans,++len);
        //         }
        //     }
        
        // return ans;
    }
};

�������?X_1, X_2, ..., X_n?����������������˵����?쳲�����ʽ?�ģ�

n >= 3
��������?i + 2 <= n������?X_i + X_{i+1} = X_{i+2}
����һ���ϸ�����������������γ����У��ҵ� A �����쳲�����ʽ�������еĳ��ȡ����һ�������ڣ�����??0 ��

������һ�£��������Ǵ�ԭ���� A?�����������ģ����� A?��ɾ������������Ԫ�أ�Ҳ���Բ�ɾ���������ı�����Ԫ�ص�˳�����磬?[3, 5, 8]?��?[3, 4, 5, 6, 7, 8]?��һ�������У�

?

ʾ�� 1��

����: [1,2,3,4,5,6,7,8]
���: 5
����:
���쳲�����ʽ������Ϊ��[1,2,3,5,8] ��
ʾ��?2��

����: [1,3,7,11,12,14,18]
���: 3
����:
���쳲�����ʽ�������У�
[1,11,12]��[3,11,14] �Լ� [7,11,18] ��
?

��ʾ��

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
�������� Java��C��C++���Լ�?C# ���ύ��ʱ�����Ʊ������� 50%��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
