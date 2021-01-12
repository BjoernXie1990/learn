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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        
        ListNode* le = head;
        int cnt = k;
        while(-- cnt) {
            le = le->next;
        }
        
        cnt = len - k + 1;
        ListNode* ri = head;
        while(-- cnt) {
            ri = ri->next;
        }
        
        swap(le->val,ri->val);
        return head;
    }
};


���������ͷ�ڵ� head ��һ������ k ��

���� ���������� k ���ڵ�͵����� k ���ڵ��ֵ�󣬷��������ͷ�ڵ㣨���� �� 1 ��ʼ��������

 

ʾ�� 1��


���룺head = [1,2,3,4,5], k = 2
�����[1,4,3,2,5]
ʾ�� 2��

���룺head = [7,9,6,6,7,8,3,0,9,5], k = 5
�����[7,9,6,6,8,7,3,0,9,5]
ʾ�� 3��

���룺head = [1], k = 1
�����[1]
ʾ�� 4��

���룺head = [1,2], k = 1
�����[2,1]
ʾ�� 5��

���룺head = [1,2,3], k = 2
�����[1,2,3]
 

��ʾ��

�����нڵ����Ŀ�� n
1 <= k <= n <= 105
0 <= Node.val <= 100
