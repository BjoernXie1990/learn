class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> f(1010,0);
        int n = birth.size();
        for(int i = 0; i < n; i++) {
            f[birth[i] - 1900 + 1]++;
            f[death[i] - 1900 + 2]--;
        }

        int res = 0;
        int cnt = 0;
        for(int i = 1; i <= 1000; i++) {
            f[i] = f[i] + f[i-1];
            if(f[i] > cnt) {
                cnt = f[i];
                res = i;
            }
        } 

        return res + 1900 - 1;
    }
};


���� N ���˵ĳ�����ݺ�������ݣ��� i ���˵ĳ������Ϊ birth[i]���������Ϊ death[i]��ʵ��һ�������Լ�����������������ݡ�

����Լ��������˶������� 1900 ���� 2000 �꣨�� 1900 �� 2000 ��֮�䡣���һ������ĳһ�������ʱ�ڴ�������״̬����ô��Ӧ�ñ�������һ���ͳ���С����磬���� 1908 �ꡢ���� 1909 �����Ӧ�������� 1908 ��� 1909 ��ļ�����

����ж���������������ͬ�Ҿ�Ϊ���ֵ�����������С����ݡ�

?

ʾ����

���룺
birth = {1900, 1901, 1950}
death = {1948, 1951, 2000}
����� 1901
?

��ʾ��

0 < birth.length == death.length <= 10000
birth[i] <= death[i]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/living-people-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
