class Solution {
public:
    static const int N = 310;
    int dp[N][N]; // dp[i][j] ��ʾ�� i,j Ϊ���½ǣ����Թ��ɵ���������εı߳�

    int countSquares(vector<vector<int>>& matrix) {
        memset(dp,0x00,sizeof dp);
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 1) {
                    dp[i+1][j+1] = Min(dp[i][j],dp[i+1][j],dp[i][j+1]) + 1;
                    ans += dp[i+1][j+1];
                }
        return ans;
    }

    inline int Min(int a,int b,int c) {
        return min(a,min(b,c));
    }
};

����һ��?m * n?�ľ��󣬾����е�Ԫ�ز��� 0 ���� 1������ͳ�Ʋ�����������ȫ�� 1 ��ɵ� ������ �Ӿ���ĸ�����

?

ʾ�� 1��

���룺matrix =
[
? [0,1,1,1],
? [1,1,1,1],
? [0,1,1,1]
]
�����15
���ͣ� 
�߳�Ϊ 1 ���������� 10 ����
�߳�Ϊ 2 ���������� 4 ����
�߳�Ϊ 3 ���������� 1 ����
�����ε����� = 10 + 4 + 1 = 15.
ʾ�� 2��

���룺matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
�����7
���ͣ�
�߳�Ϊ 1 ���������� 6 ���� 
�߳�Ϊ 2 ���������� 1 ����
�����ε����� = 6 + 1 = 7.
?

��ʾ��

1 <= arr.length?<= 300
1 <= arr[0].length?<= 300
0 <= arr[i][j] <= 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
