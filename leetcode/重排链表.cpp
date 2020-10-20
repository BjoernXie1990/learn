/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return ;

        // �ҵ��е�
        ListNode* slow = head;
        ListNode* pre = nullptr;
        ListNode* fast = head;
        while ( fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow Ϊ mid ��
        // ��ת slow ��
        pre->next = nullptr;
        ListNode* mid = slow;
        ListNode* sNext = slow->next;
        slow->next = nullptr;
        while(sNext != nullptr) {
            ListNode* tmp = sNext->next;
            sNext->next = slow;
            slow = sNext;
            sNext = tmp;
        }

        // ListNode* t = head;
        // while(t != mid) {
        //     cout << t->val << " ";
        //     t = t->next;
        // }
        // cout << endl;

        // t = slow;
        // while(t) {
        //     cout << t->val << " ";
        //     t = t->next;
        // }

        // ����
        pre = nullptr;
        ListNode* le = head;
        ListNode* ri = slow;
        while ( (le != nullptr) && (ri != nullptr)) {
            pre = le;
            ListNode* riNext = ri->next;
            ListNode* leNext = le->next;
            
            le->next = ri;
            ri->next = leNext;
            le = leNext;
            ri = riNext;
        }
        if(ri) pre->next->next = ri;
    }
};


����һ��������?L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ��?1:

�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
ʾ�� 2:

�������� 1->2->3->4->5, ��������Ϊ 1->5->2->4->3.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reorder-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
