class unionFind {
    public:
        unionFind(int n) :f(n){
            cnt = n;
            for(int i = 1; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            f[x] = y;
            cnt --;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        unionFind uf(n * n * 4);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int idx = (i * n + j) * 4;
                if(i + 1 < n) uf.merge(idx + 3,idx + 4 * n + 1);
                if(j + 1 < n) uf.merge(idx + 2,idx + 4);

                char oper = grid[i][j];
                if(oper == ' ') {
                    uf.merge(idx,idx + 1);
                    uf.merge(idx + 1,idx + 2);
                    uf.merge(idx + 2,idx + 3);
                } else if(oper == '/') {
                    uf.merge(idx,idx + 1);
                    uf.merge(idx + 2,idx + 3);
                } else if(oper == '\\') {
                    uf.merge(idx,idx + 3);
                    uf.merge(idx + 1,idx + 2);
                }
            }
        
        return uf.get();
    }
};


���� 1 x 1 ������ɵ� N x N ����?grid �У�ÿ�� 1 x 1?������ /��\ ��ո񹹳ɡ���Щ�ַ��Ὣ���黮��ΪһЩ���ߵ�����

����ע�⣬��б���ַ���ת��ģ���� \ �� "\\"?��ʾ������

�����������Ŀ��

?

ʾ�� 1��

���룺
[
? " /",
? "/ "
]
�����2
���ͣ�2x2 �������£�

ʾ�� 2��

���룺
[
? " /",
? "  "
]
�����1
���ͣ�2x2 �������£�

ʾ�� 3��

���룺
[
? "\\/",
? "/\\"
]
�����4
���ͣ�������һ�£���Ϊ \ �ַ���ת��ģ����� "\\/" ��ʾ \/���� "/\\" ��ʾ /\����
2x2 �������£�

ʾ�� 4��

���룺
[
? "/\\",
? "\\/"
]
�����5
���ͣ�������һ�£���Ϊ \ �ַ���ת��ģ����� "/\\" ��ʾ /\���� "\\/" ��ʾ \/����
2x2 �������£�

ʾ�� 5��

���룺
[
? "//",
? "/ "
]
�����3
���ͣ�2x2 �������£�

?

��ʾ��

1 <= grid.length == grid[0].length <= 30
grid[i][j] ��?'/'��'\'����?' '��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/regions-cut-by-slashes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
