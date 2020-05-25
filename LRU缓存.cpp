//�����������յ����ݽṹ����ƺ�ʵ��һ��? LRU (�������ʹ��) ������ơ���Ӧ��֧�����²����� ��ȡ���� get �� д������ put ��

//��ȡ���� get(key) - �����Կ (key) �����ڻ����У����ȡ��Կ��ֵ�����������������򷵻� -1��
//д������ put(key, value) - �����Կ�Ѿ����ڣ�����������ֵ�������Կ�����ڣ��������顸��Կ/����ֵ���������������ﵽ����ʱ����Ӧ����д��������֮ǰɾ�����δʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣

//?

//����:

//���Ƿ������?O(1) ʱ�临�Ӷ�����������ֲ�����

//?

//ʾ��:

//LRUCache cache = new LRUCache( 2 /* �������� */ );

//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // ����  1
//cache.put(3, 3);    // �ò�����ʹ����Կ 2 ����
//cache.get(2);       // ���� -1 (δ�ҵ�)
//cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
//cache.get(1);       // ���� -1 (δ�ҵ�)
//cache.get(3);       // ����  3
//cache.get(4);       // ����  4

struct node
{
    node* _pre;
    node* _next;
    int _key;
    int _value;

    node(int key,int value)
        :_key(key)
        ,_value(value)
        ,_pre(NULL)
        ,_next(NULL)
    {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        head = new node(-1,-1);
        head->_next = head->_pre = head;
    }
    ~LRUCache()
    {
        delete head;
        _capacity = -1;
    }

    //���������Ƴ��ýڵ�
    void RemoveNode(node* cur)
    {
        cur->_next->_pre = cur->_pre;
        cur->_pre->_next = cur->_next;
    }

    //ͷ��
    void PushFront(node* cur)
    {
 
        head->_next->_pre = cur;
        cur->_next = head->_next;

        head->_next = cur;
        cur->_pre = head;
    }

    int get(int key) {
        if(map.find(key) != map.end())
        {
            node* cur = map[key];
            //�Ƴ��ýڵ�
            RemoveNode(cur);
            //�Ѹýڵ�ŵ�ͷ��
            PushFront(cur);
            return cur->_value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //�������key
        if(map.find(key) != map.end())
        {
            node* cur = map[key];
            //�Ƴ�
            RemoveNode(cur);
            //ͷ��
            PushFront(cur);
            cur->_value = value;
            return ;
        }

        //���ﲻ����key,value
        //�ж��ڴ��Ƿ�����
        if(map.size() == _capacity)
        {
            //�Ƴ���βԪ��
            node* tail = head->_pre;
            RemoveNode(tail);
            map.erase(tail->_key);
            delete tail;
        }
        //��ͷ����key
        node* cur = new node(key,value);
        PushFront(cur);
        map[key] = cur;
    }
private:
    int _capacity;
    node* head;
    unordered_map<int,node*> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
