class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int> > mp(n);
        for(auto& e : graph) mp[e[0]].push_back(e[1]);

        queue<int> que;
        que.push(start);
        vector<bool> vis(n,false);
        vis[start] = true;

        while(!que.empty()) {
            int f = que.front();
            que.pop();

            for(auto& e : mp[f]) {
                if(vis[e]) continue;
                if(e == target) return true;
                vis[e] = true;
                que.push(e);
            }
        }

        return false;
    }
};

节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:

 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:

 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
提示：

节点数量n在[0, 1e5]范围内。
节点编号大于等于 0 小于 n。
图中可能存在自环和平行边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/route-between-nodes-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
