����һ������ɾ������ĵ�����?n?���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n?��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����




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
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* le = head;
        ListNode* ri = head;
        for(int i = 0; i < n; i++)
            ri = ri->next;
        if(!ri)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        while(ri->next)
        {
            ri = ri->next;
            le = le->next;
        }
        
        ListNode* del = le->next;
        le->next = del->next;
        delete del;
        return head;
    }

    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head) return NULL;
        head->next = removeNthFromEnd(head->next,n);
        cur++;
        if(n == cur)    return head->next;
        return head;
    }
};
