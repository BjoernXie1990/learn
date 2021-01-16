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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = get(headA);
        int m = get(headB);
        while(n != m) {
            if(n < m) headB = headB->next;
            else headA = headA->next;
            if(n < m) m--;
            else n--;
        }
        while(headA && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
    int get(ListNode* head) {
        if(!head) return 0;
        return 1 + get(head->next);
    }
};

�������������ҳ����ǵĵ�һ�������ڵ㡣

���������������



�ڽڵ� c1 ��ʼ�ཻ��

?

ʾ�� 1��



���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
�����Reference of the node with value = 8
������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]������ B Ϊ [5,0,1,8,4,5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
?

ʾ��?2��



���룺intersectVal?= 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
�����Reference of the node with value = 2
������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ [0,9,1,2,4]������ B Ϊ [3,2,4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
?

ʾ��?3��



���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
���ͣ������������ཻ����˷��� null��
?

ע�⣺

�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
��������վ 160 ����ͬ��https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
ͨ������68,417�ύ����108,117

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
