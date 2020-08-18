����һ��������������л�����ʵ��һ���㷨���ػ�·�Ŀ�ͷ�ڵ㡣
�л�����Ķ��壺��������ĳ���ڵ��nextԪ��ָ������ǰ����ֹ��Ľڵ㣬�������������ڻ�·��

?

ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�����tail connects to node index 1
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
?

ʾ�� 2��

���룺head = [1,2], pos = 0
�����tail connects to node index 0
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
?

ʾ�� 3��

���룺head = [1], pos = -1
�����no cycle
���ͣ�������û�л���
?

���ף�
���Ƿ���Բ��ö���ռ������⣿

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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)    break;
        }
        //������û�л�
        if(fast == nullptr || fast->next == nullptr)    return nullptr;

        ListNode* cur = head;
        while(cur != slow)
        {
            cur = cur->next;
            slow = slow->next;
        }

        return slow;
    }
};
