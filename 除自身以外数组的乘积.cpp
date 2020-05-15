//����һ������Ϊ?n?����������?nums������?n > 1�������������?output?������ output[i]?����?nums?�г�?nums[i]?֮�������Ԫ�صĳ˻���

//?

//ʾ��:

//����: [1,2,3,4]
//���: [24,12,8,6]
//?

//��ʾ����Ŀ���ݱ�֤����֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺���������������飩�ĳ˻����� 32 λ������Χ�ڡ�

//˵��: �벻Ҫʹ�ó���������?O(n) ʱ�临�Ӷ�����ɴ��⡣

//���ף�
//������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��


class Solution {
public:
    //�������� O(N)�ռ临�Ӷ�
    vector<int> productExceptSelf1(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len+1,1);
        vector<int> right(len+1,1);

        //�������
        for(int i = 1; i < len; i++)
            left[i] = left[i-1]*nums[i-1];
        
        //�ұ�����
        for(int i = len-2; i >= 0; i--)
            right[i] = right[i+1]* nums[i+1];
        
        vector<int> ret(len,0);
        for(int i = 0; i < len; i++)
            ret[i] = left[i]*right[i];
        return ret;
    }

    //��ʹ�ö���ռ�
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len,1);
        //�������
        for(int i = 1; i < len; i++)
            ret[i] = ret[i-1]*nums[i-1];
        
        //�ұ�����
        int right = 1;
        for(int i = len-2; i >= 0; i--)
        {
            right *= nums[i+1];
            ret[i] *= right; 
        }
        return ret;
    }
};
