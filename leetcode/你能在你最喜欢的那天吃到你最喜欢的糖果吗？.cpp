typedef long long LL;
const int N = 1e5 + 10;
LL f[N];

class Solution {
public:
    
    vector<bool> canEat(vector<int>& c, vector<vector<int>>& q) {
        memset(f,0x00,sizeof f);
        int n = q.size(), m = c.size();
        for(int i = 1; i <= m; i++) f[i] = c[i-1] + f[i-1];
        
        vector<bool> res(n);
        for(int i = 0; i < n; i++) {
            LL id = q[i][0], d = q[i][1], cnt = q[i][2];
            LL sum = (d + 1) * cnt;
            if(f[id] >= sum || d >= f[id + 1]) res[i] = false;
            else res[i] = true;
        }
        return res;
    }
};

����һ���±�� 0 ��ʼ������������?candiesCount?������?candiesCount[i]?��ʾ��ӵ�еĵ�?i?���ǹ�����Ŀ��ͬʱ����һ����ά����?queries?������?queries[i] = [favoriteTypei, favoriteDayi, dailyCapi]?��

�㰴�����¹������һ����Ϸ��

��ӵ�?0?�쿪ʼ���ǹ���
���ڳ��� ����?�� i - 1?���ǹ�֮ǰ������?���κ�һ�ŵ� i?���ǹ���
�ڳ��������ǹ�֮ǰ�������ÿ�� ����?�� һ��?�ǹ���
���㹹��һ������������?answer?������?answer.length == queries.length ��answer[i]?Ϊ?true?�������ǣ���ÿ��� ������ dailyCapi?���ǹ���ǰ���£�������ڵ�?favoriteDayi?��Ե���?favoriteTypei?���ǹ������� answer[i]?Ϊ false?��ע�⣬ֻҪ�������� 3 �������еĵڶ���������Ϳ�����ͬһ��Բ�ͬ���͵��ǹ���

���㷵�صõ�������?answer?��

?

ʾ�� 1��

���룺candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
�����[true,false,true]
��ʾ��
1- �ڵ� 0 ��� 2 ���ǹ�(���� 0������ 1 ��� 2 ���ǹ������� 0������ 2 ������ԳԵ����� 0 ���ǹ���
2- ÿ�������� 4 ���ǹ�����ʹ�� 0 ��� 4 ���ǹ������� 0������ 1 ��� 4 ���ǹ������� 0 ������ 1������Ҳû�취�ڵ� 2 ��Ե����� 4 ���ǹ�������֮����û����ÿ��� 4 ���ǹ����������ڵ� 2 ��Ե��� 4 ���ǹ���
3- �����ÿ��� 1 ���ǹ���������ڵ� 13 ��Ե����� 2 ���ǹ���
ʾ�� 2��

���룺candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
�����[false,true,true,false,false]
?

��ʾ��

1 <= candiesCount.length <= 105
1 <= candiesCount[i] <= 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= favoriteTypei < candiesCount.length
0 <= favoriteDayi <= 109
1 <= dailyCapi <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
