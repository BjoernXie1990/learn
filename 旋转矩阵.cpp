//����һ���� N �� N �����ʾ��ͼ������ÿ�����صĴ�СΪ 4 �ֽڡ��������һ���㷨����ͼ����ת 90 �ȡ�

//��ռ�ö����ڴ�ռ��ܷ�������

//?

//ʾ�� 1:

//���� matrix = 
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],

//ԭ����ת�������ʹ���Ϊ:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//ʾ�� 2:

//���� matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//], 

//ԭ����ת�������ʹ���Ϊ:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]


class Solution {
public:
    //�ռ临�Ӷ�O(n*n)
    void rotate1(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;
        int n = matrix.size();
        int row = n-1;
        for(int i = 0; i < n; i++)//��i��
        {
            for(int j = 0; j < n; j++)//��j��
                tmp[j][i] = matrix[row][j];
            row--;
        }
            
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                matrix[i][j] = tmp[i][j];
    }
    
    //��ʹ�ö���ռ�
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            // \ �Խ�����ת
            for(int j = 0; (j + i) < n; j++)
                swap(matrix[i][i+j],matrix[i+j][i]);

            //������i��Ԫ��
            for(int j = 0; j < n / 2; j++)
                swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
};
