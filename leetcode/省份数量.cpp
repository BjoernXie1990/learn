class Solution {
public:
    int find(vector<int>& f,int x) {
        if(x != f[x]) f[x] = find(f,f[x]);
        return f[x];    
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> f(n);
        for(int i = 1; i < n; i++) f[i] = i;

        int res = n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(isConnected[i][j] == 0) continue;
                int x = find(f,i), y = find(f,j);
                if(x != y) {
                    f[x] = y;
                    res--;
                }
            }

        return res;
    }
};

�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������

ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�

����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������

���ؾ����� ʡ�� ��������

?

ʾ�� 1��


���룺isConnected = [[1,1,0],[1,1,0],[0,0,1]]
�����2
ʾ�� 2��


���룺isConnected = [[1,0,0],[0,1,0],[0,0,1]]
�����3
?

��ʾ��

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] Ϊ 1 �� 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-provinces
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
