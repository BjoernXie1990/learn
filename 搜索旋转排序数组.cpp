
//���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

//( ���磬����?[0,1,2,4,5,6,7]?���ܱ�Ϊ?[4,5,6,7,0,1,2]?)��

//����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻�?-1?��

//����Լ��������в������ظ���Ԫ�ء�

//����㷨ʱ�临�Ӷȱ�����?O(log?n) ����

//ʾ�� 1:

//����: nums = [4,5,6,7,0,1,2], target = 0
//���: 4
//ʾ��?2:

//����: nums = [4,5,6,7,0,1,2], target = 3
//���: -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        return BinarySerch(nums,0,len-1,target);
    }

    int BinarySerch(vector<int>& nums, int left, int right, int target) {
        //����Ҳ����ͷ���-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            //��Ϊ����һ������������ת��Ľ�������Բ������������������ұ�������С�����
            //���ж�mid���������仹��������
            //�ж��Ƿ���������ʱ�����ܼ�=��������ĳ���������
            if(nums[mid] < nums[left]){//��ǰmid��������
                //��ǰ�����ұ�
                if(nums[right] >= target && nums[mid] < target) left = mid + 1;
                else right = mid - 1;//��ǰ�������
            } 
            else {//��ǰmidΪ�����䣬���ߵ�����һ����������
                //��ǰ�������
                if(nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;//��ǰ�����ұ�
            }
        }
        return -1;

    }
};
