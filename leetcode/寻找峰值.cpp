��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�

����һ����������?nums������ nums[i] �� nums[i+1]���ҵ���ֵԪ�ز�������������

������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü��ɡ�

����Լ���?nums[-1] = nums[n] = -�ޡ�

ʾ�� 1:

����: nums = [1,2,3,1]
���: 2
����: 3 �Ƿ�ֵԪ�أ���ĺ���Ӧ�÷��������� 2��
ʾ��?2:

����: nums = [1,2,1,3,5,6,4]
���: 1 �� 5 
����: ��ĺ������Է������� 1�����ֵԪ��Ϊ 2��
?    ���߷������� 5�� ���ֵԪ��Ϊ 6��
˵��:

��ĽⷨӦ����?O(logN)?ʱ�临�Ӷȵġ�


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ri = nums.size() - 1;
        int le = 0;

        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(nums[mid] > nums[mid + 1])
            {
                ri = mid;
            }
            else if(nums[mid] <= nums[mid + 1])
            {
                le = mid + 1; 
            }
        }

        return le;
    }
};
