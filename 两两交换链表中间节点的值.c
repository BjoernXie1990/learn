//����һ���������������������ڵĽڵ㣬�����ؽ����������

//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

// 

//ʾ��:

//���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* swapPairs(struct ListNode* head){
    ListNode* two = head;
    ListNode* three = head;
    //����һ���µ�ͷ���
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    newhead->next = head;
    ListNode* one = newhead;
    
    while(two)
    {
        three = two->next;
        if(three)
        {
            //����
            two->next = three->next;
            one->next = three;
            three->next = two;

            //one->three->two
            one = two;
            
        }
        two = two->next;
    }
    head = newhead->next;
    free(newhead);
    return head;
}
