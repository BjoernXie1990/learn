ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int p = len - 1;

        //����ߵ�һ������С������λ��
        for(int i = p ; i >= 0; i--)    //��ߵķ�Χ
            for(int j = len - 1; j > i; j--)    //�ұ����䷶Χ
                if(nums[j] > nums[i])
                {
                    swap(nums[i],nums[j]);
                    sort(nums.begin() + i + 1,nums.end());
                    return ;
                }
        
        sort(nums.begin(),nums.end());

    }
};
