class Solution {
public:
    const int N = 1010;
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hash;

        for(auto& num : arr) hash[num]++;

        set<int> st;
        for(auto& cnt : hash) {
            if(st.count(cnt.second) > 0) return false;
            st.insert(cnt.second);
        }
        return true;
    }
};


����һ����������?arr�������æͳ��������ÿ�����ĳ��ִ�����

���ÿ�����ĳ��ִ������Ƕ�һ�޶��ģ��ͷ���?true�����򷵻� false��

?

ʾ�� 1��

���룺arr = [1,2,2,1,1,3]
�����true
���ͣ��ڸ������У�1 ������ 3 �Σ�2 ������ 2 �Σ�3 ֻ������ 1 �Ρ�û���������ĳ��ִ�����ͬ��
ʾ�� 2��

���룺arr = [1,2]
�����false
ʾ�� 3��

���룺arr = [-3,0,1,-3,1,1,1,-3,10,0]
�����true
?

��ʾ��

1 <= arr.length?<= 1000
-1000 <= arr[i] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-number-of-occurrences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
