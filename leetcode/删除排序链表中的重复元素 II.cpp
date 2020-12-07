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
            if(!tNext || (tNext && tNext->val != t->val)) {
                t->next = nullptr;
                cur->next = t;
                cur = cur->next;
            }
            while(tNext && tNext->val == t->val) tNext = tNext->next;
            t = tNext;
        }
        return ret->next;
    }
};

����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������?û���ظ�����?�����֡�

ʾ��?1:

����: 1->2->3->3->4->4->5
���: 1->2->5
ʾ��?2:

����: 1->1->1->2->3
���: 2->3

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
