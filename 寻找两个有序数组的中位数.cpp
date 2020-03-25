//����������СΪ m �� n ����������?nums1 ��?nums2��

//�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ?O(log(m + n))��

//����Լ���?nums1?��?nums2?����ͬʱΪ�ա�

//ʾ�� 1:

//nums1 = [1, 3]
//nums2 = [2]

//����λ���� 2.0
//ʾ�� 2:

//nums1 = [1, 2]
//nums2 = [3, 4]

//����λ���� (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        //ȷ��num1 �� num2 �����
        if(len1 < len2)
            return findMedianSortedArrays(nums2,nums1);

        int n = len1 + len2;

        //����Ϊ[] ,����ұ�����
        if(n & 1)//�������鳤��Ϊ����
            return Find_Binary(nums1,0,len1-1,\
                                nums2,0,len2-1,(n>>1) + 1);//�ҵ�kС
        
        //�������鳤�Ⱥ�Ϊż��   �ҵ�k�͵�k+1С
        return (Find_Binary(nums1,0,len1-1,nums2,0,len2-1,n>>1) \
            + Find_Binary(nums1,0,len1-1,nums2,0,len2-1,(n>>1) + 1)) / 2.0;
    }

    //���ֲ��ҵ�kС
    int Find_Binary(vector<int>& nums1,int l1,int r1,\
                    vector<int>& nums2,int l2,int r2,int k)//�����ҵ�kС
    {
        if(l1 > r1)//�������1Ԫ�ض������ϣ���������1�ǿ�
            return nums2[l2 + k - 1];
        
        if(l2 > r2)//�������2Ԫ�ض������ϣ���������2�ǿ�
            return nums1[l1 + k - 1];

        if(k == 1)//����ҵ�һ��С�ģ����������������С����һ��
            return min(nums1[l1],nums2[l2]);

        //�ҵ�������k/2λ��
        int d1 = l1 + k / 2 - 1;
        int d2 = l2 + k / 2 - 1;

        //�ų�Խ������
        d1 = (d1 <= r1) ? d1 : r1;
        d2 = (d2 <= r2) ? d2 : r2;

        //�������
        //1.����1 k/2λ�õ�ֵ�� ����2 С��ɾ������1ǰ (d1 - l1 + 1) ��Ԫ��
        if(nums1[d1] < nums2[d2])
            return Find_Binary(nums1,d1 + 1,r1,nums2,l2,r2,k - (d1 - l1 + 1));

        //2.����1 k/2λ�õ�ֵ�� ����2 ��ɾ������2ǰ (d2 - l2 + 1) ��Ԫ��
        return Find_Binary(nums1,l1,r1,nums2,d2 + 1,r2, k - (d2 - l2 + 1));
    }
};
