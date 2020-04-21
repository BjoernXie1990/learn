//��дһ���������������������Ƿ��ǻ��ĵġ�

//?

//ʾ�� 1��

//���룺 1->2
//����� false 
//ʾ�� 2��

//���룺 1->2->2->1
//����� true 



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
        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        //�ҵ��м�ڵ��λ��
        //�������ڵ㣬��ָ���ͣ�����һ���ڵ�λ�ã�fast->nextΪNULL�˳�
        //ż�����ڵ㣬��ָ���ͣ��NULL��λ�ã�fastΪNULL
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //��תǰ���
        
        ListNode* node = head;
        ListNode* next = head->next;
        head->next = NULL;
        while(next != slow){
            ListNode* nextnode = next->next;
            next->next = node;
            node = next;
            next = nextnode;
        }

        //�ҵ����ε�ͷ
        ListNode* mid;
        if(fast)
            mid = slow->next;
        else
            mid = slow;
        slow = node;
        while(mid){
            if(slow->val != mid->val)
                return false;
            slow = slow->next;
            mid = mid->next;
        }

        return true;
    }
};
