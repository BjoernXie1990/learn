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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->_head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = _head->val;
        ListNode* cur = _head->next;
        int sum = 2;
        
        while (cur != nullptr) {
            if(rand() % sum == 0) {
                ans = cur->val;
            }
            sum++;
            cur = cur->next;
        }

        return ans;
    }
    private:
        ListNode* _head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
 
 ����һ�����������ѡ�������һ���ڵ㣬��������Ӧ�Ľڵ�ֵ����֤ÿ���ڵ㱻ѡ�ĸ���һ����

����:
�������ʮ�ִ��ҳ���δ֪����ν��������⣿���ܷ�ʹ�ó������ռ临�Ӷ�ʵ�֣�

ʾ��:

// ��ʼ��һ�������� [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom()����Ӧ�������1,2,3�е�һ������֤ÿ��Ԫ�ر����صĸ�����ȡ�
solution.getRandom();

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-random-node
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
