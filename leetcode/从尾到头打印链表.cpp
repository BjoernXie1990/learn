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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(!head) return res;

        ListNode* cur = head;
        ListNode* curNext = head->next;
        cur->next = nullptr;
       

        while(curNext) {
            ListNode* nodeNext = curNext->next;
            curNext->next = cur;
            cur = curNext;
            curNext = nodeNext;
        }

        while(cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};

����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

?

ʾ�� 1��

���룺head = [1,3,2]
�����[2,3,1]
?

���ƣ�

0 <= ������ <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
