class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ad) {
        int n = ad.size() + 1;
        unordered_map<int,vector<int> > mp;
        
        for(auto& e : ad) {
            int x = e[0], y = e[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        
        int u = 0;
        for(auto& e : mp)
            if(e.second.size() == 1){
                u = e.first;
                break;
            }
        
        vector<int> res(n);
        res[0] = u;
        unordered_map<int,bool> vis;
        vis[u] = true;
        
        for(int i = 1; i < n; i++) {
            for(auto& e : mp[res[i-1]]) {
                if(vis[e] == false) {
                    res[i] = e;
                    vis[e] = true;
                }
            }
        }
        
        return res;
    }
};

����һ���� n ����ͬԪ����ɵ��������� nums �������Ѿ��ǲ���������ݡ������㻹�ǵ� nums �е�ÿһ������Ԫ�ء�

����һ����ά�������� adjacentPairs ����СΪ n - 1 ������ÿ�� adjacentPairs[i] = [ui, vi] ��ʾԪ�� ui �� vi �� nums �����ڡ�

��Ŀ���ݱ�֤������Ԫ�� nums[i] �� nums[i+1] ��ɵ�����Ԫ�ضԶ������� adjacentPairs �У�������ʽ������ [nums[i], nums[i+1]] ��Ҳ������ [nums[i+1], nums[i]] ����Щ����Ԫ�ضԿ��� ������˳�� ���֡�

���� ԭʼ���� nums ��������ڶ��ֽ�𣬷��� ��������һ�� ���ɡ�

?

ʾ�� 1��

���룺adjacentPairs = [[2,1],[3,4],[3,2]]
�����[1,2,3,4]
���ͣ��������������Ԫ�ضԶ��� adjacentPairs �С�
�ر�Ҫע����ǣ�adjacentPairs[i] ֻ��ʾ����Ԫ�����ڣ�������֤�� ��-�� ˳��
ʾ�� 2��

���룺adjacentPairs = [[4,-2],[1,4],[-3,1]]
�����[-2,4,1,-3]
���ͣ������п��ܴ��ڸ�����
��һ�ֽ���� [-3,1,4,-2] ��Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 3��

���룺adjacentPairs = [[100000,-100000]]
�����[100000,-100000]
?

��ʾ��

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
��Ŀ���ݱ�֤����һЩ��?adjacentPairs ��ΪԪ�ضԵ����� nums

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
