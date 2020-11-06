class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int col[n+1][n+1];
        int row[n+1][n+1];
        memset(col,0x00,sizeof col);
        memset(row,0x00,sizeof row);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                col[i][j] = col[i-1][j] + matrix[i-1][j-1];
                row[i][j] = row[i][j-1] + matrix[i-1][j-1];
            }

        int size = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) continue;

                int x = i;
                int y = j;  // ���½�����
                for(int len = 0; (x < n) && (y < n); len++) {
                    // ��
                    int t1 = row[i+1][y+1] - row[i+1][j+1];
                    int t2 = row[x+1][y+1] - row[x+1][j+1];

                    // ��
                    int t3 = col[x+1][j+1] - col[i+1][j+1];
                    int t4 = col[x+1][y+1] - col[i+1][y+1];
                    x++,y++;
                    if(t1 + t2 + t3 + t4 != 0) continue;

                    if(len + 1 > size) {
                        ans = {i,j,len + 1};
                        size = len + 1;
                    }
                    
                }
            }
        
        return ans;
    }
};

����һ����������ÿ����Ԫ(����)�Ǻڼ��ס����һ���㷨���ҳ� 4 ���߽�Ϊ��ɫ���ص�����ӷ���

����һ������ [r, c, size] ������?r,?c?�ֱ�����ӷ������Ͻǵ��кź��кţ�size ���ӷ���ı߳������ж�������������ӷ��󣬷��� r ��С�ģ��� r ��ͬ������ c ��С���ӷ������������������ӷ��󣬷��ؿ����顣

ʾ�� 1:

����:
[
?  [1,0,1],
?  [0,0,1],
?  [0,0,1]
]
���: [1,0,2]
����: ������ 0 �����ɫ��1 �����ɫ����ֵ�Ԫ�ؼ�Ϊ��������������ӷ���
ʾ�� 2:

����:
[
?  [0,1,1],
?  [1,0,1],
?  [1,1,0]
]
���: [0,0,1]
��ʾ��

matrix.length == matrix[0].length <= 200

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/max-black-square-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
