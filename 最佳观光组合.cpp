��������������?A��A[i]?��ʾ�� i ���۹⾰������֣�������������?i ��?j?֮��ľ���Ϊ?j - i��

һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ��A[i] + A[j] + i?- j�������������֮�ͼ�ȥ��������֮��ľ��롣

����һ�Թ۹⾰����ȡ�õ���߷֡�

?

ʾ����

���룺[8,1,5,2,6]
�����11
���ͣ�i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
?

��ʾ��

2 <= A.length <= 50000
1 <= A[i] <= 1000

class Solution {
public:


    //A[i] + A[j] + i - j   -->   A[i] + i +   A[j] - j
    int maxScoreSightseeingPair(vector<int>& A) {
        int le = A[0];
        int ans = A[0];

        int len = A.size();
        for(int i = 1; i < len; i++)
        {  
            ans = max(ans,le + A[i] - i);
            le = max(le,A[i] + i);
        }

        return ans;
    }
};
