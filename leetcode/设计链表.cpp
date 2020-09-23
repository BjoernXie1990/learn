class MyLinkedList {
public:
    struct node {
        int _val;
        node* _next;
        node* _pre;
        node(int val) {
            _val = val;
            _next = nullptr;
            _pre = nullptr;
        }
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new node(-1);
        head->_next = head;
        head->_pre = head;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        node* cur = head;
        for(int i = 0; i < index; i++)
            cur = cur->_next;
        return cur->_next->_val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* cur = new node(val);
        node* headnext = head->_next;
        head->_next = cur;
        cur->_pre = head;
        cur->_next = headnext;
        headnext->_pre = cur;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* cur = new node(val);
        node* headpre = head->_pre;
        head->_pre = cur;
        cur->_next = head;

        headpre->_next = cur;
        cur->_pre = headpre;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return ;
        if(index <= 0) {
            addAtHead(val);
            return ;
        }

        // �м����
        node* curpre = head;
        for(int i = 0; i < index; i++) curpre = curpre->_next;
        node* curnext = curpre->_next;
        node* cur = new node(val);

        curpre->_next = cur;
        cur->_pre = curpre;
        cur->_next = curnext;
        curnext->_pre = cur;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return ;
        node* curpre = head;
        for(int i = 0; i < index; i++) curpre = curpre->_next;
        node* del = curpre->_next;
        node* delnext = del->_next;

        curpre->_next = delnext;
        delnext->_pre = curpre;

        delete del;
        size--;
    }
private:
    node* head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 
 
 ��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val?��?next��val?�ǵ�ǰ�ڵ��ֵ��next?��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������?prev?��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�

get(index)����ȡ�����е�?index?���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ?val?�Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ?val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ�?index?���ڵ�֮ǰ���ֵΪ?val? �Ľڵ㡣���?index?��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
deleteAtIndex(index)���������?index ��Ч����ɾ�������еĵ�?index ���ڵ㡣
?

ʾ����

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
linkedList.get(1);            //����2
linkedList.deleteAtIndex(1);  //����������1-> 3
linkedList.get(1);            //����3
?

��ʾ��

����valֵ����?[1, 1000]?֮�ڡ�
������������??[1, 1000]?֮�ڡ�
�벻Ҫʹ�����õ� LinkedList �⡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
