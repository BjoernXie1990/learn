class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        stack<int> st({1});

        for(int i = 0; i < n; i++) {
            if(st.empty()) 
                return false;
            if(preorder[i] == ',')
                continue;
            
            if(preorder[i] == '#') {
                st.top() -= 1;
                if(st.top() == 0)
                    st.pop();
            } else {
                while(i < n && preorder[i] != ',')
                    i ++;
                st.top() -= 1;
                if(st.top() == 0)
                    st.pop();
                st.push(2);
            }
        }

        return st.empty();
    }
};


���л���������һ�ַ�����ʹ��ǰ�����������������һ���ǿսڵ�ʱ�����ǿ��Լ�¼������ڵ��ֵ���������һ���սڵ㣬���ǿ���ʹ��һ�����ֵ��¼������ #��

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
���磬����Ķ��������Ա����л�Ϊ�ַ��� "9,3,4,#,#,1,#,#,2,#,6,#,#"������ # ����һ���սڵ㡣

����һ���Զ��ŷָ������У���֤���Ƿ�����ȷ�Ķ�������ǰ�����л�����дһ���ڲ��ع����������µĿ����㷨��

ÿ���Զ��ŷָ����ַ���Ϊһ��������Ϊһ����ʾ null ָ��� '#' ��

�������Ϊ�����ʽ������Ч�ģ���������Զ����������������Ķ��ţ�����?"1,,3" ��

ʾ�� 1:

����: "9,3,4,#,#,1,#,#,2,#,6,#,#"
���: true
ʾ��?2:

����: "1,#"
���: false
ʾ�� 3:

����: "9,#,#,1"
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
