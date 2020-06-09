���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У�
���� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У�
�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�

?

ʾ�� 1��

���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
�����true
���ͣ����ǿ��԰�����˳��ִ�У�
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
ʾ�� 2��

���룺pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
�����false
���ͣ�1 ������ 2 ֮ǰ������
?

��ʾ��

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed?��?popped?�����С�


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int lenle = pushed.size();
        int lenri = popped.size();

        stack<int> st;
        int r = 0;
        //��¼��ջ��˳�����poped�� r λ�õ�����һ�����ͳ�ջ
        for(int i = 0; i < lenle; i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[r])
            {
                r++;
                st.pop();
            }
        }

        //��ʱջ�ĳ�ջ˳��һ���Ǻ�poped �� r��ʼ������˳��һ����
        for(int i = r; i < lenri; i++)
        {
            if(st.top() != popped[i])   return false;
            st.pop();
        }
        return true;
    }
};
