class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n,-1);

        for(int i = n * 2 - 1; i >= 0; i--) {
            while(st.size() && nums[st.top()] <= nums[i % n]) {
                st.pop();
            }
            if(st.size())
                res[i % n] = nums[st.top()];
            st.push(i % n);
        }
        return res;
    }
};


����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء����� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ -1��

ʾ�� 1:

����: [1,2,1]
���: [2,-1,2]
����: ��һ�� 1 ����һ����������� 2��
���� 2 �Ҳ�����һ����������� 
�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
ע��: ��������ĳ��Ȳ��ᳬ�� 10000��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/next-greater-element-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
