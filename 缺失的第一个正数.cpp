//����һ��δ������������飬�����ҳ�����û�г��ֵ���С����������

//?

//ʾ��?1:

//����: [1,2,0]
//���: 3
//ʾ��?2:

//����: [3,4,-1,1]
//���: 2
//ʾ��?3:

//����: [7,8,9,11,12]
//���: 1


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0; i < len; i++)
            while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
                Swap(nums,nums[i] - 1, i);//�����ַ���ǰlen������������λ�ã�3 --�� 2��λ��
        
        // [1, -1, 3, 4]
        for(int i = 0; i < len; i++)
            if(nums[i] != i + 1) return i + 1;
        return len+1;
    }

    void Swap(vector<int>& nums,int num,int i)
    {
        int tmp = nums[i];
        nums[i] = nums[num];
        nums[num] = tmp;
    }
};
