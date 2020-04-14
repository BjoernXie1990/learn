�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����

����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��

?

���ף�

��������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��

?

ʾ����

���룺(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 8 -> 0 -> 7
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        AddStack(st1,l1);
        AddStack(st2,l2);
        int num = 0;//��λ
        ListNode* head = NULL;

        while(!st1.empty() || !st2.empty() || num)
        {
            if(!st1.empty())
            {
                num += st1.top();
                st1.pop();
            }

            if(!st2.empty())
            {
                num += st2.top();
                st2.pop();
            }

            ListNode* ret = new ListNode(num%10);
            ret->next = head;
            head = ret;
            num /= 10;
        }

        return head;
    }

    void AddStack(stack<int>& st, ListNode* list)
    {
        while(list)
        {
            st.push(list->val);
            list = list->next;
        }
    }
};


