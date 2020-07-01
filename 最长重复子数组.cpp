
��������������?A?��?B?���������������й����ġ��������������ĳ��ȡ�

ʾ�� 1:

����:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
���: 3
����: 
������Ĺ����������� [3, 2, 1]��
˵��:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100


class Solution {
public:
    //��̬�滮
    int findLength1(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();

        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }
        return ans;
    }

    //��������
    int findLength(vector<int>& A, vector<int>& B)
    {
        int n = A.size();
        int m = B.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int len = min(m,n-i);
            int tmp = MinAns(A,B,i,0,len);
            ans = max(tmp,ans);
        }

        for(int i = 0; i < m; i++)
        {
            int len = min(n,m-i);
            int tmp = MinAns(A,B,0,i,len);
            ans = max(tmp,ans);
        }
        return ans;
    }

    int MinAns(vector<int>& A,vector<int>& B,int idA,int idB,int len)
    {
        int k = 0;
        int ret = 0;
        for(int i = 0; i < len; i++)
        {
            if(A[idA + i] == B[idB + i])
                k++;
            else
                k = 0;
            ret = max(ret,k);
        }
        return ret;
    }
};
