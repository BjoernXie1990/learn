����һ����������?arr ��һ������?d ��ÿһ������Դ��±�?i?������

i + x?������?i + x < arr.length?��?0 < x <= d?��
i - x?������?i - x >= 0?��?0 < x <= d?��
�������⣬����±�?i �����±� j?��Ҫ���㣺arr[i] > arr[j]?�� arr[i] > arr[k]?�������±�?k?������ i?�� j?֮������֣�����ʽ�ģ�min(i, j) < k < max(i, j)����

�����ѡ������������±꿪ʼ��Ծ�����㷵���� ���?���Է��ʶ��ٸ��±ꡣ

��ע�⣬�κ�ʱ���㶼����������������档

?

ʾ�� 1��



���룺arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
�����4
���ͣ�����Դ��±� 10 ������Ȼ������ͼ���ξ��� 10 --> 8 --> 6 --> 7 ��
ע�⣬�������±� 6 ��ʼ����ֻ�������±� 7 �����㲻�������±� 5 ����Ϊ 13 > 9 ����Ҳ���������±� 4 ������Ϊ�±� 5 ���±� 4 �� 6 ֮���� 13 > 9 ��
���Ƶģ��㲻�ܴ��±� 3 �������±� 2 �����±� 1 ����
ʾ�� 2��

���룺arr = [3,3,3,3,3], d = 3
�����1
���ͣ�����Դ������±괦��ʼ������Զ�޷������κ��������ꡣ
ʾ�� 3��

���룺arr = [7,6,5,4,3,2,1], d = 1
�����7
���ͣ����±� 0 ����ʼ������԰�����ֵ�Ӵ�С���������е��±ꡣ
ʾ�� 4��

���룺arr = [7,1,7,1,7,1], d = 2
�����2
ʾ�� 5��

���룺arr = [66], d = 1
�����1
?

��ʾ��

1 <= arr.length <= 1000
1 <= arr[i] <= 10^5
1 <= d <= arr.length

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,1);
        vector<pair<int,int> > index(n);
        for(int i = 0; i < n; i++)
            index[i] = {i,arr[i]};
        
        sort(index.begin(),index.end(),[](const pair<int,int>& a,const pair<int,int>& b)->bool{
            return a.second < b.second;
        });

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int idx = index[i].first;
            for(int j = 1; j <= d; j++)
            {
                int pos = idx + j;
                if(pos >= n || arr[pos] >= arr[idx])    break;
                dp[idx] = max(dp[idx],dp[pos] + 1);
            }

            for(int j = 1; j <= d; j++)
            {
                int pos = idx - j;
                if(pos < 0 || arr[pos] >= arr[idx]) break;
                dp[idx] = max(dp[idx],dp[pos] + 1);
            }
            ans = max(ans,dp[idx]);
        }
        return ans;
    }
};
