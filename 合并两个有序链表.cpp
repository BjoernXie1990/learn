//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�?

//ʾ����

//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4


class Solution {
public:
    //����д��
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* ret = head;

        while(l1 || l2) {
            if(!l1) {
                ret->next = l2;
                break;
            }
            if(!l2) {
                ret->next = l1;
                break;
            }

            //������������
            if(l1->val <= l2->val) {
                ret->next = l1;
                l1 = l1->next;
                ret = ret->next;
            }
            else {
                ret->next = l2;
                l2 = l2->next;
                ret = ret->next;
            }
        }

        ListNode* headNext = head->next;
        delete head;
        return headNext;
    }

    //�ݹ�д��
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;//l1�ǿ�����ֱ�ӷ���l2
        if(!l2) return l1;//l2�ǿ�����ֱ�ӷ���l1

        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }

        //������������ l1��l2�ĵ�һ��ֵ��
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
};
