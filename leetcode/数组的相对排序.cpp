class Solution {
public:
    const int N = 1010;
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int f[N];
        for(int i = 0; i < N; i++) f[i] = -1;
        for(int i = 0; i < arr2.size(); i++) f[arr2[i]] = i;

        int ri = arr1.size() - 1;
        for(int i = 0; i < arr1.size(); i++) while(ri >= i && f[arr1[i]] == -1) swap(arr1[i],arr1[ri--]);

        sort(arr1.begin(),arr1.begin() + ri + 1,[&](const int& a,const int& b)->bool{
            return f[a] < f[b];
        });
        sort(arr1.begin() + ri + 1,arr1.end());

        return arr1;
    }
};

�����������飬arr1 ��?arr2��

arr2?�е�Ԫ�ظ�����ͬ
arr2 �е�ÿ��Ԫ�ض�������?arr1?��
�� arr1?�е�Ԫ�ؽ�������ʹ arr1 ��������˳���?arr2?�е����˳����ͬ��δ��?arr2?�г��ֹ���Ԫ����Ҫ�����������?arr1?��ĩβ��

?

ʾ����

���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
�����[2,2,2,1,4,3,3,9,6,7,19]
?

��ʾ��

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2?�е�Ԫ��?arr2[i]?������ͬ
arr2 �е�ÿ��Ԫ��?arr2[i]?��������?arr1?��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/relative-sort-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
