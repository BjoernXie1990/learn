����һ������?A�����仮��Ϊ�������ཻ��û�й���Ԫ�أ�������������?left?��?right��?ʹ�ã�

left?�е�ÿ��Ԫ�ض�С�ڻ����?right?�е�ÿ��Ԫ�ء�
left ��?right?���Ƿǿյġ�
left?Ҫ������С��
����������ķ���󷵻�?left?�ĳ��ȡ����Ա�֤���������Ļ��ַ�����

?

ʾ�� 1��

���룺[5,0,3,8,6]
�����3
���ͣ�left = [5,0,3]��right = [8,6]
ʾ�� 2��

���룺[1,1,1,0,6,12]
�����4
���ͣ�left = [1,1,1,0]��right = [6,12]
?

��ʾ��

2 <= A.length?<= 30000
0 <= A[i] <= 10^6
���Ա�֤������һ�ַ����ܹ�����Ŀ�������������� A ���л��֡�


class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int len = A.size();

        int maxNum = A[0];
        int ans = 0;
        int leftMax = A[0];
        for(int i = 1; i < len; i++)
        {
            maxNum = max(maxNum,A[i]);
            if(A[i] < leftMax)
            {
                leftMax = maxNum;
                ans = i;
            }
        }

        return ans + 1;
    }
};
