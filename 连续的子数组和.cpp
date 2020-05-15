//����һ�������Ǹ����������һ��Ŀ������?k����дһ���������жϸ������Ƿ��������������飬���С����Ϊ 2���ܺ�Ϊ k �ı��������ܺ�Ϊ n*k������ n Ҳ��һ��������

//ʾ�� 1:

//����: [23,2,4,6,7], k = 6
//���: True
//����: [2,4] ��һ����СΪ 2 �������飬���Һ�Ϊ 6��
//ʾ�� 2:

//����: [23,2,6,4,7], k = 6
//���: True
//����: [23,2,6,4,7]�Ǵ�СΪ 5 �������飬���Һ�Ϊ 42��
//˵��:

//����ĳ��Ȳ��ᳬ��10,000��
//�������Ϊ���������ܺ��� 32 λ�з���������Χ�ڡ�



class Solution {
public:
    //�����ⷨ
    bool checkSubarraySum1(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> arr(len+1,0);
        for(int i = 1; i <= len; i++)
            arr[i] = arr[i-1] + nums[i-1];
        
        for(int i = 0; i <= len-2; i++)
            for(int j = i+2; j <= len; j++)
                if(k==0 && (arr[i]-arr[j]) == 0) 
                    return true;
                else if(k != 0 && (arr[i] - arr[j]) % k == 0) 
                    return true;

        return false;
    }

    //��ϣ + ǰ׺��
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,int> map;
        map.insert({0,-1});//�ų� [0,0],0 �ĸ���
        int pre = 0;
        for(int i = 0; i < len; i++)
        {
            pre += nums[i];
            if(k != 0) pre %= k;

            if(map.count(pre) && i - map[pre] > 1) return true;
 
            map.insert({pre,i});
        }
        return false;
    }
};
