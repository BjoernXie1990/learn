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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode(-1);
        ListNode* cur = ret;

        ListNode* t = head;
        while(t) {
            ListNode* tNext = t->next;
            while(tNext && tNext->val == t->val) tNext = tNext->next;
            t->next = nullptr;
            cur->next = t;
            cur = cur->next;
            t = tNext;
        }
        return ret->next;
    }
};


����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ��?1:

����: 1->1->2
���: 1->2
ʾ��?2:

����: 1->1->2->3->3
���: 1->2->3

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
