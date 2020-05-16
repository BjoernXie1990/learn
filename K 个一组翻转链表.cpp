//����һ������ÿ?k?���ڵ�һ����з�ת�����㷵�ط�ת�������

//k?��һ��������������ֵС�ڻ��������ĳ��ȡ�

//����ڵ���������?k?������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

//?

//ʾ����

//�����������1->2->3->4->5

//��?k?= 2 ʱ��Ӧ������: 2->1->4->3->5

//��?k?= 3 ʱ��Ӧ������: 3->2->1->4->5

//?

//˵����

//����㷨ֻ��ʹ�ó����Ķ���ռ䡣
//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 0 || k == 1) return head;

        ListNode* ret = new ListNode;
        ListNode* retNext = ret;
        ret->next = head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(slow)
        {
            int count = k - 1;
            while(count)
            {
                if(fast->next) fast=fast->next;
                else break;
                count--;
            }
            if(count) break;

            Reverse(retNext,slow,fast,k);
            
            retNext = slow;
            slow = slow->next;
            fast = slow;
        }
        head = ret->next;
        delete ret;
        return head;
    }

    void Reverse(ListNode* shead, ListNode* begin,ListNode* end,int k)
    {
        ListNode* endNext = end->next;
        ListNode* cur = begin->next;
        ListNode* b = begin;
        for(int i = 1; i < k; i++)
        {
            ListNode* _next = cur->next;
            cur->next = b;
            b = cur;
            cur = _next;
        }
        shead->next = end;
        begin->next = endNext;
    }
};
