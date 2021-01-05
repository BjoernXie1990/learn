class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[target[i]] = i;

        vector<int> vec;
        for(int i = 0; i < m; i++) if(mp.count(arr[i])) vec.push_back(mp[arr[i]]);

        vector<int> d;
        for(auto& x : vec) {
            auto it = lower_bound(d.begin(),d.end(), x);
            if(it == d.end()) d.push_back(x);
            else *it = x;
        }

        return n - d.size();
    }
};

����һ������?target?���������� ������ͬ?���������Լ���һ����������?arr?��arr?���� �����ظ�Ԫ�ء�

ÿһ�β����У�������� arr?������λ�ò�����һ�������ȷ�˵�����?arr = [1,4,1,2]?����ô��������м���� 3?�õ�?[1,4,3,1,2]?��������������ʼ����������������

���㷵�� ����?����������ʹ��?target?��Ϊ?arr?��һ�������С�

һ������� ������?ָ����ɾ��ԭ�����ĳЩԪ�أ�����һ��Ԫ�ض���ɾ������ͬʱ���ı�����Ԫ�ص����˳��õ������顣�ȷ�˵��[2,7,4]?��?[4,2,3,7,2,1,4]?�������У��Ӵ�Ԫ�أ�����?[2,4,2]?���������С�

?

ʾ�� 1��

���룺target = [5,1,3], arr = [9,4,2,3,4]
�����2
���ͣ��������� 5 �� 1 ��ʹ�� arr ��Ϊ [5,9,4,1,2,3,4] ��target Ϊ arr �������С�
ʾ�� 2��

���룺target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
�����3
?

��ʾ��

1 <= target.length, arr.length <= 105
1 <= target[i], arr[i] <= 109
target?�������κ��ظ�Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
