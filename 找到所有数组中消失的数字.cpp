//����һ����Χ��? 1 �� a[i] �� n (?n = �����С ) �� �������飬�����е�Ԫ��һЩ���������Σ���һЩֻ����һ�Ρ�

//�ҵ������� [1, n] ��Χ֮��û�г����������е����֡�

//�����ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�ΪO(n)�������������������? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�

//ʾ��:

//����:
//[4,3,2,7,8,2,3,1]

//���:
//[5,6]


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0; i < len; i++)
            while(nums[i] != nums[nums[i] - 1])
                swap(nums[i],nums[nums[i]-1]);
        
        vector<int> ret;
        //1 2 3 4 3 2 7 8 
        for(int i = 0; i < len; i++)
            if(nums[i] != i+1) ret.push_back(i+1);
        return ret;
    }
};
