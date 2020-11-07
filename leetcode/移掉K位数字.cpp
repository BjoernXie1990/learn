class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();       // ��ʱβ��һ���ǱȽϴ������
            k--;
        }
        string ans("");
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // ȥ��β����0
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();      // �൱���������ǰ��0
        reverse(ans.begin(),ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};


����һ�����ַ�����ʾ�ķǸ�����?num���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С��

ע��:

num �ĳ���С�� 10002 ��?�� k��
num ��������κ�ǰ���㡣
ʾ�� 1 :

����: num = "1432219", k = 3
���: "1219"
����: �Ƴ����������� 4, 3, �� 2 �γ�һ���µ���С������ 1219��
ʾ�� 2 :

����: num = "10200", k = 1
���: "200"
����: �Ƶ���λ�� 1 ʣ�µ�����Ϊ 200. ע������������κ�ǰ���㡣
ʾ�� 3 :

����: num = "10", k = 2
���: "0"
����: ��ԭ�����Ƴ����е����֣�ʣ��Ϊ�վ���0��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-k-digits
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
