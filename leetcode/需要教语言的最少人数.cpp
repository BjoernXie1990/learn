class Solution {
public:
    int f[510][510];
    int arr[510];
    int minimumTeachings(int n, vector<vector<int>>& la, vector<vector<int>>& fr) {
        memset(f,0x00,sizeof f);
        int m = la.size();
        for(int i = 1; i <= m; i++) {
            for(auto& e : la[i-1]) f[i][e] = 1;
        }
        
        vector<vector<int> > t;
        for(auto& e : fr) {
            int x = e[0], y = e[1];
            bool ret = false;
            for(int i = 1; i <= n; i++) {
                if(f[x][i] && f[y][i]) {
                    ret = true;
                    break;
                }
            }
            if(!ret) t.push_back(e);
        }
        
        int res = 600;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            
            memset(arr,0x00,sizeof arr);
            for(auto& e : t) {
                int x = e[0], y = e[1];
                if(f[x][i] == 0 && arr[x] == 0) {
                    cnt++;
                    arr[x] = 1;
                }
                if(f[y][i] == 0 && arr[y] == 0) {
                    cnt++;
                    arr[y] = 1;
                }
            }
            res = min(res,cnt);
        }
        
        return res;
    }
};

在一个由?m?个用户组成的社交网络里，我们获取到一些用户之间的好友关系。两个用户之间可以相互沟通的条件是他们都掌握同一门语言。

给你一个整数?n?，数组?languages?和数组?friendships?，它们的含义如下：

总共有?n?种语言，编号从?1 到?n?。
languages[i]?是第 i?位用户掌握的语言集合。
friendships[i] = [u??????i???, v??????i]?表示?u???????????i????? 和?vi?为好友关系。
你可以选择 一门?语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 最少?需要教会多少名用户。

请注意，好友关系没有传递性，也就是说如果?x 和?y?是好友，且?y?和?z?是好友，?x 和?z?不一定是好友。
?

示例 1：

输入：n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
输出：1
解释：你可以选择教用户 1 第二门语言，也可以选择教用户 2 第一门语言。
示例 2：

输入：n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
输出：2
解释：教用户 1 和用户 3 第三门语言，需要教 2 名用户。
?

提示：

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u??????i < v??????i <= languages.length
1 <= friendships.length <= 500
所有的好友关系?(u?????i, v??????i)?都是唯一的。
languages[i]?中包含的值互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-people-to-teach
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
