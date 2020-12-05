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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int n = 1;
        while(tail->next) {
            n++;
            tail = tail->next;
        }
        k %= n;
        if(k == 0) return head;

        tail->next = head;
        ListNode* pre = head;
        for(int i = 0; i < n - k - 1; i++) pre = pre->next;

        ListNode* ret = pre->next;
        pre->next = nullptr;
        return ret;
    }
};

����һ��������ת����������ÿ���ڵ������ƶ�?k?��λ�ã�����?k?�ǷǸ�����

ʾ��?1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ��?2:

����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��:?0->1->2->NULL
������ת 4 ��:?2->0->1->NULL

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotate-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
