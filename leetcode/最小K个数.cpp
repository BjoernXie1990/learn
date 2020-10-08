class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        QuitSort(arr,0,arr.size()-1,k);
        
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(arr[i]);

        return ans;
    }

    void QuitSort(vector<int>& arr,int le,int ri,int k) {
        if(le >= ri || le >= k || ri < k) return ;

        int pos = le;
        int num = arr[le];
        int pre = le;
        for(int i = le + 1; i <= ri; i++)
            if(arr[i] < num)  {
                swap(arr[pos],arr[i]);
                if(pos == pre) pre = i;
                pos++;
            }
        swap(arr[pre],arr[pos]);

        QuitSort(arr,le,pos-1,k);
        QuitSort(arr,pos+1,ri,k);
    }
};

���һ���㷨���ҳ���������С��k������������˳�򷵻���k�������ɡ�

ʾ����

���룺 arr = [1,3,5,7,2,4,6,8], k = 4
����� [1,2,3,4]
��ʾ��

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/smallest-k-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
