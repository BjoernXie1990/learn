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
    ListNode* swapPairs1(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* ret = new ListNode(-1);
        ret->next = head;
        ListNode* pre = ret;
        ListNode* cur = head;
        ListNode* curNext = cur->next;

        while(curNext != nullptr) {
            ListNode* next = curNext->next;

            pre->next = curNext;
            curNext->next = cur;

            pre = cur;
            pre->next = nullptr;
            cur = next;
            if(cur == nullptr) break;
            curNext = cur->next;
        }

        if(cur != nullptr) pre->next = cur,cur->next = nullptr;
        
        ListNode* ans = ret->next;
        delete ret;

        return ans;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};


����һ���������������������ڵĽڵ㣬�����ؽ����������

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

?

ʾ��:

���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/swap-nodes-in-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
