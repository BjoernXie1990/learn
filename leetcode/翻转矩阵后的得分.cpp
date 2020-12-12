class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        // ��
        for(int i = 0; i < n; i++) {
            if(A[i][0] == 1) continue;
            for(int j = 0; j < m; j++)  A[i][j] ^= 1;
        }

        // ��
        for(int i = 1; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) cnt += A[j][i];
            if(cnt <= n / 2) {
                for(int j = 0; j < n; j++) A[j][i] ^= 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int t = 0;
            for(int j = 0; j < m; j++) if(A[i][j]) t |= (1 << (m - j - 1));
            //cout << t << " ";
            ans += t;
        }

        return ans;
    }
};


��һ����ά����?A ����ÿ��Ԫ�ص�ֵΪ?0?��?1?��

�ƶ���ָѡ����һ�л��У���ת�����л����е�ÿһ��ֵ�������� 0 ������Ϊ 1�������� 1 ������Ϊ 0��

����������������ƶ��󣬽��þ����ÿһ�ж����ն������������ͣ�����ĵ÷־�����Щ���ֵ��ܺ͡�

���ؾ����ܸߵķ�����

?

ʾ����

���룺[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
�����39
���ͣ�
ת��Ϊ [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
?

��ʾ��

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j]?��?0 ��?1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/score-after-flipping-matrix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
