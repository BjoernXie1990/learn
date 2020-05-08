
//��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ��������������

//ʾ��:

//����: 

//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0

//���: 4


class Solution {
public:
    //��������
    int maximalSquare1(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                int area = slove(matrix,i,j,row,col);
                ans = max(area,ans);
            }
        
        return ans;
    }
    int slove(vector<vector<char> >& matrix,int x,int y,int row,int col)
    {
        int area = 1;
        int tx = x;
        int ty = y;
        while(tx+1 < row && ty + 1 < col)
        {
            tx++;
            ty++;
            int tmp = 0;
            //�ж����µ�
            for(int i = x; i <= tx; i++)
            {
                if(matrix[i][ty] == '0')
                    return area;
                tmp++;
            }

            //�ж�����
            for(int j = y; j < ty; j++)
            {
                if(matrix[tx][j] == '0')
                    return area;
                tmp++;
            }
            area += tmp;
        }
        return area;
    }

    //��̬�滮
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int ans = 0;
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();

        //dp[i][j]   ��ʾ��matrix[i][j]Ϊ���½�Ԫ�ص����߳�
        vector<vector<int>> dp(row,vector<int> (col,0));
        // for(int i = 0; i < col; i++)
        //     if(matrix[0][i] == '1')
        //     {
        //         dp[0][i] = 1;
        //         ans = 1;
        //     }
            
        // for(int j = 0; j < row; j++)
        //     if(matrix[j][0] == '1')
        //     {
        //         dp[j][0] = 1;
        //         ans = 1;
        //     }

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1')
                {
                    if(i==0 || j==0)
                        dp[i][j] = 1; 
                    else
                        dp[i][j] = Threemin(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1;
                    
                    ans = max(dp[i][j],ans);
                }
        return ans * ans;
    }
    //����ȡС
    int Threemin(int a,int b,int c)
    {
        return min(min(a,b),c);
    }
};
