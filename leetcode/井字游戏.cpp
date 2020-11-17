class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();

        // col
        for(int i = 0; i < n; i++) {
            bool flag = true;
            for(int j = 1; j < n; j++) {
                if(board[i][j] != board[i][j-1] || board[i][j] == ' ') {
                    flag = false;
                    break;
                }
            }
            if(flag) return board[i][0] == 'X' ? "X" : "O";
        }

        // row
        for(int i = 0; i < n; i++) {
            bool flag = true;
            for(int j = 1; j < n; j++) {
                if(board[j][i] != board[j-1][i] || board[j][i] == ' ') {
                    flag = false;
                    break;
                }
            }
            if(flag) return board[0][i] == 'X' ? "X" : "O";
        }

        if(n) {
            bool flag = true;
            for(int i = 1; i < n; i++)
                if(board[i][i] != board[i-1][i-1] || board[i][i] == ' ') {
                    flag = false;
                    break;
                }
            if(flag) return board[0][0]  == 'X' ? "X" : "O";

            flag = true;
            int r = 0;
            for(int i = n - 2; i >= 0; i--) {
                r++;
                if(board[r][i] != board[r - 1][i+1] || board[r][i] == ' ') {
                    flag = false;
                    break;
                }
            }
            if(flag) return board[0][n-1] == 'X' ? "X" : "O";
        }

        // Draw
        bool flag = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == ' ') {
                    flag = false;
                    break;
                }
        if(flag) return "Draw";
        return "Pending";
    }
};

���һ���㷨���ж�����Ƿ�Ӯ�˾�����Ϸ��������һ�� N x N ���������̣����ַ�" "��"X"��"O"��ɣ������ַ�" "����һ����λ��

�����Ǿ�����Ϸ�Ĺ���

����������ַ������λ��" "���С�
��һ��������Ƿ��ַ�"O"���ҵڶ���������Ƿ��ַ�"X"��
"X"��"O"ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
����N����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ��������Ӧ���ַ�����һ�ʤ��
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
�����Ϸ���ڻ�ʤ�ߣ��ͷ��ظ���Ϸ�Ļ�ʤ��ʹ�õ��ַ���"X"��"O"���������Ϸ��ƽ�ֽ������򷵻� "Draw"������Ի����ж�����Ϸδ���������򷵻� "Pending"��

ʾ�� 1��

���룺 board = ["O X"," XO","X O"]
����� "X"
ʾ�� 2��

���룺 board = ["OOX","XXO","OXO"]
����� "Draw"
���ͣ� û����һ�ʤ�Ҳ����ڿ�λ
ʾ�� 3��

���룺 board = ["OOX","XXO","OX "]
����� "Pending"
���ͣ� û����һ�ʤ���Դ��ڿ�λ
��ʾ��

1 <= board.length == board[i].length <= 100
����һ����ѭ���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/tic-tac-toe-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
