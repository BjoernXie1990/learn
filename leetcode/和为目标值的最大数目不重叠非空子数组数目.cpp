����һ������?nums?��һ������?target?��

���㷵��?�ǿղ��ص�?������������Ŀ����ÿ�������������ֺͶ�Ϊ target?��

?

ʾ�� 1��

���룺nums = [1,1,1,1,1], target = 2
�����2
���ͣ��ܹ��� 2 �����ص������飨�Ӵ����ֱ�ʾ�� [1,1,1,1,1] �����ǵĺ�ΪĿ��ֵ 2 ��
ʾ�� 2��

���룺nums = [-1,3,5,1,4,2,-9], target = 6
�����2
���ͣ��ܹ��� 3 ���������Ϊ 6 ��
([5,1], [4,2], [3,5,1,4,2,-9]) ��ֻ��ǰ 2 ���ǲ��ص��ġ�
ʾ�� 3��

���룺nums = [-2,6,6,3,5,4,1,2,8], target = 10
�����3
ʾ�� 4��

���룺nums = [0,0,0], target = 0
�����3
?

��ʾ��

1 <= nums.length <=?10^5
-10^4 <= nums[i] <=?10^4
0 <= target <= 10^6

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> set_t;
        int ans = 0;
        int sum = 0;
        set_t.insert(0);

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(set_t.find(sum - target) != set_t.end())
            {
                set_t.clear();
                sum = 0;
                ans++;
            }
            set_t.insert(sum);
        }

        return ans;
    }

    int maxNonOverlapping2(vector<int>& nums, int target) {
        unordered_map<int,int> map_t;
        int ans = 0;
        int le = -1;
        int sum = 0;
        map_t[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(map_t.find(sum - target) != map_t.end())
            {
                if(map_t[sum - target] >= le)
                {
                    ans++;
                    le = i;
                }
            }
            map_t[sum] = i;
        }

        return ans;
    }
};
