//���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��

//?

//ʾ��?1:

//����: [1,2,3,4,5]
//���: True
//?

//ʾ��?2:

//����: [0,0,1,2,5]
//���: True



class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxNum = -1;
        int minNum = 15;

        for(int i = 0; i < 5; i++){
            if(nums[i] == 0)
                continue;
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
            if(i != 4 && nums[i] == nums[i+1])
                return false;
        }

        // if(maxNum - minNum < 5)
        //     return true;
        // return false;
        return maxNum - minNum < 5;
    }
};
