//����һ������?n + 1 ������������?nums�������ֶ��� 1 �� n?֮�䣨���� 1 �� n������֪���ٴ���һ���ظ�������������ֻ��һ���ظ����������ҳ�����ظ�������

//ʾ�� 1:

//����: [1,3,4,2,2]
//���: 2
//ʾ�� 2:

//����: [3,1,3,4,2]
//���: 3
//˵����

//���ܸ���ԭ���飨����������ֻ���ģ���
//ֻ��ʹ�ö���� O(1) �Ŀռ䡣
//ʱ�临�Ӷ�С�� O(n2) ��
//������ֻ��һ���ظ������֣��������ܲ�ֹ�ظ�����һ�Ρ�

class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            int count = 0;
            for(auto& eoch : nums)
                if(eoch <= mid) count++;
            
            if(count <= mid)
                left = mid+1;
            else if(count > mid)
                right = mid;
        }
        return left;
    }

    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }while(slow != fast);

        int ans = 0;
        while(ans != slow)
        {
            ans = nums[ans];
            slow = nums[slow];
        }

        return ans;
    }
};
