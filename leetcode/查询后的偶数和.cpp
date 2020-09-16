����һ����������?A?��һ����ѯ����?queries��

���ڵ�?i?�β�ѯ����?val =?queries[i][0], index?= queries[i][1]�����ǻ��?val?�ӵ�?A[index]?�ϡ�Ȼ�󣬵�?i?�β�ѯ�Ĵ��� A ��ż��ֵ�ĺ͡�

���˴�������?index = queries[i][1]?�Ǵ� 0 ��ʼ��������ÿ�β�ѯ���������޸�����?A����

�������в�ѯ�Ĵ𰸡���Ĵ�Ӧ��������?answer?������answer[i]?Ϊ��?i?�β�ѯ�Ĵ𰸡�

?

ʾ����

���룺A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
�����[8,6,2,4]
���ͣ�
��ʼʱ������Ϊ [1,2,3,4]��
�� 1 �ӵ� A[0] ��֮������Ϊ [2,2,3,4]��ż��ֵ֮��Ϊ 2 + 2 + 4 = 8��
�� -3 �ӵ� A[1] ��֮������Ϊ [2,-1,3,4]��ż��ֵ֮��Ϊ 2 + 4 = 6��
�� -4 �ӵ� A[0] ��֮������Ϊ [-2,-1,3,4]��ż��ֵ֮��Ϊ -2 + 4 = 2��
�� 2 �ӵ� A[3] ��֮������Ϊ [-2,-1,3,6]��ż��ֵ֮��Ϊ -2 + 6 = 4��
?

��ʾ��

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto num : A) 
            if(num % 2 == 0) {
                sum += num;
            }
        int n = queries.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            int num = val + A[index];
            if(A[index] % 2 == 0)   sum -= A[index];
            
            A[index] += val;
            if(A[index] % 2 == 0)   sum += A[index];
            ans.push_back(sum);
        }
        return ans;
    }
};
