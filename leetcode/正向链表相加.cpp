/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head1 ListNode�� 
     * @param head2 ListNode�� 
     * @return ListNode��
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        ListNode* le = Reverse(head1);
        ListNode* ri = Reverse(head2);
        
        int num = 0;
        ListNode* head = new ListNode(-1);
        head->next = NULL;
        ListNode* cur = head;
        
        while(le || ri || num) {
            if(le) {
                num += le->val;
                le = le->next;
            }
            if(ri) {
                num += ri->val;
                ri = ri->next;
            }
            ListNode* t = new ListNode(num % 10);
            num /= 10;
            cur->next = t;
            cur = cur->next;
            
        }
        
        ListNode* ret = head->next;
        head->next = NULL;
        return Reverse(ret);
    }
    
private:
    ListNode* Reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ret = Reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};

����������ÿһ���ڵ��ֵ���� 0 - 9 ֮�䣬��ô��������Ϳ��Դ���һ��������
���������������������ɴ��������������ֵ�Ľ������
���磺���� 1 Ϊ 9->3->7������ 2 Ϊ 6->3����������µĽ������Ϊ 1->0->0->0��
ʾ��1
����
����
[9,3,7],[6,3]
����ֵ
����
{1,0,0,0}
��ע:
1 \leq n, m \leq 10^61��n,m��10 
6
 
0 \leq a_i, b_i \leq 90��a 
i
?	
 ,b 
i
?	
 ��9
