class Solution {
public:
    int n;
    vector<bool> vis;
    vector<int> res;

    bool dfs(int m) {
        if(m == 2 * n - 1) return true;
        if(res[m]) return dfs(m + 1);

        for(int i = n; i > 1; i--) 
            if(!vis[i] && m + i < 2 * n - 1 && !res[m + i]) {
                res[m] = i; res[i + m] = i;
                vis[i] = true;
                if(dfs(m+1)) return true;
                vis[i] = false;
                res[m] = 0; res[i + m] = 0;
            }
        
        if(!vis[1]) {
            res[m] = 1; vis[1] = true;
            if(dfs(m + 1)) return true;
            res[m] = 0; vis[1] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        res.resize(2*n-1,0);
        vis.resize(n+1,false);

        dfs(0);

        return res;

    }
};

����һ������?n?�������ҵ���������������һ�����У�

����?1?��������ֻ����һ�Ρ�
2?��?n?֮��ÿ��������ǡ�ó������Ρ�
����ÿ��?2?��?n?֮�������?i?������?i?֮����ֵľ���ǡ��Ϊ?i?��
�������������� a[i]?�� a[j]?֮��� ����?�����Ƕ���Ϊ�����±����ֵ֮��?|j - i|?��

���㷵����������������?�ֵ������?�����С���Ŀ��֤�ڸ������������£�һ�����ڽ⡣

һ������?a?����Ϊ������?b?�����߳�����ͬ���ֵ������������ǣ�?a ��?b?�е�һ����һ�������ִ���a?���е����ֱ�?b?���е����ִ󡣱ȷ�˵��[0,1,9,0]?��?[0,1,5,6]?�ֵ��������Ϊ��һ����ͬ��λ���ǵ��������֣���?9?��?5?��

?

ʾ�� 1��

���룺n = 3
�����[3,1,2,3,2]
���ͣ�[2,3,2,1,3] Ҳ��һ�����е����У����� [3,1,2,3,2] ���ֵ����������С�
ʾ�� 2��

���룺n = 5
�����[5,3,1,4,3,5,2,4,2]
?

��ʾ��

1 <= n <= 20

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
