class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // ��ɢ��  1 7 7 7 7 11 --��  1 7 7 11
        int m = 0;
        for(int i = 0; i < n; i++) {
            int len = 1;
            while(i + len < n && arr[i] == arr[len + i]) len++;
            arr[m++] = arr[i];
            if(len != 1) arr[m++] = arr[i];
            i += len - 1;
        }

        queue<int> que({0});
        int dp[m];
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;

        // ����ͼ
        unordered_map<int,set<int> > ums;
        for(int i = 0; i < m; i++) ums[arr[i]].insert(i);

        int ans = 0;
        while (que.empty() == false) {
            int size = que.size();
            while (size --) {
                int f = que.front();
                que.pop();
                if(f == m - 1) return ans;    // ��ǰλ��Ϊ�յ�

                // left
                int le = f - 1;
                if(le >= 0 && dp[le] > dp[f] + 1) {
                    que.push(le);
                    dp[le] = dp[f] + 1;
                }

                // right
                int ri = f + 1;
                if ( ri < m && dp[ri] > dp[f] + 1) {
                    que.push(ri);
                    dp[ri] = dp[f] + 1;
                }

                // same
                for ( auto& index : ums[arr[f]] ) {
                    if(dp[index] > dp[f] + 1) {
                        que.push(index);
                        dp[index] = dp[f] + 1;
                    }
                }
            }
            ans++;
        }

        return -1;  // �޷������յ�
    }
};

����һ����������?arr?����һ��ʼ������ĵ�һ��Ԫ�ش����±�Ϊ 0����

ÿһ��������Դ��±�?i?�����±꣺

i + 1?���㣺i + 1 < arr.length
i - 1?���㣺i - 1 >= 0
j?���㣺arr[i] == arr[j]?��?i != j
���㷵�ص����������һ��Ԫ�ص��±괦�����?���ٲ�������?��

ע�⣺�κ�ʱ���㶼���������������档

?

ʾ�� 1��

���룺arr = [100,-23,-23,404,100,23,23,23,3,404]
�����3
���ͣ�������Ҫ��Ծ 3 �Σ��±�����Ϊ 0 --> 4 --> 3 --> 9 ���±� 9 Ϊ��������һ��Ԫ�ص��±ꡣ
ʾ�� 2��

���룺arr = [7]
�����0
���ͣ�һ��ʼ�������һ��Ԫ�ش��������㲻��Ҫ��Ծ��
ʾ�� 3��

���룺arr = [7,6,9,6,9,6,9,7]
�����1
���ͣ������ֱ�Ӵ��±� 0 �������±� 7 ����Ҳ������������һ��Ԫ�ش���
ʾ�� 4��

���룺arr = [6,1,9]
�����2
ʾ�� 5��

���룺arr = [11,22,7,7,7,7,7,7,7,22,13]
�����3
?

��ʾ��

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/jump-game-iv
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
