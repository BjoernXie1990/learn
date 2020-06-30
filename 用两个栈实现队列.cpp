������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ���ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead?�������� -1 )

?

ʾ�� 1��

���룺
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
�����[null,null,3,-1]
ʾ�� 2��

���룺
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
�����[null,-1,null,null,5,2]


class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        push_st.push(value);
    }
    
    int deleteHead() {
        int ans = 0;
        if(!pop_st.empty())
        {
            ans = pop_st.top();
            pop_st.pop();
        }
        else
        {
            if(push_st.empty()) return -1;
            while(push_st.size() != 1)
            {
                int t = push_st.top();
                pop_st.push(t);
                push_st.pop();
            }
            ans = push_st.top();
            push_st.pop();
        }
        return ans;
    }
private:
    stack<int> push_st;
    stack<int> pop_st;
};

