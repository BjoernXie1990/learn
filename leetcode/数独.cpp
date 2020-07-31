��дһ������ͨ�������Ŀո�������������⡣

һ�������Ľⷨ����ѭ���¹���

����?1-9?��ÿһ��ֻ�ܳ���һ�Ρ�
����?1-9?��ÿһ��ֻ�ܳ���һ�Ρ�
����?1-9?��ÿһ���Դ�ʵ�߷ָ���?3x3?����ֻ�ܳ���һ�Ρ�
�հ׸���?'.'?��ʾ��



һ��������



�𰸱���ɺ�ɫ��

Note:

��������������ֻ��������?1-9?���ַ�?'.'?��
����Լ������������ֻ��Ψһ�⡣
����������Զ��?9x9?��ʽ�ġ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sudoku-solver
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
private:
    vector<vector<bool> > row;
    vector<vector<bool> > col;
    vector<vector<bool> > block;

public:
    Solution()
    {
        row     =   vector<vector<bool> > (9,vector<bool> (9,false));
        col     =   vector<vector<bool> > (9,vector<bool> (9,false));
        block   =   vector<vector<bool> > (9,vector<bool> (9,false));
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')  continue;

                //[i][j] == 1,2,...9
                int num = board[i][j] - '1';//0,1...,8
                row[i][num] = true;
                col[j][num] = true;
                block[i / 3 * 3 + j / 3][num] = true;
            }
        
        dfs(board,0,0);
    }

    bool dfs(vector<vector<char> >& board,int x,int y)
    {  
        //�ӵ�ǰ�п�ʼ���ҵ�һ����λ
        while(board[x][y] != '.')
        {
            if(++y >= 9)
            {
                x++;
                y = 0;
            }

            if(x >= 9)  return true;
        }

        for(int i = 0; i < 9; i++)
        {
            int block_idx = x / 3 * 3 + y / 3;
            //�ų��������������
            if(row[x][i] || col[y][i] || block[block_idx][i])   continue;
            
            //��x,y ���� i
            board[x][y] = i + '1';
            row[x][i] = true;
            col[y][i] = true;
            block[block_idx][i] = true;

            if(dfs(board,x,y) == true)
                return true;
            
            //i ���ʺϵ�ǰλ�ã�����
            board[x][y] = '.';
            row[x][i] = false;
            col[y][i] = false;
            block[block_idx][i] = false;
        }

        return false;
    }
};
