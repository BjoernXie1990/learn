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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* ri = sortList(mid);
        ListNode* le = sortList(head);
        
        // merge
        ListNode* newhead = new ListNode(-1);
        ListNode* cur = newhead;
        
        while(le || ri) {
            
            if(!le) {
                cur->next = ri;
                ri = nullptr;
            } else if(!ri) {
                cur->next = le;
                le = nullptr;
            } else {
                if(le->val <= ri->val) {
                    cur->next = le;
                    le = le->next;
                } else {
                    cur->next = ri;
                    ri = ri->next;
                }

                cur = cur->next;
                cur->next = nullptr;
            }
        }

        return newhead->next;
    }
};


���������ͷ���?head?���뽫�䰴 ���� ���в����� ���������� ��

���ף�

�������?O(n?log?n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������
?

ʾ�� 1��


���룺head = [4,2,1,3]
�����[1,2,3,4]
ʾ�� 2��


���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]
ʾ�� 3��

���룺head = []
�����[]
?

��ʾ��

�����нڵ����Ŀ�ڷ�Χ?[0, 5 * 104]?��
-105?<= Node.val <= 105

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sort-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
