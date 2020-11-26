class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int f[n][n];            // f[i][j] i �� j �����ܶȱ��
        memset(f,0x00,sizeof f);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n - 1; j++) f[i][preferences[i][j]] = j; 

        int t[n];   // ���
        memset(t,0x00,sizeof t);
        for(auto& e : pairs) {
            t[e[0]] = e[1];
            t[e[1]] = e[0];
        }

        int ans = 0;
        for(int x = 0; x < n; x++) {
            int y = t[x];
            int idx = f[x][y];      // x y �����ܶ�
            
            for(int j = 0; j < idx; j++) {
                int u = preferences[x][j];
                int v = t[u];

                if(f[u][x] < f[u][v]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};


����һ�� n λ���ѵ��׽��̶��б����� n ���� ż�� ��

��ÿλ���� i��preferences[i] ����һ�� ���׽��̶ȴӸߵ������� �������б����仰˵�������б�ǰ��������� i ���׽��̶ȱ������б��������Ѹ��ߡ�ÿ���б��е����Ѿ��� 0 �� n-1 ֮���������ʾ��

���е����ѱ��ֳɼ��ԣ����������б� pairs ���������� pairs[i] = [xi, yi] ��ʾ xi �� yi ��ԣ��� yi �� xi ��ԡ�

���ǣ����������������ܻ������в������Ѹе������ġ��� x �� y ����� u �� v ��Ե�����£����ͬʱ������������������x �ͻ᲻���ģ�

x �� u ���׽��̶�ʤ�� x �� y����
u �� x ���׽��̶�ʤ�� u �� v
���� �����ĵ����ѵ���Ŀ ��

?

ʾ�� 1��

���룺n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
�����2
���ͣ�
���� 1 �����ģ���Ϊ��
- 1 �� 0 ��ԣ��� 1 �� 3 ���׽��̶ȱ� 1 �� 0 �ߣ���
- 3 �� 1 ���׽��̶ȱ� 3 �� 2 �ߡ�
���� 3 �����ģ���Ϊ��
- 3 �� 2 ��ԣ��� 3 �� 1 ���׽��̶ȱ� 3 �� 2 �ߣ���
- 1 �� 3 ���׽��̶ȱ� 1 �� 0 �ߡ�
���� 0 �� 2 ���ǿ��ĵġ�
ʾ�� 2��

���룺n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
�����0
���ͣ����� 0 �� 1 �����ġ�
ʾ�� 3��

���룺n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], pairs = [[1, 3], [0, 2]]
�����4
?

��ʾ��

2 <= n <= 500
n ��ż��
preferences.length?== n
preferences[i].length?== n - 1
0 <= preferences[i][j] <= n - 1
preferences[i] ������ i
preferences[i] �е�����ֵ���Ƕ�һ�޶���
pairs.length?== n/2
pairs[i].length?== 2
xi != yi
0 <= xi, yi?<= n - 1
ÿλ���Ѷ� ǡ�� ��������һ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-unhappy-friends
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
