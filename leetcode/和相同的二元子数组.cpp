��������?0?��?1? ��ɵ�����?A?�У��ж��ٸ���Ϊ S?�ķǿ������顣

?

ʾ����

���룺A = [1,0,1,0,1], S = 2
�����4
���ͣ�
�����������ʾ���� 4 ��������ĿҪ��������飺
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
?

��ʾ��

A.length <= 30000
0 <= S <= A.length
A[i]?Ϊ?0?��?1

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int le = 0;
        int sum = 0;
        int n = A.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            
            while(le < i && sum > S){
                sum -= A[le];
                le++;
            }

            int idx = le;
            int tmp = sum;
            while(idx <= i && tmp == S){
                ans++;
                tmp -= A[idx++];
            }
        }

        return ans;
    }
};
