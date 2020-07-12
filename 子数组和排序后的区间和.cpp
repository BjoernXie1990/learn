����һ������?nums?��������?n?��������������Ҫ�������зǿ�����������ĺͣ��������ǰ��������򣬵õ�һ���µİ���?n * (n + 1) / 2?�����ֵ����顣

���㷵�������������±�Ϊ?left?��?right ���±�� 1 ��ʼ�����������ֺͣ��������Ҷ˵㣩�����ڴ𰸿��ܴܺ����㽫���� 10^9 + 7 ȡģ�󷵻ء�

?

ʾ�� 1��

���룺nums = [1,2,3,4], n = 4, left = 1, right = 5
�����13 
���ͣ����е��������Ϊ 1, 3, 6, 10, 2, 5, 9, 3, 7, 4 ��������������������ǵõ��µ����� [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] ���±�� le = 1 �� ri = 5 �ĺ�Ϊ 1 + 2 + 3 + 3 + 4 = 13 ��
ʾ�� 2��

���룺nums = [1,2,3,4], n = 4, left = 3, right = 4
�����6
���ͣ�����������ʾ�� 1 һ��������������Ϊ [1, 2, 3, 3, 4, 5, 6, 7, 9, 10] ���±�� le = 3 �� ri = 4 �ĺ�Ϊ 3 + 3 = 6 ��
ʾ�� 3��

���룺nums = [1,2,3,4], n = 4, left = 1, right = 10
�����50
?

��ʾ��

1 <= nums.length <= 10^3
nums.length == n
1 <= nums[i] <= 100
1 <= left <= right?<= n * (n + 1) / 2


class Solution {
public:
    const int mod =  1000000000 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int len = nums.size();
        vector<int> arr(len+1,0);
        for(int i = 1; i <= len; i++)
            arr[i] = arr[i-1] + nums[i-1];
        
        multiset<int> s;
        for(int i = 1; i <= len; i++)
            for(int j = 0; j < i; j++)
                s.insert(arr[i] - arr[j]);
        int p = 1;
        int ans = 0;
        for(auto& num : s)
        {
            if(p >= left && p <= right) ans += num;
            ans %= mod;
            p++;
            if(p > right) break;
            
        }
        return ans;
    }
};
