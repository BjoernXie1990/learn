class Solution {
public:
    typedef pair<int,int> PII;
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<PII> > mp;
        for(int i = 0; i < n; i++)
            for(int j =i + 1 ; j < n; j++)
                mp[nums[i] * nums[j]].push_back({nums[i],nums[j]});
        
        for(auto& e : mp) {
            auto& vec = e.second;
            int m = vec.size();
            for(int i =0 ;  i< m; i++) {
                int cnt = 0;
                for(int j = i + 1;j < m; j++)
                    if(vec[i].first != vec[j].first && vec[i].second != vec[j].second) cnt++;
                res += cnt * 8;
            }
        }
        return res;
    }
};

����һ���� ��ͬ ��������ɵ����� nums �����㷵������?a * b = c * d ��Ԫ�� (a, b, c, d) ������������ a��b��c �� d ���� nums �е�Ԫ�أ��� a != b != c != d ��

?

ʾ�� 1��

���룺nums = [2,3,4,6]
�����8
���ͣ����� 8 �����������Ԫ�飺
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (3,4,2,6) , (3,4,6,2) , (4,3,6,2)
ʾ�� 2��

���룺nums = [1,2,4,5,10]
�����16
���ͣ����� 16 �����������Ԫ�飺
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
ʾ�� 3��

���룺nums = [2,3,4,6,8,12]
�����40
ʾ�� 4��

���룺nums = [2,3,5,7]
�����0
?

��ʾ��

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums �е�����Ԫ�� ������ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/tuple-with-same-product
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
