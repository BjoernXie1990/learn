����һ���Ѱ�����������?���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1?����С��?index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();

        //����
        // for(int i = 0; i < len-1; i++)
        // {
        //     int pos = BinaryFind(numbers,i+1,len-1,target-numbers[i]);
        //     if(numbers[pos] == target - numbers[i])
        //         return {i+1,pos+1};
        // }

        int le = 0;
        int ri = len-1;
        while(le < ri)
        {
            int num = numbers[le] + numbers[ri];
            if(num == target)
                return {le+1,ri+1};
            else if(num < target)
                le++;
            else if(num > target)
                ri--;
        }

        return {};
    }

    int BinaryFind(vector<int>& nums,int le,int ri,int n)
    {
        if(le > ri) return le;

        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(nums[mid] == n) return mid;

            if(nums[mid] < n)   le = mid + 1;
            else if(nums[mid] > n)  ri = mid - 1;
        }

        return le;
    }
};
