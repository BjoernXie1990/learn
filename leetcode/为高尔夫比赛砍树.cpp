class Solution {
public:
    struct node {
        int _x;
        int _y;
        int _v;
    };

    int n = 0;
    int m = 0;
    
    int vis[55][55];
    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();

        // >0 ��¼
        node nums[55*55];
        int len = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(forest[i][j] > 0) nums[len++] = {i,j,forest[i][j]};
        sort(nums,nums + len,[](const auto& a,const auto& b)->bool {
            return a._v < b._v;
        });

        int ans = 0;
        int ret = BFS(forest,0,0,nums[0]._x,nums[0]._y);
        if(ret == -1) return -1;
        ans += ret;

        for(int i = 0; i < len-1; i++) {
            ret = BFS(forest,nums[i]._x,nums[i]._y,nums[i+1]._x,nums[i+1]._y);
            if(ret == -1) return -1;
            ans += ret;
        }

        return ans;
    }

    int BFS(vector<vector<int> >& forest,int x,int y,int r,int c) {
        static int dir[4][2] = {1,0,-1,0,0,-1,0,1};
        int ret = 0;
        if(x == r && y == c) return ret;
        using key = pair<int,int>;
        queue<key> que;
        que.push(make_pair(x,y));
        memset(vis,0x00,sizeof(vis));

        while(que.empty() == false) {
            int size = que.size();
            ret++;

            while(size --) {
                auto f = que.front();
                que.pop();

                for(int i = 0; i < 4; i++) {
                    int tx = f.first + dir[i][0];
                    int ty = f.second + dir[i][1];
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m 
                        || vis[tx][ty] == 1 || forest[tx][ty] == 0) continue;
                    
                    if(tx == r && ty == c) return ret;
                    que.push(make_pair(tx,ty));
                    vis[tx][ty] = 1;
                }
            }
        }

        return -1;
    }
};


�㱻������һ��Ҫ�ٰ�߶�����������ֿ���. ������һ���Ǹ��Ķ�ά�����ʾ�� ����������У�

0 ��ʾ�ϰ����޷�������.
1?��ʾ�������ߵĵ���.
�� 1 �����?��ʾһ�������߹������ĸ߶�.
ÿһ�����㶼�������ϡ��¡������ĸ�����֮һ�ƶ�һ����λ�������վ�ĵط���һ��������ô����Ծ����Ƿ�Ҫ��������

�㱻Ҫ�������ĸ߶ȴӵ���߿������е�����ÿ����һ���������ĸ߶ȱ�Ϊ 1 ��

�㽫�ӣ�0��0���㿪ʼ��������Ӧ�÷����㿳����������Ҫ�ߵ���С������ ������޷��������е��������� -1 ��

���Ա�֤���ǣ�û���������ĸ߶�����ͬ�ģ�������������Ҫ����һ������

?

ʾ��?1:

����: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
���: 6
ʾ��?2:

����: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
���: -1
ʾ��?3:

����: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
���: 6
����: (0,0) λ�õ����������ֱ�ӿ�ȥ�������㲽��
?

��ʾ��

1 <= forest.length <= 50
1 <= forest[i].length <= 50
0 <= forest[i][j]?<= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/cut-off-trees-for-golf-event
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
