class Solution {
public:
    int maxValue(vector<vector<int>>& eve, int k) {
        int n = eve.size();
        sort(eve.begin(),eve.end(),[](const auto& a,const auto& b)->bool{
            return a[1] < b[1];
        });
        int f[n+1][k+1];
        memset(f,0x00,sizeof f);
        
        int res = 0;
        for(int i = 1; i <= n; i++) {
            int le = 0, ri = i - 1;
            while(le < ri) {
                int mid = le + ri + 1 >> 1;
                if(eve[mid-1][1] < eve[i-1][0]) le = mid;
                else ri = mid - 1;
            }
            for(int j = 1; j <= k; j++) {
                f[i][j] = max(f[i-1][j],f[le][j - 1] + eve[i-1][2]);
                res = max(f[i][j],res);
            }
        }
        
        return res;
    }
};
����һ��?events?���飬����?events[i] = [startDayi, endDayi, valuei]?����ʾ��?i?��������?startDayi?�쿪ʼ����?endDayi?������������μ�������飬���ܵõ���ֵ?valuei?��ͬʱ����һ������?k?��ʾ���ܲμӵ���������Ŀ��

��ͬһʱ��ֻ�ܲμ�һ�����顣�����ѡ��μ�ĳ�����飬��ô����� ����?�زμ���������顣������������ǰ����ڻ����ڵģ�Ҳ����˵�㲻��ͬʱ�μ�һ����ʼ��������һ������������ͬ���������顣

���㷵���ܵõ��Ļ����ֵ?����?��

?

ʾ�� 1��



���룺events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
�����7
���ͣ�ѡ����ɫ�Ļ���� 0 �� 1���õ��ܼ�ֵ��Ϊ 4 + 3 = 7 ��
ʾ�� 2��



���룺events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
�����10
���ͣ��μӻ��� 2 ���õ���ֵ��Ϊ 10 ��
��û���ٲμӱ�Ļ����ˣ���Ϊ������ 2 ���ص����� ��?��Ҫ�μ��� k �����顣
ʾ�� 3��



���룺events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
�����9
���ͣ����ܻ��黥���ص�����ֻ�ܲμ� 3 �����飬����ѡ���ֵ���� 3 �����顣
?

��ʾ��

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
