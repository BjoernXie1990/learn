class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s = 0, t = 0;
        vector<int> c1(10,0),c2(10,0);
        for(auto& e : nums1) {
            s += e;
            c1[e] ++;
        }
        for(auto& e : nums2) {
            t += e;
            c2[e] ++;
        }
            
        if(s < t) {
            swap(s,t);
            nums1.swap(nums2);
            c1.swap(c2);
        }
        
        int res = 0, i = 6, j = 1;
        while(s > t && (i >= 2 || j <= 5)) {
            int sub = s - t;
            res ++;
            while(i >= 1 && !c1[i]) i--;
            while(j <= 6 && !c2[j]) j++;
            if(abs(i - 6) <= abs(j - 1)) {
                c1[i] --;
                if(i - sub >= 1) {
                    s -= sub;
                    c1[i - sub] ++;
                } else {
                    s -= i - 1;
                    c1[1] ++;
                }
            } else {
                c2[j] --;
                if(j + sub <= 6) {
                    t += sub;
                    c2[j + sub] ++;
                } else {
                    t += 6 - j;
                    c2[6] ++;
                }
            }
        }
        
        
        if(s == t) return res;
        return -1;
    }
};


�����������ȿ��ܲ��ȵ���������?nums1 ��?nums2?�����������е�����ֵ����?1?��?6?֮�䣨����?1?��?6����

ÿ�β����У������ѡ�� ����?�����е�����һ��������������� 1?�� 6?֮�� ����?��ֵ������ 1?�� 6����

���㷵��ʹ nums1?���������ĺ���?nums2?���������ĺ���ȵ����ٲ�������������޷�ʹ��������ĺ���ȣ��뷵�� -1?��

?

ʾ�� 1��

���룺nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
�����3
���ͣ������ͨ�� 3 �β���ʹ nums1 ���������ĺ��� nums2 ���������ĺ���ȡ����������±궼�� 0 ��ʼ��
- �� nums2[0] ��Ϊ 6 �� nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] ��
- �� nums1[5] ��Ϊ 1 �� nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] ��
- �� nums1[2] ��Ϊ 2 �� nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] ��
ʾ�� 2��

���룺nums1 = [1,1,1,1,1,1,1], nums2 = [6]
�����-1
���ͣ�û�а취���� nums1 �ĺͻ������� nums2 �ĺ�ʹ������ȡ�
ʾ�� 3��

���룺nums1 = [6,6], nums2 = [1]
�����3
���ͣ������ͨ�� 3 �β���ʹ nums1 ���������ĺ��� nums2 ���������ĺ���ȡ����������±궼�� 0 ��ʼ��
- �� nums1[0] ��Ϊ 2 �� nums1 = [2,6], nums2 = [1] ��
- �� nums1[1] ��Ϊ 2 �� nums1 = [2,2], nums2 = [1] ��
- �� nums2[0] ��Ϊ 4 �� nums1 = [2,2], nums2 = [4] ��
?

��ʾ��

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
