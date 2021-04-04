class Solution {
public:
    bool squareIsWhite(string s) {
        vector<vector<bool> > f(8,vector<bool> (8,false));
        
        for(int i = 0 ; i < 8; i ++) {
            if(i & 1) {
                f[i][0] = true;
            } else {
                f[i][0] = false;
            }
            
            for(int j = 1; j < 8; j++)
                f[i][j] = !f[i][j - 1];
        }
        
        int r = s[0] - 'a', c = s[1] - '1';
        
        return f[r][c];
    }
};


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + coordinates[1]) % 2;
    }
};

����һ������?coordinates?������һ���ַ�������ʾ��������������һ�����ӵ����ꡣ��ͼ�ǹ�����������ʾ��ͼ��



����������ӵ���ɫ�ǰ�ɫ�����㷵��?true������Ǻ�ɫ���뷵��?false?��

��������һ�������������������һ�����ڵĸ��ӡ������һ���ַ�����ĸ���ڶ����ַ������֡�

?

ʾ�� 1��

���룺coordinates = "a1"
�����false
���ͣ�����ͼ������ʾ��"a1" ����ĸ����Ǻ�ɫ�ģ����Է��� false ��
ʾ�� 2��

���룺coordinates = "h3"
�����true
���ͣ�����ͼ������ʾ��"h3" ����ĸ����ǰ�ɫ�ģ����Է��� true ��
ʾ�� 3��

���룺coordinates = "c7"
�����false
?

��ʾ��

coordinates.length == 2
'a' <= coordinates[0] <= 'h'
'1' <= coordinates[1] <= '8'

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
