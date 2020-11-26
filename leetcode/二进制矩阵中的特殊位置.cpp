class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int r[n],c[m];
        memset(r,0x00,sizeof r);
        memset(c,0x00,sizeof c);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue;
                if(r[i] == 1 && c[j] == 1) ans++;
            }
        return ans;
    }
};

����һ����СΪ rows x cols �ľ��� mat������ mat[i][j] �� 0 �� 1���뷵�� ����?mat ������λ�õ���Ŀ ��

����λ�� ���壺��� mat[i][j] == 1 ���ҵ� i �к͵� j ���е���������Ԫ�ؾ�Ϊ 0���к��е��±�� �� 0 ��ʼ ������λ�� (i, j) ����Ϊ����λ�á�

?

ʾ�� 1��

���룺mat = [[1,0,0],
?           [0,0,1],
?           [1,0,0]]
�����1
���ͣ�(1,2) ��һ������λ�ã���Ϊ mat[1][2] == 1 ���������к�������������Ԫ�ض��� 0
ʾ�� 2��

���룺mat = [[1,0,0],
?           [0,1,0],
?           [0,0,1]]
�����3
���ͣ�(0,0), (1,1) �� (2,2) ��������λ��
ʾ�� 3��

���룺mat = [[0,0,0,1],
?           [1,0,0,0],
?           [0,1,1,0],
?           [0,0,0,0]]
�����2
ʾ�� 4��

���룺mat = [[0,0,0,0,0],
?           [1,0,0,0,0],
?           [0,1,0,0,0],
?           [0,0,1,0,0],
?           [0,0,0,1,1]]
�����3
?

��ʾ��

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] �� 0 �� 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
