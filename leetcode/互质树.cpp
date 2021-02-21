class Solution {
public:
    int n;
    unordered_map<int,set<int> > mp;
    vector<int> res;
    vector<int> nums;
    
    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        n = _nums.size();
        nums = _nums;
        for(auto& e : edges) {
            mp[e[0]].insert(e[1]);
            mp[e[1]].insert(e[0]);
        }
        
        res.resize(n, -1);
        
        dfs(0,-1,vector<int> (51,-1));
        
        return res;
    }
    
    int gcd(int a,int b) {
        if(a < b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a % b);
    }
    
    void dfs(int v,int u,vector<int> f) {
        int cur = nums[v];
        res[v] = f[cur];
        
        for(int i = 1; i <= 50; i++)
            if(gcd(cur,i) == 1) {
                f[i] = v;
            }

        for(auto& e : mp[v]) {
            if(e == u) continue;
            dfs(e,v,f);
        }
        
    }
};


const int N = 1e5 + 10, M = 2 * N;
int h[N],e[M],ne[M],id;
int depth[N];

class Solution {
public:
    vector<int> nums,res,pos;
    vector<vector<int> > g; // �������Ĺ�ϵ

    void add(int u,int v) {
        e[id] = v, ne[id] = h[u], h[u] = id ++;
    }

    int gcd(int a,int b) {
        //if(a < b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a % b);
    }

    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        int n = _nums.size();
        memset(h,-1,sizeof h);
        id = 0;

        for(auto& e : edges) {
            int a = e[0], b = e[1];
            add(a,b), add(b,a);
        }

        g.resize(55);
        for(int i = 1; i <= 50; i++)
            for(int j = 1; j <= 50; j++)
                if(gcd(i,j) == 1)
                    g[i].push_back(j);
        
        res.resize(n,-1);
        pos.resize(55, -1);
        depth[0] = 0;

        dfs(0,-1);

        return res;
    }

    void dfs(int v,int fa) {
        int x = nums[v];
        for(auto& e : g[x])
            if(pos[e] != -1) 
                if(res[v] == -1 || depth[pos[e]] > depth[res[v]])
                    res[v] = pos[e];

        int pre = pos[x];
        pos[x] = v;
        for(int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if(j == fa) continue;
            depth[j] = depth[v] + 1;

            dfs(j,v);
        }
        pos[x] = pre;
    }
};


����һ�� n?���ڵ������Ҳ����һ���޻���ͨ����ͼ�����ڵ��Ŵ� 0?�� n - 1?����ǡ���� n - 1?���ߣ�ÿ���ڵ���һ��ֵ������ ���ڵ�?Ϊ 0 �ŵ㡣

����һ����������?nums?��һ����ά����?edges?����ʾ�������nums[i]?��ʾ��?i?�����ֵ��edges[j] = [uj, vj]?��ʾ�ڵ�?uj?�ͽڵ�?vj?��������һ���ߡ�

��?gcd(x, y) == 1?�����ǳ�������?x ��?y?�� ���ʵ�?������?gcd(x, y)?�� x?�� y?�� ���Լ��?��

�ӽڵ�?i?�� ��?���·���ϵĵ㶼�ǽڵ� i?�����Ƚڵ㡣һ���ڵ� ���� ���Լ������Ƚڵ㡣

���㷵��һ����СΪ n?������ ans?������?ans[i]����ڵ�?i?��������Ƚڵ�������?nums[i] ��?nums[ans[i]]?�� ���ʵ�?��������������������Ƚڵ㣬ans[i]?Ϊ -1?��

?

ʾ�� 1��



���룺nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
�����[-1,0,0,1]
���ͣ���ͼ�У�ÿ���ڵ��ֵ�������б�ʾ��
- �ڵ� 0 û�л������ȡ�
- �ڵ� 1 ֻ��һ�����Ƚڵ� 0 �����ǵ�ֵ�ǻ��ʵģ�gcd(2,3) == 1����
- �ڵ� 2 ���������Ƚڵ㣬�ֱ��ǽڵ� 1 �ͽڵ� 0 ���ڵ� 1 ��ֵ������ֵ���ǻ��ʵģ�gcd(3,3) == 3�����ڵ� 0 ��ֵ�ǻ��ʵ�(gcd(2,3) == 1)�����Խڵ� 0 ������ķ���Ҫ������Ƚڵ㡣
- �ڵ� 3 ���������Ƚڵ㣬�ֱ��ǽڵ� 1 �ͽڵ� 0 ������ڵ� 1 ���ʣ�gcd(3,2) == 1�������Խڵ� 1 ����������ķ���Ҫ������Ƚڵ㡣
ʾ�� 2��



���룺nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
�����[-1,0,-1,0,0,0,-1]
?

��ʾ��

nums.length == n
1 <= nums[i] <= 50
1 <= n <= 105
edges.length == n - 1
edges[j].length == 2
0 <= uj, vj < n
uj != vj

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/tree-of-coprimes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
