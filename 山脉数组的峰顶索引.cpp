���ǰѷ����������Ե�����?A?����ɽ����

A.length >= 3
���� 0 < i?< A.length - 1 ʹ��A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
����һ��ȷ��Ϊɽ�������飬�����κ�����?A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]?�� i?��ֵ��

?

ʾ�� 1��

���룺[0,1,0]
�����1
ʾ�� 2��

���룺[0,2,1,0]
�����1
?

��ʾ��

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A �����϶����ɽ��


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int le = 0;
        int ri = A.size() - 1;

        while(le < ri)
        {
            int mid = (le + ri) / 2;

            //mid����ɽ�������
            if(A[mid - 1] < A[mid] && A[mid] < A[mid+1])
                le = mid + 1;
            else if(A[mid - 1] > A[mid] && A[mid] > A[mid + 1])//mid����ɽ���Ҳ�
                ri = mid;
            else if(A[mid - 1] < A[mid] && A[mid] >= A[mid + 1])
                return mid;
        }

        return le;
    }
};
