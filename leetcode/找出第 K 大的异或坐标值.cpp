class Solution {
public:
    int kthLargestValue(vector<vector<int>>& ma, int k) {
        int n = ma.size(), m = ma[0].size();
        vector<vector<int> > f(n+1,vector<int> (m + 1, 0));
        priority_queue<int> pq;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                f[i][j] = ma[i-1][j-1] ^ f[i-1][j-1] ^ f[i][j-1] ^ f[i-1][j];
                pq.push(f[i][j]);
            }
        }
        
        
        int res = 0;
        while(k --) {
            res= pq.top();
            pq.pop();
        }
        return res;
    }
};


����һ����ά���� matrix ��һ������ k �������СΪ?m x n �ɷǸ�������ɡ�

���������� (a, b) �� ֵ ���ɶ��������� 0 <= i <= a < m �� 0 <= j <= b < n ��Ԫ�� matrix[i][j]���±�� 0 ��ʼ������ִ���������õ���

�����ҳ�?matrix �����������е� k ���ֵ��k ��ֵ�� 1 ��ʼ��������

?

ʾ�� 1��

���룺matrix = [[5,2],[1,6]], k = 1
�����7
���ͣ����� (0,1) ��ֵ�� 5 XOR 2 = 7 ��Ϊ����ֵ��
ʾ�� 2��

���룺matrix = [[5,2],[1,6]], k = 2
�����5
���ͣ����� (0,0) ��ֵ�� 5 = 5 ��Ϊ�� 2 ���ֵ��
ʾ�� 3��

���룺matrix = [[5,2],[1,6]], k = 3
�����4
���ͣ����� (1,0) ��ֵ�� 5 XOR 1 = 4 ��Ϊ�� 3 ���ֵ��
ʾ�� 4��

���룺matrix = [[5,2],[1,6]], k = 4
�����0
���ͣ����� (1,1) ��ֵ�� 5 XOR 2 XOR 1 XOR 6 = 0 ��Ϊ�� 4 ���ֵ��
?

��ʾ��

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
