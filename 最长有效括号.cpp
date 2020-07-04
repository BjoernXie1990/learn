����һ��ֻ���� '('?�� ')'?���ַ������ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�

ʾ��?1:

����: "(()"
���: 2
����: ���Ч�����Ӵ�Ϊ "()"
ʾ�� 2:

����: ")()())"
���: 4
����: ���Ч�����Ӵ�Ϊ "()()"


class Solution {
public:
    //��̬�滮
    int longestValidParentheses1(string s) {
        int len = s.size();
        stack<int> st;  //���ǰ������ (
        vector<bool> dp(len,false);

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
                continue;
            }

            if(s[i] == ')' && st.empty())
                continue;
            
            int p = st.top();
            st.pop();
            dp[p] = true;
            dp[i] = true;
        }

        int ans = 0;
        int left = 0;
        //Ѱ��������true����
        for(int i = 0; i < len; i++)
        {
            if(dp[i] == false)
            {
                left = i + 1;
                continue;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;
    }

    //ջ
    int longestValidParentheses(string s)
    {
        int len = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
                continue;
            }
            //˵�� s[i] ��ʱ�� )
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans = max(ans,i - st.top());
        }
        return ans;
    }

};
