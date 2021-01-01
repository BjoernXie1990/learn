class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int le = 0, ri = arr.size() - 1;

        while(le < ri) {
            while(le < ri && arr[le] == arr[ri]) ri--;  // ���������ظ���Ԫ��
            int mid = (le + ri) / 2;

            // �����м��ظ���Ԫ��
            while(mid - 1 > le && arr[mid] == arr[mid - 1]) mid--;
            // �������
            if(arr[le] <= arr[mid]) {
                if(target <= arr[mid] && target >= arr[le]) ri = mid;
                else le = mid + 1;
            } else {    // ������
                if(target >= arr[mid] && target <= arr[ri]) le = mid;
                else ri = mid - 1; 
            }
        }

        if(arr[le] == target) return le;
        return -1;
    }
};

������ת���顣����һ�����������飬����n������������������ѱ���ת���ܶ���ˣ��������ꡣ���д�����ҳ������е�ĳ��Ԫ�أ���������Ԫ��ԭ���ǰ��������еġ����ж����ͬԪ�أ���������ֵ��С��һ����

ʾ��1:

 ����: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
 ���: 8��Ԫ��5�ڸ������е�������
ʾ��2:

 ���룺arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
 �����-1 ��û���ҵ���
��ʾ:

arr ���ȷ�Χ��[1, 1000000]֮��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/search-rotate-array-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
