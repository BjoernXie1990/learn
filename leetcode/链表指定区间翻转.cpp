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
     * @param head ListNode�� 
     * @param m int���� 
     * @param n int���� 
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* ri = nullptr;
        ListNode* le = nullptr;
        
        for(int i = 1; i <= n + 1; i++) {
            if(i < m) {
                pre = cur;
                cur = cur->next;
            }else if(i == m) {
                ri = cur;
                le = cur;
            }else {
                ListNode* t = cur->next;
                cur->next = le;
                le = cur;
                cur = t;
            }
        }
        ri->next = cur;
        if(pre) pre->next = le;
        else head = le;
        return head;
    }
};

��һ������\ m m λ�õ�\ n n λ��֮������䷴ת��Ҫ��ʱ�临�Ӷ� ���ռ临�Ӷ� ��
���磺
����������Ϊ 1\to 2 \to 3 \to 4 \to 5 \to NULL1��2��3��4��5��NULL, ��,
���� 1\to 4\to 3\to 2\to 5\to NULL1��4��3��2��5��NULL.
ע�⣺
������ ��������������
1 \leq m \leq n \leq ������1��m��n��������
ʾ��1
����
����
{1,2,3,4,5},2,4
����ֵ
����
{1,4,3,2,5}
