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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;

        ListNode* cur = head;
        ListNode* pre = head;
        while(cur != nullptr) {
            if(cur->val < x) {
                int preNum = pre->val;
                int curNum = cur->val;
                pre->val = curNum;
                cur->val = preNum;
                pre = pre->next;
            }
            cur = cur->next;
        }

        return head;
    }
};

��д������ x Ϊ��׼�ָ�����ʹ������С�� x �Ľڵ����ڴ��ڻ���� x �Ľڵ�֮ǰ����������а��� x��x ֻ�������С�� x ��Ԫ��֮��(������ʾ)���ָ�Ԫ�� x ֻ�账�ڡ��Ұ벿�֡����ɣ��䲻��Ҫ����������������֮�䡣

ʾ��:

����: head = 3->5->8->5->10->2->1, x = 5
���: 3->1->2->10->5->5->8

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-list-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
