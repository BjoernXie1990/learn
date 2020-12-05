class Solution {
public:
    vector<int> ans;
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return maxNumber(nums2,nums1,k);

        
        for(int i = max(0,k - m); i <= k && i <= n; i++) {
            vector<int> arr1 = Getarr(nums1,n,i);
            vector<int> arr2 = Getarr(nums2,m,k - i);
            merge(arr1,i,arr2,k - i);   // �ϲ����� + �жϴ�С
        }

        return ans;
    }

    // �õ������� һ��k ���ȵ����������
    vector<int> Getarr(vector<int>& arr,int n,int k) {
        vector<int> ret(k);
        for(int i = 0, j = 0; i < n; i++) {
            while(n - i + j > k && j > 0 && arr[i] > ret[j - 1]) j--;
            if(j < k) ret[j++] = arr[i];
        }

        return ret;
    }

    // ��������ϲ�
    void merge(vector<int>& arr1,int n,vector<int>& arr2,int m) {
        vector<int> t(n + m,0);
        int le = 0, ri = 0, idx = 0;
        while(idx < n + m) {
            if(check(arr1,le,arr2,ri)) t[idx++] = arr1[le++];
            else t[idx++] = arr2[ri++];
        }

        if(!check(ans,0,t,0)) ans.swap(t);

        // for(auto& e : t) cout << e << " ";
        // cout << endl;
    }

    bool check(vector<int>& ans,int i,vector<int>& t,int j) {
        int n = ans.size();
        int m = t.size();
        while(i < n && j < m && ans[i] == t[j]) i++,j++;

        return j == m || (i < n && ans[i] > t[j]);
    }
};


�������ȷֱ�Ϊ?m?��?n?���������飬��Ԫ����?0-9?���ɣ���ʾ������Ȼ����λ�ϵ����֡����ڴ�������������ѡ�� k (k <= m + n)?������ƴ�ӳ�һ���µ�����Ҫ���ͬһ��������ȡ�������ֱ�������ԭ�����е����˳��

���������������������������һ����ʾ��������ĳ���Ϊ?k?�����顣

˵��: �뾡���ܵ��Ż����㷨��ʱ��Ϳռ临�Ӷȡ�

ʾ��?1:

����:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
���:
[9, 8, 6, 5, 3]
ʾ�� 2:

����:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
���:
[6, 7, 6, 0, 4]
ʾ�� 3:

����:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
���:
[9, 8, 9]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/create-maximum-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
