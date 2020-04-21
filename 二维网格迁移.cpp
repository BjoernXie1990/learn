//����һ�� m �� n?�еĶ�ά����?grid?��һ������?k������Ҫ��?grid?Ǩ��?k?�Ρ�

//ÿ�Ρ�Ǩ�ơ��������������������

//λ�� grid[i][j]?��Ԫ�ؽ����ƶ���?grid[i][j + 1]��
//λ��?grid[i][n?- 1] ��Ԫ�ؽ����ƶ���?grid[i + 1][0]��
//λ�� grid[m?- 1][n - 1]?��Ԫ�ؽ����ƶ���?grid[0][0]��
//���㷵��?k ��Ǩ�Ʋ��������յõ��� ��ά����



//ʾ�� 1��
//���룺grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//�����[[9,1,2],[3,4,5],[6,7,8]]

//ʾ�� 2��
//���룺grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
//�����[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        //����K��֮��ÿһ��Ԫ�ص��к�
        vector<int> c(col,0);
        for(int i = 0; i < col; i++){
            c[i] = (i + k) % col;
        }

        vector<vector<int> > ans(row,vector<int> (col,0));

        for(int j = 0; j < col; j++){
            //�жϵ�ǰ��Ԫ�ؾ���k��֮�󣬸ı��˶��ٴ�
            int path = 0;
            int tmp = j;
            for(int i = 0; i < k; i++){
                tmp = (tmp + 1) % col;
                path += (tmp == 0) ? 1 : 0;
            }

            for(int i = 0; i < row; i++){
                int x = (i + path) % row;
                ans[x][c[j]] = grid[i][j];
            }
        }

        return ans;
    }
};
