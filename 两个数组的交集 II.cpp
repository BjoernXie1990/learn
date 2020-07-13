�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2,2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [4,9]
˵����

��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
���ǿ��Բ�������������˳��
����:

��������������Ѿ��ź����أ��㽫����Ż�����㷨��
���?nums1?�Ĵ�С��?nums2?С�ܶ࣬���ַ������ţ�
���?nums2?��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô��


class Solution {
public:
    //��ϣ����
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2,nums1);
        unordered_map<int,int> map;
        for(auto& n : nums1)
            map[n]++;
        
        vector<int> ans;
        for(auto& n : nums2)
            if(map[n] > 0) ans.push_back(n),map[n]--;
        return ans;
    }

    //����
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int le = 0,ri = 0;
        vector<int> ans;
        while(le < nums1.size() && ri < nums2.size())
        {
            if(nums1[le] == nums2[ri])
            {
                ans.push_back(nums2[ri]);
                le++;
                ri++;
                continue;
            }

            //le  != ri
            if(nums1[le] < nums2[ri])
                le++;
            else
                ri++;
        }
        return ans;
    }

};
