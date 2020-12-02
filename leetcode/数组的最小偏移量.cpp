class Solution {
public:
    typedef pair<int,int> PII;
    int minimumDeviation(vector<int>& nums) {
        set<PII> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            while(num % 2 == 0) {       // ����ż������Ϊ����
                num /= 2;
            }
            st.insert(make_pair(num,i));
        }

        int ans = st.rbegin()->first - st.begin()->first;
        // ÿ��̰�ĵض���С��Ԫ�ؽ��г�22�Ĳ�����ֱ�������ټ���������ȥΪֹ����С��Ԫ���Ѿ���ż�������ҵ�����ԭʼֵ��
        while(st.begin()->first < nums[st.begin()->second] || st.begin()->first % 2 == 1) {
            auto [num,idx] = *st.begin();
            st.erase(st.begin());
            st.insert(make_pair(num << 1,idx));

            ans = min(ans,st.rbegin()->first - st.begin()->first);
        }

        return ans;
    }
};


����һ���� n ����������ɵ����� nums ��

����Զ����������Ԫ��ִ��������������������

���Ԫ���� ż�� ������ 2
���磬��������� [1,2,3,4] ����ô����Զ����һ��Ԫ��ִ�д˲�����ʹ���� [1,2,3,2]
���Ԫ���� ���� ������ 2
���磬��������� [1,2,3,4] ����ô����ԶԵ�һ��Ԫ��ִ�д˲�����ʹ���� [2,2,3,4]
����� ƫ���� ����������������Ԫ��֮��� ����ֵ ��

����������ִ��ĳЩ����֮�����ӵ�е� ��Сƫ���� ��

?

ʾ�� 1��

���룺nums = [1,2,3,4]
�����1
���ͣ�����Խ�����ת��Ϊ [1,2,3,2]��Ȼ��ת���� [2,2,3,2]��ƫ������ 3 - 2 = 1
ʾ�� 2��

���룺nums = [4,1,5,20,3]
�����3
���ͣ����β���������Խ�����ת��Ϊ [4,2,5,5,3]��ƫ������ 5 - 2 = 3
ʾ�� 3��

���룺nums = [2,10,8]
�����3
?

��ʾ��

n == nums.length
2 <= n <= 105
1 <= nums[i] <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimize-deviation-in-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
