class Solution {
public:
    typedef pair<int,int> PII;
    int largestSubmatrix(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> f(m,0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            
            for(int j = 0;  j < m; j++)
                if(arr[i][j] == 1) f[j]++;
                else f[j] = 0;
            
            vector<int> t = f;
            sort(t.begin(),t.end());
            
            for(int j = 0; j < m; j++) {
                if(t[j] == 0) continue;
                int w = m - j;
                res = max(res,t[j] * w);
                
            }
        }
        return res;
    }
};

����һ�������ƾ���?matrix?�����Ĵ�СΪ?m x n?������Խ� matrix?�е� ��?������˳���������С�

���㷵�����ŷ����½� matrix?�������к�ȫ�� 1?���Ӿ��������

?

ʾ�� 1��



���룺matrix = [[0,0,1],[1,1,1],[1,0,1]]
�����4
���ͣ�����԰�����ͼ��ʽ�������о����ÿһ�С�
����ȫ 1 �Ӿ�������ͼ�мӴֵĲ��֣����Ϊ 4 ��
ʾ�� 2��



���룺matrix = [[1,0,1,0,1]]
�����3
���ͣ�����԰�����ͼ��ʽ�������о����ÿһ�С�
����ȫ 1 �Ӿ�������ͼ�мӴֵĲ��֣����Ϊ 3 ��
ʾ�� 3��

���룺matrix = [[1,1,0],[1,0,1]]
�����2
���ͣ�������ֻ���������������Ų�������û�б����Ϊ 2 �����ȫ 1 �Ӿ��Ρ�
ʾ�� 4��

���룺matrix = [[0,0],[0,0]]
�����0
���ͣ����ھ�����û�� 1 ��û���κ�ȫ 1 ���Ӿ����������Ϊ 0 ��
?

��ʾ��

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j]?Ҫô��?0?��Ҫô��?1 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
