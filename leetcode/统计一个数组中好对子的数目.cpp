class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,0);
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            int num = 0;
            while(t) {
                num = num * 10 + t % 10;
                t /= 10;
            }
            
            f[i] = num;
        
        }
        
        long long res = 0;
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i] - f[i]] ++;
        }
        
        
        for(auto& e : mp) {
            long long cnt = e.second;
            res = (res + (long long)((cnt * (cnt - 1)) / 2) % MOD) % MOD;
        }
        
        return res;
    }
};

����һ������?nums?��������ֻ�����Ǹ�����������?rev(x)?��ֵΪ������?x?��������λ��ת�õ��Ľ�����ȷ�˵?rev(123) = 321?��?rev(120) = 21?�����ǳ����������������±��?(i, j) ��?�õ�?��

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
���㷵�غ��±�Ե���Ŀ�����ڽ�����ܻ�ܴ��뽫�����?109 + 7?ȡ��?�󷵻ء�

?

ʾ�� 1��

���룺nums = [42,11,1,97]
�����2
���ͣ����������Ϊ��
 - (0,3)��42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 ��
 - (1,2)��11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 ��
ʾ�� 2��

���룺nums = [13,10,35,24,76]
�����4
?

��ʾ��

1 <= nums.length <= 105
0 <= nums[i] <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-nice-pairs-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
