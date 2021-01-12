class Solution {
public:
    unordered_map<int,set<int> > mp;
    vector<int> f;
    int tt[100005];
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    
    
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        int n  = s.size();
        f.resize(n,0);
        for(int i = 0; i < n; i++) f[i]  =i;
        
        for(auto& e : a) {
            int x = find(e[0]);
            int y = find(e[1]);
            if(x != y) f[x] = y;
        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int x = find(i);
            mp[x].insert(i);
        }
        
        for(auto& e : mp) {
            auto& st = e.second;
            memset(tt,0x00,sizeof tt);
            
            for(auto& b : st) tt[s[b]]++;
            for(auto& b : st) {
                if(tt[t[b]]) {
                    tt[t[b]] --;
                    res ++;
                }
            }
        }
        
        return n- res;
    }
    
};

���������������� source �� target �����ȶ��� n ������һ������ allowedSwaps ������ÿ�� allowedSwaps[i] = [ai, bi] ��ʾ����Խ������� source ���±�Ϊ ai �� bi���±�� 0 ��ʼ��������Ԫ�ء�ע�⣬����԰� ���� ˳�� ��� ����һ���ض��±�ָ���Ԫ�ء�

��ͬ���ȵ���������?source �� target ��� �������� ��Ԫ�ز�ͬ���±���������ʽ�ϣ���ֵ��������?source[i] != target[i] ���±�� 0 ��ʼ�����±� i��0 <= i <= n-1����������

�ڶ����� source ִ�� ���� �����Ľ��������󣬷��� source �� target ��� ��С�������� ��

?

ʾ�� 1��

���룺source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
�����1
���ͣ�source ���԰�������ʽת����
- �����±� 0 �� 1 ָ���Ԫ�أ�source = [2,1,3,4]
- �����±� 2 �� 3 ָ���Ԫ�أ�source = [2,1,4,3]
source �� target ��ĺ��������� 1 �������� 1 ��Ԫ�ز�ͬ�����±� 3 ��
ʾ�� 2��

���룺source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
�����2
���ͣ����ܶ� source ִ�н���������
source �� target ��ĺ��������� 2 �������� 2 ��Ԫ�ز�ͬ�����±� 1 ���±� 2 ��
ʾ�� 3��

���룺source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
�����0
?

��ʾ��

n == source.length == target.length
1 <= n <= 105
1 <= source[i], target[i] <= 105
0 <= allowedSwaps.length <= 105
allowedSwaps[i].length == 2
0 <= ai, bi <= n - 1
ai != bi

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
