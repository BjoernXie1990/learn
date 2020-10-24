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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* pre = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode* mid = slow;\
        if(pre) pre->next = nullptr;
        ListNode* next = slow->next;
        while(next) {
            ListNode* nnext = next->next;
            next->next = slow;
            slow = next;
            next = nnext;
        }

        // check
        ListNode* le = head;
        ListNode* ri = slow;
        while(le) {
            if(le->val != ri->val) return false;
            le = le->next;
            ri = ri->next;
        }

        return true;
    }
};


���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
���ף�
���ܷ���?O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
