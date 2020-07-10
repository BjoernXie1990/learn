���ǰ����� A �з����������Ե��������������� B ��Ϊ ��ɽ������

B.length >= 3
���� 0 < i?< B.length - 1 ʹ�� B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
��ע�⣺B ������ A �����������飬������������ A����

����һ���������� A������� ��ɽ����?�ĳ��ȡ�

��������� ��ɽ����?�򷵻� 0��

?

ʾ�� 1��

���룺[2,1,4,7,3,2,5]
�����5
���ͣ���� ��ɽ���� �� [1,4,7,3,2]������Ϊ 5��
ʾ�� 2��

���룺[2,2,2]
�����0
���ͣ����� ��ɽ������
?

��ʾ��

0 <= A.length <= 10000
0 <= A[i] <= 10000

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if(len < 3) return 0;

        int ans = 0;
        for(int j = 1; j < len - 1; j++)
        {
            if(A[j] <= A[j-1] || A[j] <= A[j+1])
                continue;
            
            //�� i λ����������չ
            int l = j;
            int r = j;
            while(l > 0 && A[l] > A[l - 1])
                l--;
            while(r < len - 1 && A[r] > A[r + 1])
                r++;
            ans = max(ans,(r-l+1));
        }
        return ans;
    }
};
