����һ����������?nums?��һ��������?k�������ж��Ƿ���԰�������黮�ֳ�һЩ��?k?������������ɵļ��ϡ�
������ԣ��뷵��?True�����򣬷���?False��

?

ʾ�� 1��

���룺nums = [1,2,3,3,4,4,5,6], k = 4
�����true
���ͣ�������Էֳ� [1,2,3,4] �� [3,4,5,6]��
ʾ�� 2��

���룺nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
�����true
���ͣ�������Էֳ� [1,2,3] , [2,3,4] , [3,4,5] �� [9,10,11]��
ʾ�� 3��

���룺nums = [3,3,2,2,1,1], k = 3
�����true
ʾ�� 4��

���룺nums = [1,2,3,4], k = 3
�����false
���ͣ����鲻�ֳܷɼ�����СΪ 3 �������顣
?

��ʾ��

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length



class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len = nums.size();
        if(len % k != 0) return false;
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> map;
        for(auto& n : nums)
            map[n]++;

        for(int i = 0; i < len; i++)
        {
            if(map[nums[i]] == 0) continue;
            for(int j = 0; j < k; j++)
            {
                if(map.count(nums[i] + j) == 0)   return false;
                map[nums[i] + j]--;
            }
        }
        return true;
    }
};
