//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

//˵����

//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

//ʾ�� 1:

//����: [2,2,3,2]
//���: 3
//ʾ��?2:

//����: [0,1,0,1,0,1,99]
//���: 99


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int ret = 0;//ͳ�Ƶ�iλ����1�Ĵ���
            int count = 1 << i;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & count)
                    ret++;
            }
            if(ret % 3) 
                ans |= count;
        }
        return ans;
    }
};

//����һ����������?nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�

//ʾ�� :

//����: [1,2,1,3,2,5]
//���: [3,5]
//ע�⣺


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        int len = nums.size();

        for(auto& eoch : nums)
            tmp ^= eoch;
        
        //�ҵ�tmp��һλ��һ������λ��
        int pos = 0;
        for(int i = 0; i < 32; i++){
            int ret = 1 << i;
            if(tmp & ret){
                pos = ret;
                break;
            }
        }

        int left = 0, right = 0;
        for(auto& eoch : nums)
            (eoch & pos) ? (left ^= eoch) : (right ^= eoch);
        
        return {left,right};
    }
};
