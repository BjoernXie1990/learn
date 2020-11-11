class Solution {
public:
    const int N = 10010;
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();

        int f[n][2 * N];        // 1-10000 ��������  10001 - 20000 ��������  0
        memset(f,0x00,sizeof f);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            f[i][0] = 1;
            for(int j = 0; j < i; j++) {
                int len = A[i] - A[j];
                if(len < 0) len = 10000 - len;

                if(f[j][len] == 0) f[i][len] = 2;
                else f[i][len] = f[j][len] + 1;
                ans = max(ans,f[i][len]);
            }
        }

        return ans;
        //unordered_map<int,int> mp[n];  // map[n][m] ����Ϊ n �ĵȲ����г���Ϊ m
        // int ans = 1;
        // for(int i = 0; i < n; i++) {
        //     mp[i][0] = 1;
        //     for(int j = 0; j < i; j ++) {
        //         int len = A[i] - A[j];
        //         auto pos = mp[j].find(len);
        //         if(pos == mp[j].end()) {
        //             mp[i][len] = 2;
        //         } else {
        //             mp[i][len] = max(mp[j][len] + 1,mp[i][len]);
        //         }

        //         ans = max(ans,mp[i][len]);
        //     }
        // }

        // return ans;
    }
};


����һ����������?A������ A?����Ȳ������еĳ��ȡ�

����һ�£�A?�����������б�?A[i_1], A[i_2], ..., A[i_k] ����?0 <= i_1 < i_2 < ... < i_k <= A.length - 1���������?B[i+1] - B[i](?0 <= i < B.length - 1) ��ֵ����ͬ����ô����?B?�ǵȲ�ġ�

?

ʾ�� 1��

���룺[3,6,9,12]
�����4
���ͣ� 
���������ǹ���Ϊ 3 �ĵȲ����С�
ʾ�� 2��

���룺[9,4,7,2,10]
�����3
���ͣ�
��ĵȲ��������� [4,7,10]��
ʾ�� 3��

���룺[20,1,15,3,10,5,8]
�����4
���ͣ�
��ĵȲ��������� [20,15,10,5]��
?

��ʾ��

2 <= A.length <= 2000
0 <= A[i] <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-arithmetic-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
