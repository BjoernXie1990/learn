class Solution {
public:
    int f[100020], cnt;
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    bool merge(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        f[x] = y;
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) return -1;
        for(int i = 0; i < n; i++) f[i] = i;
        cnt = n;

        for(auto& e : connections) {
            int x = e[0], y = e[1];
            if(merge(x,y)) cnt --;
        }

        return cnt - 1;
    }
};

����̫�����½�?n?̨��������ӳ�һ�����磬������ı�Ŵ�?0?��?n-1��������?connections?��ʾ������?connections[i] = [a, b]?�����˼����?a?��?b��

�����е��κ�һ̨�����������ͨ������ֱ�ӻ��߼�ӷ���ͬһ����������������һ̨�������

����������������ĳ�ʼ����?connections������԰ο�������ֱ̨�������֮������£�����������һ��δֱ���ļ������������㲢����ʹ���м��������ͨ��������ٲ�����������������ܣ��򷵻�?-1 ��?

?

ʾ�� 1��



���룺n = 4, connections = [[0,1],[0,2],[1,2]]
�����1
���ͣ����¼���� 1 �� 2 ֮������£��������嵽����� 1 �� 3 �ϡ�
ʾ�� 2��



���룺n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
�����2
ʾ�� 3��

���룺n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
�����-1
���ͣ������������㡣
ʾ�� 4��

���룺n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
�����0
?

��ʾ��

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1]?< n
connections[i][0] != connections[i][1]
û���ظ������ӡ�
��̨���������ͨ�������������ӡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
