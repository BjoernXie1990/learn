int f[8][8][8][8][200];

class Solution {
public:
    int n,m,cjump,mjump;
    vector<string> g;
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    bool dp(int ci,int cj,int mi,int mj,int k) {
        if(k >= 200) return 0;
        auto& v = f[ci][cj][mi][mj][k];
        if(v != -1) return v;

        if(k & 1) {    // è
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j <= cjump; j++) {
                    int x = ci + dir[i][0] * j, y = cj + dir[i][1] * j;
                    if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#') break;
                    if(x == mi && y == mj) return v = 0;
                    if(g[x][y] == 'F') return v = 0;
                    if(!dp(x,y,mi,mj,k+1)) return v = 0;
                }
            }
            return v = 1;
        }

        // ����
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j <= mjump; j++) {
                int x = mi + dir[i][0] * j, y = mj + dir[i][1] * j;
                if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#') break;
                if(x == ci && y == cj) continue;
                if(g[x][y] == 'F') return v = 1;
                if(dp(ci,cj,x,y,k+1)) return v = 1;
            }
        }
        return v = 0;
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        g = grid;
        n = grid.size(), m = grid[0].size(), cjump = catJump, mjump = mouseJump;
        memset(f,-1,sizeof f);
        int ci,cj,mi,mj;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'C') ci = i, cj = j;
                else if(grid[i][j] == 'M') mi = i, mj = j;
        return dp(ci,cj,mi,mj,0);
    }
};

һֻè��һֻ��������һ������è���������Ϸ��

���������Ļ����趨��һ��?rows x cols?�ķ��� grid?������ÿ�����ӿ�����һ��ǽ��һ��ذ塢һλ��ң�è�������󣩻���ʳ�

������ַ�?'C'?������è����?'M'?���������󣩱�ʾ��
�ذ����ַ�?'.'?��ʾ����ҿ���ͨ��������ӡ�
ǽ���ַ�?'#'?��ʾ����Ҳ���ͨ��������ӡ�
ʳ�����ַ�?'F'?��ʾ����ҿ���ͨ��������ӡ�
�ַ�?'C'?��?'M'?��?'F'?��?grid?�ж�ֻ�����һ�Ρ�
è�����������¹����ƶ���

���� ���ƶ�?��Ȼ��������������ƶ���
ÿһ�β���ʱ��è����������������������ĸ�����֮һ�ĸ��ӣ����ǲ�������ǽҲ��������?grid?��
catJump ��?mouseJump?��è������ֱ���һ���ܵ������Զ���룬����Ҳ������С��������ĳ��ȡ�
���ǿ���ͣ����ԭ�ء�
���������Ծ��è��λ�á�
��Ϸ�� 4 �ַ�ʽ�������

���è����������ͬ��λ�ã���ôè��ʤ��
���è�ȵ���ʳ���ôè��ʤ��
��������ȵ���ʳ���ô�����ʤ��
����������� 1000 �β������ڵ���ʳ���ôè��ʤ��
����?rows x cols?�ľ���?grid?����������?catJump?��?mouseJump?��˫������ȡ���Ų��ԣ���������ʤ����ô���㷵��?true?�����򷵻� false?��

?

ʾ�� 1��



���룺grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
�����true
���ͣ�è�޷�ץ������Ҳû���������ȵ���ʳ�
ʾ�� 2��



���룺grid = ["M.C...F"], catJump = 1, mouseJump = 4
�����true
ʾ�� 3��

���룺grid = ["M.C...F"], catJump = 1, mouseJump = 3
�����false
ʾ�� 4��

���룺grid = ["C...#","...#F","....#","M...."], catJump = 2, mouseJump = 5
�����false
ʾ�� 5��

���룺grid = [".M...","..#..","#..#.","C#.#.","...#F"], catJump = 3, mouseJump = 1
�����true
?

��ʾ��

rows == grid.length
cols = grid[i].length
1 <= rows, cols <= 8
grid[i][j] ֻ�����ַ�?'C'?��'M'?��'F'?��'.'?��?'#'?��
grid?��ֻ����һ��?'C'?��'M'?��?'F'?��
1 <= catJump, mouseJump <= 8

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/cat-and-mouse-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
