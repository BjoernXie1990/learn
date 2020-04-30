//����һ��?n?��Ԫ������ģ�������������?nums ��һ��Ŀ��ֵ?target ?��дһ����������?nums?�е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��


//ʾ�� 1:

//����: nums = [-1,0,3,5,9,12], target = 9
//���: 4
//����: 9 ������ nums �в����±�Ϊ 4
//ʾ��?2:

//����: nums = [-1,0,3,5,9,12], target = 2
//���: -1
//����: 2 ������ nums ����˷��� -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        //[left,right]������ұ����� 
        while(left <= right) {
            int  mid = (left + right)>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
}; 
//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

//����㷨ʱ�临�Ӷȱ�����?O(log n) ����

//��������в�����Ŀ��ֵ������?[-1, -1]��

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans(2,-1);
        ans[0] = BinaryFindLeft(nums,target,0,len-1);
        ans[1] = BinaryFindRight(nums,target,0,len-1);
        return ans;
    }
    //Ѱ�����߽�
    int BinaryFindLeft(vector<int>& nums, int target,int left,int right) {
        if(left > right) return -1;
        int len = right + 1;
        //[left,right) ����ҿ���д��
        right += 1;
        while(left < right) //��ֹ������left == right
            int mid = (left + right) / 2;
            int num = nums[mid];

            if(num == target) right = mid;
            else if(num < target) left = mid + 1;
            else if(num > target) right = mid;
        }

        //[left,right] ����ұյ�д��
        // while(left <= right) {//��ֹ������ left - 1 = right
        //     int mid = (left + right) / 2;
        //     int num = nums[mid];
        //     if(num == target) right = mid - 1;
        //     else if(num > target) right = mid - 1;
        //     else if(num < target) left = mid + 1;
        // }
        if(left >= len || nums[left] != target) return -1;
        return left;
    }
    //Ѱ���Ҳ�߽�
    int BinaryFindRight(vector<int>& nums,int target,int left,int right) {
        if(left > right) return -1;
        int len = right + 1;
        //[left,right) ����ҿ���д��
        right += 1;
        while(left < right) {//��ֹ������left == right
            int mid = (left + right) / 2;
            int num = nums[mid];

            if(num == target) left = mid + 1;
            else if(num < target) left = mid + 1;
            else if(num > target) right = mid;
        }
        if(right <= 0 || nums[right-1] != target) return -1;
        return right-1;//�Ҳ�����Ϊ������

        //[left,right] ����ұյ�д��
        // while(left <= right) {
        //     int mid = (left + right) / 2;
        //     int num = nums[mid];
        //     if(num == target) left = mid + 1;
        //     else if(num > target) right = mid - 1;
        //     else if(num < target) left = mid + 1;
        // }

        //if(right < 0 || nums[right] != target) return -1;
        //return right;
    }
};
