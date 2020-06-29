����һ�����������һ������?k���ж��������Ƿ����������ͬ������?i?��?j��ʹ��?nums [i] = nums [j]������ i �� j?�Ĳ�� ����ֵ ����Ϊ k��

?

ʾ��?1:

����: nums = [1,2,3,1], k = 3
���: true
ʾ�� 2:

����: nums = [1,0,1,1], k = 1
���: true
ʾ�� 3:

����: nums = [1,2,3,1,2,3], k = 2
���: false

class Solution {
public:
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int le = max(0,i - k);
            int ri = min(len-1,i+k);

            for(int j = le; j <= ri; j++)
            {
                if(i != j && nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,vector<int> > map;

        for(int i = 0; i < len; i++)
        {
            map[nums[i]].push_back(i);

            for(auto& n : map[nums[i]])
            {
                if(n != i && abs(n - i) <= k)
                    return true;
            }
        }
        return false;
    }
};
