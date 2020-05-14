//��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* headNode = head;
        while(headNode)
        {
            Node* next  = headNode->next;
            Node* node = new Node(headNode->val);
            node->next = next;
            headNode->next = node;
            headNode = next;
        }

        headNode = head;
        while(headNode)
        {
            if(headNode->random != NULL)
                headNode->next->random = headNode->random->next;
            headNode = headNode->next->next;
        }

        Node* ret = new Node(0);
        Node* retHead = ret;
        headNode = head;
        while(headNode)
        {
            Node* copy = headNode->next;
            Node* headnext = copy->next;

            ret->next = copy;
            ret = copy;

            headNode->next=headnext;//����ԭ��������
            headNode = headnext;
        }

        ret = retHead->next;
        delete retHead;
        return ret;
    }
};
