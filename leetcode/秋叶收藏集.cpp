class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int dp[3][n];
        memset(dp,0x00,sizeof(dp));
        dp[0][2] = (leaves[0] != 'r') + (leaves[1] != 'r') + (leaves[2] != 'r');  // rrr
        dp[1][2] = (leaves[0] != 'r') +                      (leaves[2] != 'y');  // rry  ryy
        dp[2][2] = (leaves[0] != 'r') + (leaves[1] != 'y') + (leaves[2] != 'r');  // ryr

        for(int i = 3; i < n; i++) {
            bool isR = (leaves[i] == 'r');
            dp[0][i] = dp[0][i-1] + !isR;
            dp[1][i] = min(dp[0][i-1],dp[1][i-1]) + isR;
            dp[2][i] = min(dp[1][i-1],dp[2][i-1]) + !isR;
        }

        return dp[2][n-1];
    }
};

С�۳�ȥ���Σ�;���ռ���һЩ��Ҷ�ͻ�Ҷ����������ЩҶ�ӳ���������һ����Ҷ�ղؼ� leaves�� �ַ��� leaves ������Сд�ַ� r �� y�� �����ַ� r ��ʾһƬ��Ҷ���ַ� y ��ʾһƬ��Ҷ��
������������Ŀ��ǣ�С����Ҫ���ղؼ�����Ҷ�����е����ɡ��졢�ơ��졹�����֡�ÿ������Ҷ�������Բ���ȣ���������ڵ��� 1��ÿ�ε���������С�ۿ��Խ�һƬ��Ҷ�滻�ɻ�Ҷ���߽�һƬ��Ҷ�滻�ɺ�Ҷ������С��������Ҫ���ٴε����������ܽ���Ҷ�ղؼ�������ϡ�

ʾ�� 1��

���룺leaves = "rrryyyrryyyrr"

�����2

���ͣ��������Σ����м����Ƭ��Ҷ�滻�ɻ�Ҷ���õ� "rrryyyyyyyyrr"

ʾ�� 2��

���룺leaves = "ryr"

�����0

���ͣ��ѷ���Ҫ�󣬲���Ҫ�������

��ʾ��

3 <= leaves.length <= 10^5
leaves ��ֻ�����ַ� 'r' ���ַ� 'y'

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/UlBDOe
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
