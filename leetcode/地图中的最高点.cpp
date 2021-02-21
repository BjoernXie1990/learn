
class Solution {
public:
    int n,m;
    typedef pair<int,int> PII;
    vector<vector<int>> highestPeak(vector<vector<int>>& f) {
        n = f.size(), m = f[0].size();
        
        vector<vector<int> > res(n,vector<int> (m,-1));
        queue<PII> que;
        vector<vector<int> > d = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(f[i][j] == 1) {
                    res[i][j] = 0;
                    que.push({i,j});
                }
        
        while(que.size()) {
            int s = que.size();
            while(s --) {
                auto f = que.front();
                que.pop();
                
                for(int i = 0; i < 4; i++) {
                    int x = f.first + d[i][0], y = f.second + d[i][1];
                    if(x < 0 || y < 0 || x  >= n || y >= m || res[x][y] != -1) continue;
                    
                    res[x][y] = res[f.first][f.second] + 1;
                    que.push({x,y});
                }
            }
        }
        
        return res;
    }
};


����һ����СΪ?m x n?����������?isWater?����������һ���� ½��?�� ˮ��?��Ԫ����ɵĵ�ͼ��

���?isWater[i][j] == 0?������?(i, j)?��һ�� ½��?���ӡ�
���?isWater[i][j] == 1?������?(i, j)?��һ�� ˮ��?���ӡ�
����Ҫ�������¹����ÿ����Ԫ���Ÿ߶ȣ�

ÿ�����ӵĸ߶ȶ������ǷǸ��ġ�
���һ���������� ˮ��?����ô���ĸ߶ȱ���Ϊ 0?��
�������ڵĸ��Ӹ߶Ȳ� ����?Ϊ 1?���������������������ϡ��������������໥�����ţ��ͳ�����Ϊ���ڵĸ��ӡ���Ҳ����˵������һ�������ߣ�
�ҵ�һ�ְ��Ÿ߶ȵķ�����ʹ�þ����е���߸߶�ֵ?���?��

���㷵��һ����СΪ?m x n?���������� height?������ height[i][j]?�Ǹ��� (i, j)?�ĸ߶ȡ�����ж��ֽⷨ���뷵��?����һ��?��

?

ʾ�� 1��



���룺isWater = [[0,1],[0,0]]
�����[[1,0],[2,1]]
���ͣ���ͼչʾ�˸��������Ӱ��ŵĸ߶ȡ�
��ɫ������ˮ�����ɫ������½�ظ�
ʾ�� 2��



���룺isWater = [[0,0,1],[1,0,0],[0,0,0]]
�����[[1,1,0],[0,1,1],[1,2,2]]
���ͣ����а��ŷ����У���߿��и߶�Ϊ 2 ��
���ⰲ�ŷ����У�ֻҪ��߸߶�Ϊ 2 �ҷ�����������ģ���Ϊ���з�����
?

��ʾ��

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j]?Ҫô��?0?��Ҫô��?1?��
������ 1?��ˮ����ӡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/map-of-highest-peak
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
