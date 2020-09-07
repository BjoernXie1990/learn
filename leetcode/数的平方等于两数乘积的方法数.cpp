���������������� nums1 �� nums2 �����㷵�ظ������¹����γɵ���Ԫ�����Ŀ������ 1 ������ 2 ����

���� 1����Ԫ�� (i, j, k) ����� nums1[i]2?== nums2[j] * nums2[k] ���� 0 <= i < nums1.length �� 0 <= j < k < nums2.length
���� 2����Ԫ�� (i, j, k) ����� nums2[i]2?== nums1[j] * nums1[k] ���� 0 <= i < nums2.length �� 0 <= j < k < nums1.length
?

ʾ�� 1��

���룺nums1 = [7,4], nums2 = [5,2,8,9]
�����1
���ͣ����� 1��(1,1,2), nums1[1]^2 = nums2[1] * nums2[2] (4^2 = 2 * 8)
ʾ�� 2��

���룺nums1 = [1,1], nums2 = [1,1,1]
�����9
���ͣ�������Ԫ�鶼������ĿҪ����Ϊ 1^2 = 1 * 1
���� 1��(0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2), nums1[i]^2 = nums2[j] * nums2[k]
���� 2��(0,0,1), (1,0,1), (2,0,1), nums2[i]^2 = nums1[j] * nums1[k]
ʾ�� 3��

���룺nums1 = [7,7,8,3], nums2 = [1,2,9,7]
�����2
���ͣ�������������ĿҪ�����Ԫ��
���� 1��(3,0,2), nums1[3]^2 = nums2[0] * nums2[2]
���� 2��(3,0,1), nums2[3]^2 = nums1[0] * nums1[1]
ʾ�� 4��

���룺nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
�����0
���ͣ������ڷ�����ĿҪ�����Ԫ��
?

��ʾ��

1 <= nums1.length, nums2.length <= 1000
1 <= nums1[i], nums2[i] <= 10^5

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long,int> map_t;
        for(int i = 0; i < nums1.size(); i++) 
            for(int j = i + 1; j < nums1.size(); j++)
                map_t[(long long)((long long)nums1[i] * (long long)nums1[j])]++;
        
        unordered_map<long long,int> map2_t;
        for(int i = 0; i < nums2.size(); i++) 
            for(int j = i + 1; j < nums2.size(); j++)
                map2_t[(long long)((long long)nums2[i] * (long long)nums2[j])]++;
        
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++)
            if(map2_t.count((long long)((long long)nums1[i] * (long long)nums1[i])) > 0) ans += map2_t[(long long)((long long)nums1[i] * (long long)nums1[i])];
        
        for(int i = 0; i < nums2.size(); i++)
            if(map_t.count((long long)((long long)nums2[i] * (long long)nums2[i])) > 0) ans += map_t[(long long)((long long)nums2[i] * (long long)nums2[i])];

        return ans;
    }
};
