����һ��Ԫ�ض���������������A?�������� L?�Լ�?R?(L <= R)��

���������ǿ����������Ԫ��������ڵ���L?С�ڵ���R�������������

���� :
����: 
A = [2, 1, 4, 3]
L = 2
R = 3
���: 3
����: ����������������: [2], [2, 1], [3].
ע��:

L, R? ��?A[i] ������������Χ��?[0, 10^9]��
����?A?�ĳ��ȷ�Χ��[1, 50000]��


class Solution {
public:
    int numSubarrayBoundedMax1(vector<int>& A, int L, int R) {
        int n = A.size();

        int ans = 0;
        int pre = -1;
        int le = -1;

        for(int i = 0; i < n; i++) {
            if(A[i] >= L && A[i] <= R){
                ans += i - le;
                pre = i;
            } else if (A[i] < L) {
                if(pre > le) ans += pre - le;
            } else {
                le = i;
            }
        }

        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return check(A,R) - check(A,L-1);
    }

    int check(vector<int>& A,int num) {
        int n = A.size();
        int sum = 0;
        int ret = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] <= num) {
                sum++;
                ret += sum;
            } else {
                sum = 0;
            }
        }

        return ret;
    }
};
