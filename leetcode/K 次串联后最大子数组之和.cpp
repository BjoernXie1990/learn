����һ����������?arr?��һ������?k��

���ȣ�����Ҫ�Ը���������޸ģ�����ԭ���� arr �ظ�?k?�Ρ�

�ٸ����ӣ����?arr?= [1, 2] �� k = 3����ô�޸ĺ���������?[1, 2, 1, 2, 1, 2]��

Ȼ�����㷵���޸ĺ�������е�����������֮�͡�

ע�⣬�����鳤�ȿ����� 0������������������ܺ�Ҳ�� 0��

����?������ܻ�ܴ�������Ҫ ģ��mod��?10^9 + 7?���ٷ��ء�?

?

ʾ�� 1��

���룺arr = [1,2], k = 3
�����9
ʾ�� 2��

���룺arr = [1,-2,1], k = 5
�����2
ʾ�� 3��

���룺arr = [-1,-2], k = 7
�����0
?

��ʾ��

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        long maxRi= 0;
        long maxLe = 0;
        long ans = 0;
        long sum = 0;
        long tmp = 0;

        for(int i = 0; i < n; i++)
        {
            if(tmp < 0)
                tmp = arr[i];
            else
                tmp += arr[i];
            sum += arr[i];

            maxLe = max(sum,maxLe);
            ans = max(tmp,ans);
        }
        if(k == 1)  return max((int)ans,0);

        tmp = 0;
        for(int i = n-1; i >= 0; i--)
        {
            tmp += arr[i];
            maxRi = max(maxRi,tmp);
        }

        return max(ans,max(maxLe + maxRi,maxRi + maxLe + (k-2) * sum)) % mod;
    }
};
