class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(),p.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            return a[0] < b[0];
        });

        int ans = 0;
        int pre = p[0][0];
        for(int i = 1; i < n; i++) ans = max(ans,p[i][0] - pre),pre = p[i][0];
        // set<int> st;
        // for(int i = 0; i < n; i++) st.insert(p[i][0]);
        
        // int ans = 0;
        // int pre = *(st.begin());
        // st.erase(pre);
        
        // for(auto& x : st)  {
        //     ans = max(ans,x - pre);
        //     pre = x;
        // }
        
        return ans;
    }
};

����?n?����άƽ���ϵĵ� points ������?points[i] = [xi, yi]?�����㷵������֮���ڲ��������κε��?���ֱ���?�Ŀ�ȡ�

��ֱ��� �Ķ����ǹ̶���ȣ��� y �������������һ������Ҳ���Ǹ߶�Ϊ����󣩡� ���ֱ���?Ϊ�������һ����ֱ�����

��ע�⣬��ֱ����?����?�ĵ�?����?�����ڡ�

?

ʾ�� 1��

?
���룺points = [[8,7],[9,9],[7,4],[9,7]]
�����1
���ͣ���ɫ�������ɫ��������������
ʾ�� 2��

���룺points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
�����3
?

��ʾ��

n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi?<= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/widest-vertical-area-between-two-points-containing-no-points
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
