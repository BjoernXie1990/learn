class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> ans({-1,-1});

        int n = array.size();
        int cnt = INT_MIN;
        // ˳����� end ��������ֵ���λ��
        for(int i = 0; i < n; i++)
            if(array[i] >= cnt) cnt = array[i];
            else ans[1] = i;
        if(ans[1] == -1) return ans;    // �Ѿ�������

        // ������ start ���ұ���Сֵ���λ��
        cnt = INT_MAX;
        for(int i = n - 1; i >= 0; i--) 
            if(array[i] <= cnt) cnt = array[i];
            else ans[0] = i;
        return ans;
    }
};


����һ���������飬��дһ���������ҳ�����m��n��ֻҪ����������[m,n]��Ԫ���ź������������������ġ�ע�⣺n-m������С��Ҳ����˵���ҳ�����������������С���������ֵΪ[m,n]����������������m��n��������������������ģ����뷵��[-1,-1]��

ʾ����

���룺 [1,2,4,7,10,11,7,12,6,7,16,18,19]
����� [3,9]
��ʾ��

0 <= len(array) <= 1000000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sub-sort-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
