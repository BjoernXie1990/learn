//����һ����ά�ľ��󣬰���?'X'?��?'O'����ĸ O����

//�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е�?'O' �� 'X' ��䡣

//ʾ��:

//X X X X
//X O O X
//X X O X
//X O X X
//������ĺ����󣬾����Ϊ��

//X X X X
//X X X X
//X X X X
//X O X X
//����:

//��Χ�Ƶ����䲻������ڱ߽��ϣ����仰˵���κα߽��ϵ�?'O'?�����ᱻ���Ϊ?'X'�� �κβ��ڱ߽��ϣ�����߽��ϵ�?'O'?������?'O'?���ն��ᱻ���Ϊ?'X'���������Ԫ����ˮƽ��ֱ�������ڣ���������ǡ��������ġ�



class Solution {
public:
    void solve(vector<vector<char>>& board) {
    if(board.empty()||board[0].empty()) return;
        //����������������������ı���������ÿ�����ı��ҵ�O�������������ȥ�����Ǳ�Ե�ҵ���O������ת��Ϊ"F"
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)
                    dfs(i,j,board);
            }
        } 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='F')
                    board[i][j]='O';
            }
        }    
    }
    void dfs(int col,int row,vector<vector<char>>& board)
    {
        if(col<0||col>board.size()-1||row<0||row>board[0].size()-1)
            return;
        if(board[col][row]=='X'||board[col][row]=='F')
            return;
        else if(board[col][row]=='O')
        {
            board[col][row]='F';
            dfs(col-1,row,board);
            dfs(col+1,row,board);
            dfs(col,row-1,board);
            dfs(col,row+1,board);
        }
    }
    
};
