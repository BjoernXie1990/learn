//������������������Ҳ�Ϊ�յ���������?A?��?B?��

//���ǿ��Խ���?A[i]?��?B[i]?��Ԫ�ء�ע��������Ԫ���ڸ��Ե�������Ӧ�ô�����ͬ��λ�á�

//�ڽ�����һЩԪ��֮������?A?��?B?��Ӧ�����ϸ�����ģ������ϸ������������ΪA[0] < A[1] < A[2] < ... < A[A.length - 1]����

//��������?A?��?B?���뷵��ʹ����������������ϸ����״̬����С�����������������������������Ч�ġ�

//ʾ��:
//����: A = [1,3,5,4], B = [1,2,3,7]
//���: 1
//����: 
//���� A[3] �� B[3] ��������������:
//A = [1, 3, 5, 7] �� B = [1, 2, 3, 4]
//���������Ϊ�ϸ�����ġ�


class Solution {
public:
    //�ռ临�Ӷ�O(n)
    int minSwap1(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<vector<int> > dp(len,vector<int>(2,0));
        dp[0][1] = 1;
        for(int i = 1; i < len; i++)
        {
            if(A[i] <= A[i-1] || B[i] <= B[i-1])//ǰһ��û�н���,��һ����Ҫ����
            {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }
            else if( B[i] <= A[i-1] || A[i] <= B[i-1])//ǰһ�з�����������һ�в���Ҫ����
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
            else//�ɽ������ɲ�����
            {
                dp[i][0] = min(dp[i-1][1],dp[i-1][0]);
                dp[i][1] = dp[i][0] + 1;
            }

        }
        return min(dp[len-1][0],dp[len-1][1]);
    }
    //�ռ临�Ӷ�O(n)
    int minSwap2(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<vector<int> > dp(len,vector<int>(2,0));
        dp[0][1] = 1;
        for(int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i][1] = 3000;
            if(A[i] > A[i-1] && B[i] > B[i-1])//ǰһ��û�з�������
            {
                dp[i][0] = min(dp[i][0],dp[i-1][0]);
                dp[i][1] = min(dp[i][1],dp[i-1][1] + 1);
            }

            if( A[i] > B[i-1] &&  B[i] > A[i-1] )//ǰһ�з�������
            {
                dp[i][0] = min(dp[i][0],dp[i-1][1]);
                dp[i][1] = min(dp[i][1],dp[i-1][0] + 1);
            }

        }
        return min(dp[len-1][0],dp[len-1][1]);
    }
    //�ռ临�Ӷ�O(1)
    int minSwap3(vector<int>& A, vector<int>& B) {
        int len = A.size();
        int dp[2] = {0,1};
        for(int i = 1; i < len; i++)
        {
            int n0 =3000, n1 = 3000;
            if(A[i] > A[i-1] && B[i] > B[i-1])//ǰһ��û�з�������
            {
                n0 = min(n0,dp[0]);
                n1 = min(n1,dp[1] + 1);
            }

            if( A[i] > B[i-1] &&  B[i] > A[i-1] )//ǰһ�з�������
            {
                n0 = min(n0,dp[1]);
                n1 = min(n1,dp[0] + 1);
            }

            dp[0] = n0,dp[1] = n1;
        }
        return min(dp[0],dp[1]);
    }
    //�ռ临�Ӷ�O(1)
     int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        int dp[2] = {0,1};
        for(int i = 1; i < len; i++)
        {
            int n0 = dp[0],n1 = dp[1];
            if(A[i] > A[i-1] && B[i] > B[i-1])//ǰһ��û�н�������һ�в���Ҫ����
            {
                if( A[i] > B[i-1] &&  B[i] > A[i-1] )//ǰһ�з�����������һ�в���Ҫ����
                {
                    //ȡ��һ�����������Сֵ
                    dp[0] = min(n0,n1);
                    dp[1] = dp[0] + 1;
                }
                else//ǰһ�з�����������һ����Ҫ����
                    dp[1]++;
            }
            else//��һ����Ҫ����
            {
                dp[1] = dp[0] + 1;
                dp[0] = n1; 
            }

        }
        return min(dp[0],dp[1]);
    }
};
